cmake_minimum_required (VERSION 3.8)

project (Engine VERSION 1.0)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_subdirectory ("Engine/vendor/GLFW")
add_subdirectory ("Engine")
add_subdirectory ("Game")