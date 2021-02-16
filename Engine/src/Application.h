#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "Window.h"

#include <memory>

namespace eng
{
    class ENG_API Application
    {
    public:
        Application();
        virtual ~Application();

        // Start the program
        void Run();

        void OnEvent(Event &e);

    private:
        bool OnWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // To be defined in client
    Application *CreateApplication();
} // namespace eng
