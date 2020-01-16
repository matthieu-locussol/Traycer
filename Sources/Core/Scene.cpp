#include <Core/Scene.hpp>

Scene::Scene() {
    m_backgroundColor = Color();
}

void Scene::addAmbientLight(AmbientLight light) {
    m_ambientLight = light;
}

void Scene::addLight(BaseLight * light) {
    m_lights.push_back(light);
}

void Scene::addObject(BaseShape * object) {
    m_objects.push_back(object);
}

void Scene::setBackgroundColor(Color backgroundColor) {
    m_backgroundColor = backgroundColor;
}

Color& Scene::getBackgroundColor() {
    return m_backgroundColor;
}

std::vector<BaseLight*>& Scene::getLights() {
    return m_lights;
}

std::vector<BaseShape*>& Scene::getObjects() {
    return m_objects;
}