#ifndef HEADER_BASESHAPE_HPP
#define HEADER_BASESHAPE_HPP

#include <Core/Color.hpp>
#include <Core/Constants.hpp>
#include <Core/Ray.hpp>
#include <Core/Vector.hpp>

class BaseShape {
    public:
        virtual bool intersect(const Ray& ray, float& to, float& t1);
        virtual Vector3 getNormal(const Vector3& hitPoint);

        void setCenter(Vector3 center);

        void setColor(Color color);
        void setColorSpecular(Color colorSpecular);

        void setKa(float ka);
        void setKd(float kd);
        void setKs(float ks);

        void setShininess(float shininess);
        void setReflectivity(float reflectivity);
        void setTransparency(float transparency);

        void setGlossiness(float glossiness);
        void setGlossyTransparency(float glossyTransparency);

        Vector3 getCenter() const;

        Color getColor() const;
        Color getColorSpecular() const;

        float getKa() const;
        float getKd() const;
        float getKs() const;

        float getShininess() const;
        float getReflectivity() const;
        float getTransparency() const;

        float getGlossiness() const;
        float getGlossyTransparency() const;

    protected:
        Vector3 m_center;

        Color m_color;
        Color m_colorSpecular;

        float m_ka;
        float m_kd;
        float m_ks;

        float m_shininess;
        float m_reflectivity;
        float m_transparency;

        float m_glossiness;
        float m_glossyTransparency;
};

#endif // HEADER_BASESHAPE_HPP