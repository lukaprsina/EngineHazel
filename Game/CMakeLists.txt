add_executable (Game
	"src/Game.cpp"	
	)

target_compile_definitions(Game
	PRIVATE ENG_PLATFORM_WINDOWS
	)

target_include_directories(Game
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
	)

target_link_libraries(Game	
	PUBLIC Engine
	)
