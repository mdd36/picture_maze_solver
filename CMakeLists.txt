cmake_minimum_required(VERSION 3.8)
project(picture_maze_solver)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/GraphNode.cpp src/GraphNode.h src/GraphEdge.cpp src/GraphEdge.h src/png.h src/FileParser.cpp src/FileParser.h)
add_subdirectory(lib)
add_library(jpeg.lib OBJECT)
add_executable(picture_maze_solver ${SOURCE_FILES})