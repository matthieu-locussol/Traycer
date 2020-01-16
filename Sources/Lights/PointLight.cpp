#include <Lights/PointLight.hpp>

PointLight::PointLight() :
    BaseLight()
{
    m_type = 0x08;
}

PointLight::PointLight(Vector3 position, Vector3 intensity) :
    BaseLight(position, intensity)
{
    m_type = 0x08;
}

float PointLight::attenuate(const float& r) const {
    return 1.0 / (r * r);
}