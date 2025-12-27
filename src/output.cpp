#include "output.hpp"
#include <stdexcept>

Output::Output(const std::string& filename) : filename(filename), file(filename) {
    if (!file.is_open()) {
        throw std::runtime_error("Could not open output file: " + filename);
    }
}

Output::~Output() {
    if (file.is_open()) file.close();
}

void Output::writeHeader() {
    file << "time,body_name,x,y,z,vx,vy,vz\n";
}

void Output::writeStep(double time, const std::vector<Body>& bodies) {
    for (const auto& body : bodies) {
        file << time << "," << body.name << ","
             << body.position[0] << "," << body.position[1] << "," << body.position[2] << ","
             << body.velocity[0] << "," << body.velocity[1] << "," << body.velocity[2] << "\n";
    }
}
