#include <Core/Vector.hpp>

Vector3& Vector3::normalize() {
    float norm2 = length2();

    if(norm2 > 0) {
        float invNorm = 1 / sqrt(norm2);

        x *= invNorm;
        y *= invNorm;
        z *= invNorm;
    }

    return *this;
}

Vector3& Vector3::rotateX(const float& angle) {
    float _y = y;
    float _z = z;

    y = _y * cos(angle) - _z * sin(angle);
    z = _y * sin(angle) + _z * cos(angle);

    return *this;
}

Vector3& Vector3::rotateY(const float& angle) {
    float _x = x;
    float _z = z;

    x = _z * sin(angle) + _x * cos(angle);
    z = _z * cos(angle) - _x * sin(angle);

    return *this;
}

Vector3& Vector3::rotateZ(const float& angle) {
    float _x = x;

    x = _x * cos(angle) - y * sin(angle);
    y = _x * sin(angle) + y * cos(angle);

    return *this;
}

ostream& operator << (ostream& os, const Vector3& v) {
    os << "[" << v.x << " " << v.y << " " << v.z << "]";
    return os;
}

Vector3 Vector3::random() {
    float rx = ((float) rand() / (RAND_MAX));
    float ry = ((float) rand() / (RAND_MAX));
    float rz = ((float) rand() / (RAND_MAX));

    return Vector3(rx, ry, rz);
}