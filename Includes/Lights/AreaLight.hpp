#ifndef HEADER_AREALIGHT_HPP
#define HEADER_AREALIGHT_HPP

#include <Lights/BaseLight.hpp>

class AreaLight : public BaseLight {
    public:
        AreaLight();
        AreaLight(Vector3 position, Vector3 intensity);

        float attenuate(const float& r) const;
};

#endif // HEADER_AREALIGHT_HPP