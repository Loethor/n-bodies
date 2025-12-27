#pragma once

#include "math_utils.hpp"

class Body {
public:
	Body(const Vec3& position, const Vec3& velocity, double mass)
		: position(position), velocity(velocity), mass(mass) {}

	Vec3 position;
	Vec3 velocity;
	double mass;
};
