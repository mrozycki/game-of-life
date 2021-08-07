#include "shapes.h"

namespace gfx {
void rect(canvas& canvas, std::size_t x, std::size_t y, std::size_t width, std::size_t height, color const& color) {
    for (auto i = x; i < x + width; ++i) {
        for (auto j = y; j < y + width; ++j) {
            canvas.set_pixel(i, j, color);
        }
    }
}
}  // namespace gfx