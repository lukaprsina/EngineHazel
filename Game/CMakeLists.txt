add_executable (Game "src/Game.cpp")

target_include_directories(Game
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src	
)

target_link_libraries(Game
	PUBLIC Engine
	)
