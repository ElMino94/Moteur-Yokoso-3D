#include "Application.h"
#include <iostream>

Application::Application()
{
    std::cout << "Application started\n";
}

Application::~Application()
{
    std::cout << "Application shutdown\n";
}

void Application::Run()
{
    while (m_Running)
    {
        std::cout << "Engine frame\n";
        m_Running = false;
    }
}