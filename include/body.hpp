#pragma once

#include "vector_math.hpp"
#include <string>

class Body {
public:
    Body(const std::string& name, const Vec3& position, const Vec3& velocity, double mass, double radius)
        : name(name), position(position), velocity(velocity), mass(mass), radius(radius) {}

    void printState() const;

    std::string name;
    Vec3 position;
    Vec3 velocity;
    double mass;
    double radius;
};
