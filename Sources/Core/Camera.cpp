#include <Core/Camera.hpp>

Camera::Camera(Vector3 position, int width, int height, float fov) {
    m_position = position;

    m_width = width;
    m_height = height;

    m_invWidth = 1 / (float)(m_width);
    m_invHeight = 1 / (float)(m_height);
    m_fov = fov;
    m_aspectRatio = m_width / float(m_height);

    m_angle = tan(0.5 * m_fov * M_PI/ 180.0);
    m_angleX = 0;
    m_angleY = 0;
    m_angleZ = 0;
}

Vector3 Camera::pixelToViewport(Vector3 pixel) {
    float x = (2 * ((pixel.x + 0.5) * m_invWidth) - 1) * m_angle * m_aspectRatio;
    float y = (1 - 2 * ((pixel.y + 0.5) * m_invHeight)) * m_angle;

    Vector3 rayDirection = Vector3(x, y, pixel.z);
    rayDirection.rotateX(m_angleX);
    rayDirection.rotateY(m_angleY);
    rayDirection.rotateZ(m_angleZ);
    rayDirection.normalize();

    return rayDirection;
}

Vector3& Camera::getPosition() {
    return m_position;
}

void Camera::setPosition(Vector3 position) {
    m_position = position;
}

void Camera::setAngleX(float angleX) {
    m_angleX = angleX;
}

void Camera::setAngleY(float angleY) {
    m_angleY = angleY;
}

void Camera::setAngleZ(float angleZ) {
    m_angleZ = angleZ;
}