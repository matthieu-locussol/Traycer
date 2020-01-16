#include <Utils/IO.hpp>

#include <fstream>

namespace IO {
    void ImageToPPMFile(Color * image, int width, int height) {
        std::ofstream out("./scene.ppm", std::ios::out | std::ios::binary);
        out << "P6\n" << width << " " << height << "\n255\n";

        for (unsigned i = 0; i < width * height; ++i) {
            Color pixel = image[i].clamp();

            out << (unsigned char) pixel.r;
            out << (unsigned char) pixel.g;
            out << (unsigned char) pixel.b;
        }

        out.close();
    }
};