#pragma once

#include <vector>

namespace game {
enum class cell { DEAD, ALIVE };

class board {
public:
    board(std::size_t width, std::size_t height);

    void set_cell(int x, int y, cell cell);
    cell get_cell(int x, int y) const;

    std::size_t width() const { return width_; }
    std::size_t height() const { return height_; }

private:
    std::size_t width_;
    std::size_t height_;
    std::vector<cell> cells_;
};
}  // namespace game