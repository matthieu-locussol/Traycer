#include <Lights/AmbientLight.hpp>

AmbientLight::AmbientLight() :
    BaseLight()
{
    m_type = 0x02;
}

AmbientLight::AmbientLight(Vector3 intensity) :
    BaseLight(intensity)
{
    m_type = 0x02;
}

float AmbientLight::attenuate(const float& r) const {
    return 1.0;
}