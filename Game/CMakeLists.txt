add_library(Game STATIC
    Game.cpp
)

target_include_directories(Game
    PUBLIC
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(Game
    PUBLIC
        Engine
)