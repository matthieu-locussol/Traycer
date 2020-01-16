#ifndef HEADER_RAY_HPP
#define HEADER_RAY_HPP

#include <Core/Vector.hpp>

class Ray {
    public:
        Ray(Vector3 origin, Vector3 direction);

        Vector3 getOrigin() const;
        Vector3 getDirection() const;

    private:
        Vector3 m_origin;
        Vector3 m_direction;
};

#endif // HEADER_RAY_HPP