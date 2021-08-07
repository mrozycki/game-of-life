#include "canvas.h"

#include <fstream>

namespace gfx {
canvas::canvas(std::size_t width, std::size_t height)
    : width_(width), height_(height), pixels_(width * height, color{0}) {}

void canvas::set_pixel(std::size_t x, std::size_t y, color c) {
    if (x < width_ && y < height_) {
        pixels_[y * width_ + x] = c;
    }
}

std::ostream& operator<<(std::ostream& out, canvas const& c) {
    out << "P1 " << c.width() << " " << c.height() << "\n";
    for (auto pixel : c.pixels_) {
        out << pixel.black << " ";
    }
    return out;
}
}  // namespace gfx