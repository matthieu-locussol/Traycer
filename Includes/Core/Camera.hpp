#ifndef HEADER_CAMERA_HPP
#define HEADER_CAMERA_HPP

#include <Core/Vector.hpp>

class Camera {
  public:
    Camera(Vector3 position, int width, int height, float fov);

    Vector3 pixelToViewport(Vector3 pixel);

    Vector3& getPosition();

    void setPosition(Vector3 position);
    void setAngleX(float angleX);
    void setAngleY(float angleY);
    void setAngleZ(float angleZ);

  private:
    Vector3 m_position;

    int m_width;
    int m_height;

    float m_invWidth;
    float m_invHeight;
    float m_fov;
    float m_aspectRatio;

    float m_angle;
    float m_angleX;
    float m_angleY;
    float m_angleZ;
};

#endif // HEADER_CAMERA_HPP