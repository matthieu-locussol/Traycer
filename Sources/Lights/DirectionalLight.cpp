#include <Lights/DirectionalLight.hpp>

DirectionalLight::DirectionalLight() :
    BaseLight()
{
    m_type = 0x04;
}

DirectionalLight::DirectionalLight(Vector3 position, Vector3 intensity) :
    BaseLight(position, intensity)
{
    m_type = 0x04;
}

float DirectionalLight::attenuate(const float& r) const {
    return 1.0;
}