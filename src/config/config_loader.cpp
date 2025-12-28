#include "config_loader.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

std::vector<Body> ConfigLoader::loadBodies(const std::string& filename) {
    std::vector<Body> bodies;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        // Skip empty lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }
        
        std::istringstream iss(line);
        std::string name;
        double mass, x, y, z, vx, vy, vz, radius;
        if (iss >> name >> mass >> x >> y >> z >> vx >> vy >> vz >> radius) {
            Vec3 position = {x, y, z};
            Vec3 velocity = {vx, vy, vz};
            bodies.emplace_back(name, position, velocity, mass, radius);
        }
    }
    
    file.close();
    return bodies;
}
