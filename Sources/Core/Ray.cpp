#include <Core/Ray.hpp>

Ray::Ray(Vector3 origin, Vector3 direction) :
    m_origin(origin),
    m_direction(direction)
{

}

Vector3 Ray::getOrigin() const {
    return m_origin;
}

Vector3 Ray::getDirection() const {
    return m_direction;
}