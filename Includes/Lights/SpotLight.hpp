#ifndef HEADER_SPOTLIGHT_HPP
#define HEADER_SPOTLIGHT_HPP

#include <Lights/BaseLight.hpp>

class SpotLight : public BaseLight {
    public:
        SpotLight();
        SpotLight(Vector3 position, Vector3 intensity);

        float attenuate(Vector3 Vobj, Vector3 Vlight) const;
    private:
        using BaseLight::attenuate;
};

#endif // HEADER_SPOTLIGHT_HPP