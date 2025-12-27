#include "body.hpp"
#include <iostream>
#include <iomanip>

void Body::print() const {
    std::cout << name << ":\n";
    std::cout << "  Position: (" << position[0] << ", " << position[1] << ", " << position[2] << ")\n";
    std::cout << "  Velocity: (" << velocity[0] << ", " << velocity[1] << ", " << velocity[2] << ")\n";
}

