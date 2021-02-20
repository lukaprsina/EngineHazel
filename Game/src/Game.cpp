#include "Engine.h"

class TransparentLayer : public eng::Layer
{
public:
    TransparentLayer()
        : Layer()
    {
    }

    void OnEvent(eng::Event &event) override
    {
        ENG_TRACE("Transparent: {0}", event.ToString());
    }
};

class BlockingLayer : public eng::Layer
{
public:
    BlockingLayer()
        : Layer()
    {
    }

    void OnEvent(eng::Event &event) override
    {
        ENG_TRACE("Block: {0}", event.ToString());
        ENG_TRACE("-------------");
        event.Handled = true;
    }
};

class Game : public eng::Application
{
public:
    Game()
    {
        TransparentLayer *gameLayer = new TransparentLayer;
        PushLayer(gameLayer);

        BlockingLayer *uiLayer = new BlockingLayer;
        PushLayer(uiLayer);

        TransparentLayer *warningLayer = new TransparentLayer;
        PushLayer(warningLayer);

        BringLayerToFront(gameLayer);
        BringLayerForward(uiLayer, 2);
        SendLayerBackward(uiLayer, 1);
    }
    ~Game()
    {
    }
};

eng::Application *eng::CreateApplication()
{
    return new Game();
}