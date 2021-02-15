#pragma once

extern eng::Application* eng::CreateApplication();

int main(int argc, char* argv[])
{
	auto app = eng::CreateApplication();
	app->Run();
	delete app;
}