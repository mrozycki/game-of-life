#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "game/board.h"
#include "game/logic.h"
#include "gfx/canvas.h"
#include "gfx/shapes.h"

gfx::canvas draw_board(game::board const& board, std::size_t scale_factor = 1) {
    gfx::canvas canvas(board.width() * scale_factor, board.height() * scale_factor);
    for (auto i = 0; i < board.width(); ++i) {
        for (auto j = 0; j < board.height(); ++j) {
            if (board.get_cell(i, j) == game::cell::ALIVE) {
                gfx::rect(canvas, i * scale_factor, j * scale_factor, scale_factor, scale_factor, gfx::color{1});
            }
        }
    }
    return canvas;
}

std::string generate_filename(std::string const& prefix, std::size_t index) {
    std::stringstream ss;
    ss << prefix << std::setfill('0') << std::setw(3) << index << ".pbm";
    return ss.str();
}

int main() {
    game::board glider(10, 10);
    glider.set_cell(2, 1, game::cell::ALIVE);
    glider.set_cell(3, 2, game::cell::ALIVE);
    glider.set_cell(1, 3, game::cell::ALIVE);
    glider.set_cell(2, 3, game::cell::ALIVE);
    glider.set_cell(3, 3, game::cell::ALIVE);

    for (auto i = 0; i < 30; ++i) {
        gfx::print_to_file(generate_filename("glider", i), draw_board(glider, 10));
        glider = game::next_generation(glider);
    }

    return 0;
}