#include "logic.h"

namespace {
std::size_t count_neighbours(game::board const& board, int x, int y) {
    std::size_t result = 0;
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            if (!(x == i && y == j) && board.get_cell(i, j) == game::cell::ALIVE) {
                ++result;
            }
        }
    }
    return result;
}
}

namespace game {
board next_generation(board const& previous) {
    board next(previous.width(), previous.height());
    for(int y = 0; y < next.height(); ++y) {
        for (int x = 0; x < next.width(); ++x) {
            auto neighbours = count_neighbours(previous, x, y);
            if (previous.get_cell(x, y) == cell::ALIVE && (neighbours == 2 || neighbours == 3)) {
                next.set_cell(x, y, cell::ALIVE);
            } else if (previous.get_cell(x, y) == cell::DEAD && neighbours == 3) {
                next.set_cell(x, y, cell::ALIVE);
            } else {
                next.set_cell(x, y, cell::DEAD);
            }
        }
    }
    return next;
}
}