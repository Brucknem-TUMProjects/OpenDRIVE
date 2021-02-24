//
// Created by brucknem on 22.02.21.
//

#include "Vector.hpp"

namespace opendrive {

    Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector operator+(const Vector &lhs, const Vector &rhs) {
        return {
                lhs.x + rhs.x,
                lhs.y + rhs.y,
                lhs.z + rhs.z
        };
    }

    Vector operator-(const Vector &lhs, const Vector &rhs) {
        return {
                lhs.x - rhs.x,
                lhs.y - rhs.y,
                lhs.z - rhs.z
        };
    }

    Vector &Vector::operator+=(const Vector &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    Vector Vector::rotateXY(double angle) const {
        auto sin = std::sin(angle);
        auto cos = std::cos(angle);
        return {
                x * cos - y * sin,
                x * sin + y * cos
        };
    }

    double Vector::distance(const Vector &rhs) const {
        return (*this - rhs).length();
    }

    std::ostream &operator<<(std::ostream &os, const Vector &other) {
        os << other.x << "," << other.y << "," << other.z;
        return os;
    }

    Vector &Vector::normalize() {
        double l = length();
        x /= l;
        y /= l;
        z /= l;
        return *this;
    }

    Vector Vector::cross(const Vector &other) const {
        return {
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x
        };
    }

    double Vector::dot(const Vector &other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    double Vector::length() const {
        return std::sqrt(dot(*this));
    }
}