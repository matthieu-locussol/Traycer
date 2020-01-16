#ifndef HEADER_SPHERE_HPP
#define HEADER_SPHERE_HPP

#include <Shapes/BaseShape.hpp>

class Sphere : public BaseShape {
    public:
        Sphere(const Vector3& center, const float radius, const Color& color, const float ka, const float kd, const float ks, const float shinny = 128.0, const float reflectScale = 1.0, const float transparency = 0.0);

        bool intersect(const Ray& ray, float& t0, float& t1);
        Vector3 getNormal(const Vector3& hitPoint);

    private:
        float m_radius;
        float m_radiusSquared;
};

#endif // HEADER_SPHERE_HPP