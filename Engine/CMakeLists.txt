add_library(Engine STATIC
    Core/src/Application.cpp
    Core/src/Logger.cpp
 )

target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/include
)