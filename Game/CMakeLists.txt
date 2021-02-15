cmake_minimum_required (VERSION 3.8)

add_executable (Game "src/Game.cpp")

target_link_libraries(Game PRIVATE Engine)
