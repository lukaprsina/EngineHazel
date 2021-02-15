#pragma once

#ifdef ENG_PLATFORM_WINDOWS

extern eng::Application* eng::CreateApplication();

int main(int argc, char* argv[])
{
	auto app = eng::CreateApplication();
	app->Run();
	delete app;
}

#endif