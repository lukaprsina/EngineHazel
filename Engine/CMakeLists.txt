add_library (Engine SHARED
	"src/Core/pch.cpp"
	"src/Core/Application.cpp"
	"src/Platform/GLFWWindow.cpp"
	"src/Core/Log.cpp"
)

target_include_directories(Engine
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/Glad/include
	)

target_precompile_headers(Engine
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/pch.h
	)

target_link_libraries(Engine
	PRIVATE glfw
	PRIVATE Glad
	PRIVATE spdlog::spdlog_header_only
	)

target_compile_definitions(Engine
	PUBLIC ${ENG_PLATFORM}
	PRIVATE ENG_BUILD_DLL
	PRIVATE GLFW_INCLUDE_NONE
	)