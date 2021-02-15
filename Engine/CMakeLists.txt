add_library (Engine "src/Application.cpp")

target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(ENG_PLATFORM ENG_PLATFORM_UNKNOWN)

if (WIN32)
  set(ENG_PLATFORM ENG_PLATFORM_WINDOWS)
endif (WIN32)
if (UNIX)
  set(ENG_PLATFORM ENG_PLATFORM_UNIX)
endif (UNIX)

target_compile_definitions(Engine PUBLIC ENG_BUILD_DLL ${ENG_PLATFORM})

target_include_directories(Engine
          PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
          )