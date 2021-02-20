#include "Engine.h"

class MyLayer : public eng::Layer
{
public:
    MyLayer()
        : Layer()
    {}

    void OnEvent(eng::Event& event) override
    {        
        ENG_TRACE("MyLayer: {0}", event.ToString());        
    }
};

class MyOtherLayer : public eng::Layer
{
public:
    MyOtherLayer()
        : Layer()
    {}

    void OnEvent(eng::Event& event) override
    {        
        ENG_TRACE("MyOtherLayer: {0}", event.ToString());
        event.Handled = true;
    }
};

class Game : public eng::Application
{
public:
    Game()
    {
        MyLayer* gameLayer = new MyLayer;
        PushLayer(gameLayer);

        MyOtherLayer* uiLayer = new MyOtherLayer;
        PushLayer(uiLayer);

        BringLayerForward(gameLayer);
    }
    ~Game()
    {
    }
};

eng::Application *eng::CreateApplication()
{
    return new Game();
}