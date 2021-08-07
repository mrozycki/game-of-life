add_executable(game_of_life
    main.cpp
    gfx/canvas.cpp
    gfx/shapes.cpp
    game/board.cpp
    game/logic.cpp)

set_property(TARGET game_of_life PROPERTY CXX_STANDARD 17)