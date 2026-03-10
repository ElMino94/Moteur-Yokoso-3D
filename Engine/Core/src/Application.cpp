#include "Application.h"

#include "Logger.h"
#include "Window.h"

Application::Application(){

    Init();

}

Application::~Application(){

    Shutdown();

}

void Application::Init(){

    Logger::Log("Application started");
    m_Window = std::make_unique<Window>(1280, 720, "Yokoso Engine");

}

void Application::Shutdown(){

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