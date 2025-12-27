#pragma once

#include <array>
#include <cmath>

using Vec3 = std::array<double, 3>;

inline Vec3 operator+(const Vec3& a, const Vec3& b) {
    return {a[0] + b[0], a[1] + b[1], a[2] + b[2]};
}

inline Vec3 operator-(const Vec3& a, const Vec3& b) {
    return {a[0] - b[0], a[1] - b[1], a[2] - b[2]};
}

inline Vec3 operator*(const Vec3& v, double s) {
    return {v[0] * s, v[1] * s, v[2] * s};
}

inline Vec3 operator*(double s, const Vec3& v) {
    return v * s;
}

inline double dot(const Vec3& a, const Vec3& b) {
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

inline double norm(const Vec3& v) {
    return std::sqrt(dot(v, v));
}

inline Vec3 normalize(const Vec3& v) {
    double n = norm(v);
    return n > 0 ? v * (1.0 / n) : Vec3{0, 0, 0};
}
