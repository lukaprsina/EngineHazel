add_library (Engine SHARED
	"src/Core/pch.cpp"
	"src/Core/Application.cpp"
	"src/Platform/GLFWWindow.cpp"
	"src/Core/Log.cpp"
)

target_include_directories(Engine
	PRIVATE ${PROJECT_BINARY_DIR}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/Glad/include
	)

target_link_libraries(Engine
	PRIVATE glfw
	PRIVATE Glad
	#PRIVATE spdlog
	)

if (WIN32)
	set(ENG_PLATFORM ENG_PLATFORM_WINDOWS)
endif (WIN32)
if (UNIX)
	set(ENG_PLATFORM ENG_PLATFORM_UNIX)
endif (UNIX)

target_compile_definitions(Engine
	PRIVATE ${ENG_PLATFORM}
	PRIVATE ENG_BUILD_DLL
	PRIVATE GLFW_INCLUDE_NONE
	)