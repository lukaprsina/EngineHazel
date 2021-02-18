#include "Core/Application.h"
#include "Core/Log.h"

#include <Glad/glad.h>

namespace eng
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        ENG_CORE_TRACE("Creating Application.");
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }

    Application::~Application()
    {
        ENG_CORE_TRACE("Destroying Application.");
    }

    void Application::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(1, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        ENG_CORE_TRACE("Closing Window.");
        m_Running = false;
        return true;
    }
} // namespace eng