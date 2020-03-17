cmake_minimum_required(VERSION 3.10)

project(game_of_life)

add_executable(game_of_life
    main.cpp
    gfx/canvas.cpp
    gfx/shapes.cpp
    game/board.cpp
    game/logic.cpp)