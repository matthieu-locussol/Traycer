#include <Lights/BaseLight.hpp>

BaseLight::BaseLight() :
    m_position(Vector3()),
    m_intensity(Vector3())
{
    m_type = 0x01;
}

BaseLight::BaseLight(Vector3 intensity) :
    m_position(Vector3()),
    m_intensity(intensity)
{
    m_type = 0x01;
}

BaseLight::BaseLight(Vector3 position, Vector3 intensity) :
    m_position(position),
    m_intensity(intensity)
{
    m_type = 0x01;
}

float BaseLight::attenuate(const float& r) const{
    return 1.0;
}

unsigned char BaseLight::getType() const {
    return m_type;
}

int BaseLight::getSamples() const {
    return m_samples;
}

float BaseLight::getWidth() const {
    return m_width;
}

float BaseLight::getHeight() const {
    return m_height;
}

Vector3 BaseLight::getPosition() const {
    return m_position;
}

Vector3 BaseLight::getIntensity() const {
    return m_intensity;
}