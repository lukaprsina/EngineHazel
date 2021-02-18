#include "GLFWWindow.h"
#include "Core/Log.h"

#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"

#include <Glad/glad.h>

namespace eng
{

    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char *description)
    {
        ENG_CORE_ERROR("GLFW Error [{0}]: {1}", error, description);
    }

    Window *Window::Create(const WindowProps &props)
    {
        return new GLFWWindow(props);
    }

    GLFWWindow::GLFWWindow(const WindowProps &props)
    {
        ENG_CORE_TRACE("Creating a GLFW window.");
        Init(props);
    }

    GLFWWindow::~GLFWWindow()
    {
        ENG_CORE_TRACE("Destroying the GLFW window.");
        Shutdown();
    }

    void GLFWWindow::Init(const WindowProps &props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        if (s_GLFWInitialized)
        {
            ENG_CORE_TRACE("GLFW already initialized.");
        }
        else
        {
            int success = glfwInit();
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
            ENG_CORE_TRACE("Initialized GLFW.");
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        ENG_CORE_TRACE("Created a window.");

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            ENG_CORE_ERROR("Cannot initialize Glad.");
        }
        else
        {
            ENG_CORE_TRACE("Initialized Glad.");
        }

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // Set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            switch (action)
            {
            case GLFW_PRESS:
            {
                KeyPressedEvent event(key, 0);
                data.EventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                data.EventCallback(event);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressedEvent event(key, 1);
                data.EventCallback(event);
                break;
            }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            switch (action)
            {
            case GLFW_PRESS:
            {
                MouseButtonPressedEvent event(button);
                data.EventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                MouseButtonReleasedEvent event(button);
                data.EventCallback(event);
                break;
            }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffset, double yOffset) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xPos, double yPos) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)xPos, (float)yPos);
            data.EventCallback(event);
        });
    }

    void GLFWWindow::Shutdown()
    {
        ENG_CORE_TRACE("Destroying GLFW window.");
        glfwDestroyWindow(m_Window);
    }

    void GLFWWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void GLFWWindow::SetVSync(bool enabled)
    {
        if (enabled)
        {
            glfwSwapInterval(1);
            ENG_CORE_TRACE("VSync enabled.");
        }
        else
        {
            glfwSwapInterval(0);
            ENG_CORE_TRACE("VSync disabled.");
        }
        m_Data.VSync = enabled;
    }

    bool GLFWWindow::IsVSync() const
    {
        return m_Data.VSync;
    }

} // namespace eng
