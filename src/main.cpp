#include <iostream>
#include <filesystem>
#include <string>
#include "body.hpp"
#include "simulation.hpp"
#include "euler_integrator.hpp"
#include "config_loader.hpp"
#include "output.hpp"

int main() {
    // Config file path
    std::string config_path = "data/earth_moon.txt";
    // Extract base name for output
    std::filesystem::path config_file(config_path);
    std::string base_name = config_file.stem().string();
    std::string output_dir = "output";
    std::filesystem::create_directories(output_dir);
    std::string output_path = output_dir + "/" + base_name + ".csv";

    // Load bodies from config file
    std::vector<Body> bodies = ConfigLoader::loadBodies(config_path);
    
    // Create a simulation
    Simulation simulation;
    simulation.dt = 3600.0; // 1 hour time step
    simulation.bodies = bodies;

    // Create integrator
    EulerIntegrator integrator;

    // Create output
    Output output(output_path);
    output.writeHeader();

    // Initial state output
    double time = 0.0;
    output.writeStep(time, simulation.bodies);

    // Run simulation for 655 steps
    for (int step = 0; step < 655; ++step) {
        integrator.step(simulation);
        time += simulation.dt;
        output.writeStep(time, simulation.bodies);
    }

    std::cout << "Simulation complete. Output written to " << output_path << "\n";
    return 0;
}