#ifndef HEADER_SCENE_HPP
#define HEADER_SCENE_HPP

#include <vector>

#include <Core/Color.hpp>
#include <Lights/AmbientLight.hpp>
#include <Lights/BaseLight.hpp>
#include <Shapes/BaseShape.hpp>

class Scene {
    public:
        Scene();

        void addAmbientLight(AmbientLight light);
        void addLight(BaseLight * light);
        void addObject(BaseShape * object);

        void setBackgroundColor(Color backgroundColor);

        Color& getBackgroundColor();
        std::vector<BaseLight*>& getLights();
        std::vector<BaseShape*>& getObjects();

    private:
        Color m_backgroundColor;

        AmbientLight m_ambientLight;

        std::vector<BaseLight*> m_lights;
        std::vector<BaseShape*> m_objects;
};

#endif // HEADER_SCENE_HPP