#include <cmath>
#include <iostream>

class Vec3 {

    float x, y, z;

    Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

        // Parameterized constructor
    Vec3(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

        // Vector addition
    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    // Vector subtraction
    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    // Scalar multiplication
    Vec3 operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    // Scalar division
    Vec3 operator/(float scalar) const {
        if (scalar == 0) throw std::runtime_error("Division by zero!");
        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    // Dot product
    float dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Cross product
    Vec3 cross(const Vec3& other) const {
        return Vec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Magnitude of the vector
    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Normalization
    Vec3 normalize() const {
        float mag = magnitude();
        if (mag == 0) throw std::runtime_error("Cannot normalize a zero-length vector!");
        return *this / mag;
    }

    // Print the vector (for debugging)
    void print() const {
        std::cout << "Vec3(" << x << ", " << y << ", " << z << ")" << std::endl;
    }




};