#include "Core/Application.h"
#include "Core/Log.h"

#include <glad/glad.h>

namespace eng
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        eng::Log::Init();
        ENG_CORE_TRACE("Creating an Application class...");
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
        ENG_CORE_TRACE("Destroying the Application class...");
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));  

        for (auto it = m_Layers.end(); it != m_Layers.begin(); )
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
            for (Layer* layer : m_Layers)
                layer->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        ENG_CORE_TRACE("Closing the window...");
        m_Running = false;
        return true;
    }
} // namespace eng