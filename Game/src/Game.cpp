#include "Engine.h"

class Game : public eng::Application
{
public:
	Game()
	{

	}
	~Game()
	{

	}
};

eng::Application* eng::CreateApplication()
{
	return new Game();
}