#ifndef HEADER_VECTOR3_HPP
#define HEADER_VECTOR3_HPP

#include <cmath>
#include <iostream>

using namespace std;

class Vector3 {
    public:
        Vector3() : x(0.0), y(0.0), z(0.0) {}
        Vector3(float xx) : x(xx), y(xx), z(xx) {}
        Vector3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}

        Vector3 operator - () const { return Vector3(-x, -y, -z); }
        Vector3 operator + (const float &f) const { return Vector3(x + f, y + f, z + f); }
        Vector3 operator - (const float &f) const { return Vector3(x - f, y - f, z - f); }
        Vector3 operator * (const float &f) const { return Vector3(x * f, y * f, z * f); }
        Vector3 operator / (const float &f) const { return Vector3(x / f, y / f, z / f); }
        Vector3 operator + (const Vector3 &v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
        Vector3 operator - (const Vector3 &v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
        Vector3 operator * (const Vector3 &v)  const { return Vector3(x * v.x, y * v.y, z * v.z); }
        Vector3& operator += (const Vector3 &v) { x += v.x, y += v.y, z += v.z; return *this; }
        Vector3& operator *= (const Vector3 &v) { x *= v.x, y *= v.y, z *= v.z; return *this; }

        float dot(const Vector3 &v) const { return x * v.x + y * v.y + z * v.z; }
        Vector3 cross(const Vector3 &v) const { return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
        float length2() const { return x * x + y * y + z * z; }
        float length() const { return sqrt(length2()); }

        Vector3& normalize();

        Vector3& rotateX(const float &angle);
        Vector3& rotateY(const float &angle);
        Vector3& rotateZ(const float &angle);

        friend ostream & operator << (ostream &os, const Vector3 &v);

        static Vector3 random();

    public:
        float x;
        float y;
        float z;
};

#endif // HEADER_VECTOR3_HPP