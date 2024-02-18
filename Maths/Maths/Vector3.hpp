#pragma once
#include <math.h>
// DONE YESTERDAY:
// Right-Click on Solution >> Add New Project >> C++ Static Library >> "Maths"
// Right-Click on Solution >> Add New Project >> GoogleTest (Target: Maths) >> "Maths.Test"
// Right-Click on Maths >> Add New Class >> "Vector3"
// Right-Click on test.cpp >> Rename to "Vector3Test.cpp"
// Find the Code for Vector3Test.cpp and for Vector.h on Discord

// TODO NOW:
// Goal: Write a Unit Test to test one Vector Class Feature
//        e.g. Vector3(1, 2, 3) + Vector3(4, 5, 6) = Vector3(5, 7, 9)
// Then: Implement the Vector Class Feature
//        e.g. return Vector3(x + other.x, ...
// Do this for Vector3(float, float, float), ==, !=, -V3, V3*float, V3/float, V3+V3, V3-V3,
//    float Vector3::magnitude()
//          returns length of vector e.g. 10
//    Vector3 Vector3::normalize()
//          return a vector with length 1

// if you do vector * k, then the magnitude m becomes m*k
// if you do vector / k, then the magnitude m becomes m/k
// if you do vector /m, then the magnitude m becomes m/m = 1


class Vector3
{
public:
    float x, y, z;
    inline Vector3() : x{}, y{}, z{} {}
    inline Vector3(float x, float y, float z)
        : x{ x }, y{ y }, z{ z } {
    }

    //                 v this function does not change OTHER
    inline bool operator==(const Vector3& other) const { // <- this function does not change THIS
        return x == other.x && y == other.y && z == other.z;
    }

    inline bool operator!=(const Vector3& other) const { // <- this function does not change THIS
        return !(*this == other);
    }

    // TODO:
    inline Vector3 operator-() const {
        return Vector3(-x, -y, -z);
    }

    inline Vector3 operator*(float k) const {
        return Vector3(x*k, y*k, z*k);
    }

    inline Vector3 operator/(float k) const {
        return Vector3(x / k, y / k, z / k);
    }

    inline Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y  + other.y, z + other.z);
    }
    
    inline Vector3& operator+=(const Vector3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
    
    inline Vector3& operator-=(const Vector3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    inline Vector3 operator-(const Vector3& other) const {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    inline float Magnitude() const {
        return sqrtf(x * x + y * y + z * z);
    }
    
    inline Vector3 Normalized() const {
        return (*this)/Magnitude();
    }
};

inline Vector3 operator*(float k, const Vector3& v) {
    return Vector3(v.x*k, v.y*k, v.z*k);
}
