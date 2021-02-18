cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project (GameEngine VERSION 1.0)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_subdirectory ("Engine/vendor/GLFW")
add_subdirectory ("Engine/vendor/Glad")
add_subdirectory ("Engine/vendor/spdlog")
add_subdirectory ("Engine")
add_subdirectory ("Game")