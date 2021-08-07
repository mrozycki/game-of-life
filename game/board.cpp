#include "board.h"

namespace game {
board::board(std::size_t width, std::size_t height)
    : width_(width), height_(height), cells_(width * height, cell::DEAD) {}

void board::set_cell(int x, int y, cell cell) {
    if (x >= 0 && x < width_ && y >= 0 && y < height_) {
        cells_[y * width_ + x] = cell;
    }
}

cell board::get_cell(int x, int y) const {
    if (x >= 0 && x < width_ && y >= 0 && y < height_) {
        return cells_[y * width_ + x];
    } else {
        return cell::DEAD;
    }
}
}  // namespace game
