#include "canvas.h"

#include <fstream>

namespace gfx {
canvas::canvas(std::size_t width, std::size_t height)
    : width_(width)
    , height_(height)
    , pixels_(width * height, color{0}) {}

void canvas::set_pixel(std::size_t x, std::size_t y, color c) {
    if (x < width_ && y < height_) {
        pixels_[y * width_ + x] = c;
    }
}

color canvas::get_pixel(std::size_t x, std::size_t y) const {
    if (x < width_ && y < height_) {
        return pixels_[y * width_ + x];
    } else {
        return color{0};
    }
}

std::ostream& operator<<(std::ostream& out, canvas const& c) {
    out << "P1\n";
    out << c.width() << " " << c.height() << "\n";
    for (auto y = 0; y < c.height(); ++y) {
        for (auto x = 0; x < c.width(); ++x) {
            out << c.get_pixel(x, y).black << " ";
        }
    }

    return out;
}

void print_to_file(std::string const& filename, canvas const& c) {
    std::fstream file(filename, std::ios::out);
    file << c;
}
}