#include <iostream>
#include "Application.h"

namespace eng {
	Application::Application()
	{        
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (true)
		{
			std::cout << "My Engine\n";
		}
	}
}