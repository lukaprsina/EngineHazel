#pragma once

#include "Core/pch.h"
#include "Core/Core.h"
#include "Core/Layer.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "Window.h"

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

        void PushLayer(Layer* layer);
        void PopLayer(Layer* layer);

        void BringLayerToFront(Layer* layer);
        void SendLayerToBack(Layer* layer);

        void BringLayerForward(Layer* layer, unsigned int count = 1);
        void SendLayerBackward(Layer* layer, unsigned int count = 1);

    private:
        bool OnWindowClose(WindowCloseEvent &e);

        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        std::vector<Layer*> m_Layers;
    };

    // To be defined in client
    Application *CreateApplication();
} // namespace eng
