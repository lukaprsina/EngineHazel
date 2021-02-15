#pragma once

#include "Core.h"

namespace eng {
	class ENG_API Application
	{
	public:
		Application();
		virtual ~Application();

		// Start the program
		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

