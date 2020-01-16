#include <Lights/SpotLight.hpp>

SpotLight::SpotLight() :
    BaseLight()
{
    m_type = 0x10;
}

SpotLight::SpotLight(Vector3 position, Vector3 intensity) :
    BaseLight(position, intensity)
{
    m_type = 0x10;
}

float SpotLight::attenuate(Vector3 Vobj, Vector3 Vlight) const {
    return Vobj.dot(Vlight);
}