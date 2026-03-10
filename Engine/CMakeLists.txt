find_package(Vulkan REQUIRED)

add_library(Engine STATIC
    Core/src/Application.cpp
    Core/src/Logger.cpp
    Platform/src/Window.cpp
    Renderer/src/VulkanContext.cpp
)

target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Core/include
        ${CMAKE_CURRENT_SOURCE_DIR}/Platform/include
        ${CMAKE_CURRENT_SOURCE_DIR}/Renderer/include
)

target_link_libraries(Engine
    PUBLIC
        glfw
        Vulkan::Vulkan
)