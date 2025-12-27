#include <iostream>
#include "body.hpp"
#include "simulation.hpp"
#include "euler_integrator.hpp"
#include "config_loader.hpp"

int main() {
    // Load bodies from config file
    std::vector<Body> bodies = ConfigLoader::loadBodies("data/earth_moon.txt");
    
    // Create a simulation
    Simulation sim;
    sim.dt = 3600.0; // 1 hour time step
    sim.bodies = bodies;

    // Create integrator and integrate
    EulerIntegrator integrator;
    
    std::cout << "Initial state:\n";
    for (const auto& body : sim.bodies) {
        body.print();
    }
    
    integrator.integrate(sim);
    
    std::cout << "\nAfter integration:\n";
    for (const auto& body : sim.bodies) {
        body.print();
    }
    
    return 0;
}