#ifndef HEADER_DIRECTIONALLIGHT_HPP
#define HEADER_DIRECTIONALLIGHT_HPP

#include <Lights/BaseLight.hpp>

class DirectionalLight : public BaseLight {
    public:
        DirectionalLight();
        DirectionalLight(Vector3 position, Vector3 intensity);

        float attenuate(const float& r) const;
};

#endif // HEADER_DIRECTIONALLIGHT_HPP