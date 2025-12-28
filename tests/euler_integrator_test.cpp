#include <gtest/gtest.h>
#include "euler_integrator.hpp"
#include "simulation.hpp"

TEST(EulerIntegratorTest, IntegrateUpdatesVelocity) {
    Simulation simulation;
    simulation.dt = 1.0;
    
    Body body("Body", {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 1.0e24, 1.0);
    Body attractor("Attractor", {1.0e6, 0.0, 0.0}, {0.0, 0.0, 0.0}, 1.0e30, 1.0);
    
    simulation.bodies.push_back(body);
    simulation.bodies.push_back(attractor);
    
    Vec3 initial_velocity = simulation.bodies[0].velocity;
    
    EulerIntegrator integrator;
    integrator.step(simulation);
    
    // Velocity should have changed due to gravitational acceleration
    EXPECT_NE(simulation.bodies[0].velocity[0], initial_velocity[0]);
}

TEST(EulerIntegratorTest, IntegrateUpdatesPosition) {
    Simulation simulation;
    simulation.dt = 1.0;
    
    Body body("Body", {0.0, 0.0, 0.0}, {100.0, 0.0, 0.0}, 1.0e24, 1.0);
    simulation.bodies.push_back(body);
    
    Vec3 initial_position = simulation.bodies[0].position;
    
    EulerIntegrator integrator;
    integrator.step(simulation);
    
    // Position should have changed due to velocity
    EXPECT_NE(simulation.bodies[0].position[0], initial_position[0]);
}

TEST(EulerIntegratorTest, IntegrateWithZeroVelocityAndAcceleration) {
    Simulation simulation;
    simulation.dt = 1.0;
    
    Body body("Body", {100.0, 200.0, 300.0}, {0.0, 0.0, 0.0}, 1.0e24, 1.0);
    simulation.bodies.push_back(body);
    
    Vec3 initial_position = simulation.bodies[0].position;
    Vec3 initial_velocity = simulation.bodies[0].velocity;
    
    EulerIntegrator integrator;
    integrator.step(simulation);
    
    // Position and velocity should remain unchanged (no forces, no initial velocity)
    EXPECT_DOUBLE_EQ(simulation.bodies[0].position[0], initial_position[0]);
    EXPECT_DOUBLE_EQ(simulation.bodies[0].position[1], initial_position[1]);
    EXPECT_DOUBLE_EQ(simulation.bodies[0].position[2], initial_position[2]);
    EXPECT_DOUBLE_EQ(simulation.bodies[0].velocity[0], initial_velocity[0]);
    EXPECT_DOUBLE_EQ(simulation.bodies[0].velocity[1], initial_velocity[1]);
    EXPECT_DOUBLE_EQ(simulation.bodies[0].velocity[2], initial_velocity[2]);
}

TEST(EulerIntegratorTest, IntegrateWithConstantVelocity) {
    Simulation simulation;
    simulation.dt = 2.0;
    
    Body body("Body", {0.0, 0.0, 0.0}, {50.0, 25.0, 10.0}, 1.0e24, 1.0);
    simulation.bodies.push_back(body);
    
    EulerIntegrator integrator;
    integrator.step(simulation);
    
    // With no forces, position should update by velocity * dt
    EXPECT_DOUBLE_EQ(simulation.bodies[0].position[0], 100.0);  // 50 * 2
    EXPECT_DOUBLE_EQ(simulation.bodies[0].position[1], 50.0);   // 25 * 2
    EXPECT_DOUBLE_EQ(simulation.bodies[0].position[2], 20.0);   // 10 * 2
}
