add_library (Engine SHARED "src/Core/Application.cpp" "src/Platform/GLFWWindow.cpp")

target_include_directories(Engine
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/Glad/include
	)

target_link_libraries(Engine
	PRIVATE glfw
	PRIVATE libobsglad.so
	)

if (WIN32)
	set(ENG_PLATFORM ENG_PLATFORM_WINDOWS)
endif (WIN32)
if (UNIX)
	set(ENG_PLATFORM ENG_PLATFORM_UNIX)
endif (UNIX)

target_compile_definitions(Engine
	PRIVATE ENG_BUILD_DLL
	${ENG_PLATFORM}
	PRIVATE GLFW_INCLUDE_NONE
	)