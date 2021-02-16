#include <iostream>
#include "Application.h"
#include "Events/ApplicationEvent.h"

namespace eng
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);

        std::cout << e << '\n';
        
        while (true);      
    }
} // namespace eng