#ifndef HEADER_POINTLIGHT_HPP
#define HEADER_POINTLIGHT_HPP

#include <Lights/BaseLight.hpp>

class PointLight : public BaseLight {
    public:
        PointLight();
        PointLight(Vector3 position, Vector3 intensity);

        float attenuate(const float& r) const;
};

#endif // HEADER_POINTLIGHT_HPP