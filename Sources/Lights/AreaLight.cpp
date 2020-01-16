#include <Lights/AreaLight.hpp>

AreaLight::AreaLight() :
    BaseLight()
{
    m_type = 0x20;
    m_samples = 2;
    m_width = 4;
    m_height = 4;
}

AreaLight::AreaLight(Vector3 position, Vector3 intensity) :
    BaseLight(position, intensity)
{
    m_type = 0x20;
    m_samples = 2;
    m_width = 4;
    m_height = 4;
}

float AreaLight::attenuate(const float& r) const {
    return 1.0;
}