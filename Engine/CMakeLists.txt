add_library (Engine "src/Application.cpp")

add_definitions(ENG_PLATFORM_WINDOWS ENG_BUILD_DLL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

target_include_directories(Engine
          PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
          )