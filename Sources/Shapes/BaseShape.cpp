#include <Shapes/BaseShape.hpp>

bool BaseShape::intersect(const Ray& ray, float& to, float& t1) {
    return false;
}

Vector3 BaseShape::getNormal(const Vector3& hitPoint) {
    return Vector3();
}

void BaseShape::setCenter(Vector3 center) {
    m_center = center;
}

void BaseShape::setColor(Color color) {
    m_color = color;
}

void BaseShape::setColorSpecular(Color colorSpecular) {
    m_colorSpecular = colorSpecular;
}

void BaseShape::setKa(float ka) {
    m_ka = ka;
}

void BaseShape::setKd(float kd) {
    m_kd = kd;
}

void BaseShape::setKs(float ks) {
    m_ks = ks;
}

void BaseShape::setShininess(float shininess) {
    m_shininess = shininess;
}

void BaseShape::setReflectivity(float reflectivity) {
    m_reflectivity = reflectivity;
}

void BaseShape::setTransparency(float transparency) {
    m_transparency = transparency;
}

void BaseShape::setGlossiness(float glossiness) {
    m_glossiness = glossiness;
}

void BaseShape::setGlossyTransparency(float glossyTransparency) {
    m_glossyTransparency = glossyTransparency;
}

Vector3 BaseShape::getCenter() const {
    return m_center;
}

Color BaseShape::getColor() const {
    return m_color;
}

Color BaseShape::getColorSpecular() const {
    return m_colorSpecular;
}

float BaseShape::getKa() const {
    return m_ka;
}

float BaseShape::getKd() const {
    return m_kd;
}

float BaseShape::getKs() const {
    return m_ks;
}

float BaseShape::getShininess() const {
    return m_shininess;
}

float BaseShape::getReflectivity() const {
    return m_reflectivity;
}

float BaseShape::getTransparency() const {
    return m_transparency;
}

float BaseShape::getGlossiness() const {
    return m_glossiness;
}

float BaseShape::getGlossyTransparency() const {
    return m_glossyTransparency;
}