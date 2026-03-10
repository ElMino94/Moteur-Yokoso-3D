#include "Application.h"

#include "Logger.h"
#include "Window.h"
#include "VulkanContext.h"

Application::Application(){

    Init();

}

Application::~Application(){

    Shutdown();

}

void Application::Init(){

    Logger::Log("Application started");

    m_Window = std::make_unique<Window>(1280, 720, "Yokoso Engine");

    m_Renderer = std::make_unique<VulkanContext>(m_Window.get());
    m_Renderer->Init();

}

void Application::Shutdown(){

    m_Renderer.reset();
    m_Window.reset();

    Logger::Log("Application shutdown");

}

void Application::Run(){

    while (m_Running){

        if (!m_Window || m_Window->ShouldClose()){

            m_Running = false;
            continue;

        }

        m_Window->PollEvents();

    }

}