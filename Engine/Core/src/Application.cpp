#include "Application.h"

#include "Logger.h"
#include "Assert.h"

Application::Application()
{
    Init();
}

Application::~Application()
{
    Shutdown();
}

void Application::Init()
{
    Logger::Log("Application started");
}

void Application::Shutdown()
{
    Logger::Log("Application shutdown");
}

void Application::Run()
{
    while (m_Running)
    {
        Logger::Log("Engine frame");

        m_Running = false;
    }
}

