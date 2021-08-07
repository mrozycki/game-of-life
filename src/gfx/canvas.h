#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace gfx {
struct color {
    bool black;
};

class canvas {
public:
    canvas(std::size_t width, std::size_t height);

    void set_pixel(std::size_t x, std::size_t y, color c);
    color get_pixel(std::size_t x, std::size_t y) const;

    std::size_t width() const { return width_; }
    std::size_t height() const { return height_; }

    friend std::ostream& operator<<(std::ostream& out, canvas const& c);

private:
    std::size_t width_;
    std::size_t height_;
    std::vector<color> pixels_;
};

}  // namespace gfx