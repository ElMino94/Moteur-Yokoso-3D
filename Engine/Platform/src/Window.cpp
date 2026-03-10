#include "Window.h"
#include "Logger.h"

#include <GLFW/glfw3.h>

Window::Window(int width, int height, const char* title)
    : m_Width(width), m_Height(height), m_Title(title)
{
    if (!glfwInit())
    {
        Logger::Error("Failed to initialize GLFW");
        return;
    }

    // Important pour Vulkan plus tard :
    // on ne veut PAS qu'OpenGL soit créé automatiquement.
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);

    if (!m_Window)
    {
        Logger::Error("Failed to create GLFW window");
        glfwTerminate();
        return;
    }

    Logger::Log("Window created");
}

Window::~Window()
{
    if (m_Window)
    {
        glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }

    glfwTerminate();
    Logger::Log("Window destroyed");
}

void Window::PollEvents()
{
    glfwPollEvents();
}

bool Window::ShouldClose() const
{
    if (!m_Window)
    {
        return true;
    }

    return glfwWindowShouldClose(m_Window);
}