#ifndef HEADER_COLOR_HPP
#define HEADER_COLOR_HPP

#include <Core/Vector.hpp>

struct Color {
    public:
        Color();
        Color(float c);
        Color(float _r, float _g, float _b);

        Color operator * (float f) const;
        Color operator * (Vector3 f) const;
        Color operator * (Color c) const;
        Color operator + (Color c) const;
        Color& operator += (const Color &c);
        Color& operator *= (const Color &c);

        Color& clamp();

    public:
        float r;
        float g;
        float b;
};

#endif // HEADER_COLOR_HPP