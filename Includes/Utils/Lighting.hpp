#ifndef HEADER_LIGHTING_HPP
#define HEADER_LIGHTING_HPP

#include <vector>

#include <Core/Color.hpp>
#include <Core/Ray.hpp>
#include <Lights/BaseLight.hpp>
#include <Shapes/BaseShape.hpp>

namespace Lighting {
    Color getLighting(const BaseShape& object, const Vector3& point, const Vector3& normal, const Vector3& view, const BaseLight * light);
    Color getLighting(const BaseShape& object, const Vector3& point, const Vector3& normal, const Vector3& view, const vector<BaseLight*>& lights, const vector<BaseShape*>& objects);
    Color getLightingSimple(const BaseShape& object, const Vector3& point, const Vector3& normal, const Vector3& view, const vector<BaseLight*>& lights, const vector<BaseShape*>& objects);

    bool getShadow(const Vector3& point, const BaseLight& light, const vector<BaseShape*>& objects);

    float getShadowFactor(const Vector3& point, const BaseLight& light, const vector<BaseShape*>& objects);
};

#endif // HEADER_LIGHTING_HPP