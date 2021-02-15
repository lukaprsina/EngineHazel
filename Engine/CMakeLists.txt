add_library (Engine "src/Application.cpp")

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_definitions(Engine PUBLIC ENG_PLATFORM_WINDOWS ENG_BUILD_DLL)

target_include_directories(Engine
          PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
          )