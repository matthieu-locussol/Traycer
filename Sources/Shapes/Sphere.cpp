#include <Shapes/Sphere.hpp>

Sphere::Sphere(const Vector3& center, const float radius, const Color& color, const float ka, const float kd, const float ks, const float shinny, const float reflectScale, const float transparency) :
    m_radius(radius),
    m_radiusSquared(radius * radius)
{
    m_center = center;

    m_color = color;
    m_colorSpecular = Color(255);

    m_ka = ka;
    m_kd = kd;
    m_ks = ks;

    m_shininess = shinny;
    m_reflectivity = reflectScale;
    m_transparency = transparency;

    m_glossiness = 0;
    m_glossyTransparency = 0;
}

bool Sphere::intersect(const Ray& ray, float& t0, float& t1) {
    Vector3 l = m_center - ray.getOrigin();
    float tca = l.dot(ray.getDirection());

    if (tca < 0) {
        return false;
    }

    float d2 = l.dot(l) - tca * tca;

    if (d2 > m_radiusSquared) {
        return false;
    }

    float thc = sqrt(m_radiusSquared - d2);

    t0 = tca - thc;
    t1 = tca + thc;

    return true;
}

Vector3 Sphere::getNormal(const Vector3 &hitPoint) {
    return (hitPoint - m_center) / m_radius;
}