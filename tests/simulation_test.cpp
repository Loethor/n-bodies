#include <gtest/gtest.h>
#include "simulation.hpp"
#include <cmath>

TEST(SimulationTest, ComputeAccelerationsForTwoBodies) {
    Simulation simulation;
    simulation.dt = 1.0;
    
    // Two bodies with known masses and positions
    Body body1("Body1", {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 1.0e24, 1.0);
    Body body2("Body2", {1.0e6, 0.0, 0.0}, {0.0, 0.0, 0.0}, 1.0e24, 1.0);
    
    simulation.bodies.push_back(body1);
    simulation.bodies.push_back(body2);
    
    std::vector<Vec3> accelerations = simulation.computeAccelerations();
    
    ASSERT_EQ(accelerations.size(), 2);
    
    // G = 6.67430e-11, m2 = 1e24, r = 1e6
    // a = G * m / r^2 = 6.67430e-11 * 1e24 / (1e6)^2 = 6.6743e-5
    double expected_acc = 6.67430e-11 * 1.0e24 / (1.0e6 * 1.0e6);
    
    // Body1 should accelerate toward Body2 (positive x direction)
    EXPECT_NEAR(accelerations[0][0], expected_acc, 1e-10);
    EXPECT_NEAR(accelerations[0][1], 0.0, 1e-10);
    EXPECT_NEAR(accelerations[0][2], 0.0, 1e-10);
    
    // Body2 should accelerate toward Body1 (negative x direction)
    EXPECT_NEAR(accelerations[1][0], -expected_acc, 1e-10);
    EXPECT_NEAR(accelerations[1][1], 0.0, 1e-10);
    EXPECT_NEAR(accelerations[1][2], 0.0, 1e-10);
}

TEST(SimulationTest, ComputeAccelerationsForSingleBody) {
    Simulation simulation;
    simulation.dt = 1.0;
    
    Body body("Body", {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 1.0e24, 1.0);
    simulation.bodies.push_back(body);
    
    std::vector<Vec3> accelerations = simulation.computeAccelerations();
    
    ASSERT_EQ(accelerations.size(), 1);
    
    // Single body should have zero acceleration
    EXPECT_DOUBLE_EQ(accelerations[0][0], 0.0);
    EXPECT_DOUBLE_EQ(accelerations[0][1], 0.0);
    EXPECT_DOUBLE_EQ(accelerations[0][2], 0.0);
}

TEST(SimulationTest, ComputeAccelerationsSymmetric) {
    Simulation simulation;
    simulation.dt = 1.0;
    
    // Two bodies equidistant from origin
    Body body1("Body1", {1.0e6, 0.0, 0.0}, {0.0, 0.0, 0.0}, 2.0e24, 1.0);
    Body body2("Body2", {-1.0e6, 0.0, 0.0}, {0.0, 0.0, 0.0}, 2.0e24, 1.0);
    
    simulation.bodies.push_back(body1);
    simulation.bodies.push_back(body2);
    
    std::vector<Vec3> accelerations = simulation.computeAccelerations();
    
    // Accelerations should be equal in magnitude but opposite in direction
    EXPECT_NEAR(accelerations[0][0], -accelerations[1][0], 1e-10);
    EXPECT_NEAR(accelerations[0][1], -accelerations[1][1], 1e-10);
    EXPECT_NEAR(accelerations[0][2], -accelerations[1][2], 1e-10);
}
