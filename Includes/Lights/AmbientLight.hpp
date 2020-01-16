#ifndef HEADER_AMBIENTLIGHT_HPP
#define HEADER_AMBIENTLIGHT_HPP

#include <Lights/BaseLight.hpp>

class AmbientLight : public BaseLight {
    public:
        AmbientLight();
        AmbientLight(Vector3 intensity);

        float attenuate(const float& r) const;
};

#endif // HEADER_AMBIENTLIGHT_HPP