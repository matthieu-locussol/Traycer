#ifndef HEADER_BASELIGHT_HPP
#define HEADER_BASELIGHT_HPP

#include <Core/Vector.hpp>

class BaseLight {
    public:
        BaseLight();
        BaseLight(Vector3 intensity);
        BaseLight(Vector3 position, Vector3 intensity);

        virtual float attenuate(const float& r) const;

        unsigned char getType() const;
        int getSamples() const;
        float getWidth() const;
        float getHeight() const;

        Vector3 getPosition() const;
        Vector3 getIntensity() const;

    protected:
        unsigned char m_type;

        int m_samples;

        float m_width;
        float m_height;

    private:
        Vector3 m_position;
        Vector3 m_intensity;
};

#endif // HEADER_BASELIGHT_HPP