#include <iostream>
#include "body.hpp"

int main() {
    Vec3 pos = {1.0, 2.0, 3.0};
    Vec3 vel = {0.1, 0.2, 0.3};
    double mass = 5.0;
    Body body(pos, vel, mass);

    std::cout << "Body created:\n";
    std::cout << "  Position: (" << body.position[0] << ", " << body.position[1] << ", " << body.position[2] << ")\n";
    std::cout << "  Velocity: (" << body.velocity[0] << ", " << body.velocity[1] << ", " << body.velocity[2] << ")\n";
    std::cout << "  Mass: " << body.mass << '\n';
    return 0;
}