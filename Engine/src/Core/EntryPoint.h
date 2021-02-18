#pragma once
#include "Core/Log.h"

extern eng::Application *eng::CreateApplication();

int main(int argc, char *argv[])
{
    eng::Log::Init();

    ENG_CORE_CRITICAL("ls");

    auto app = eng::CreateApplication();
    app->Run();
    delete app;
}