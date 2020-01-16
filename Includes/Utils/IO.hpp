#ifndef HEADER_IO_HPP
#define HEADER_IO_HPP

#include <Core/Color.hpp>

namespace IO {
    void ImageToPPMFile(Color * image, int width, int height);
};

#endif // HEADER_IO_HPP