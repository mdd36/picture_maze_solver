cmake_minimum_required(VERSION 3.8)
project(picture_maze_solver)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/graph/GraphNode.cpp src/graph/GraphNode.h src/graph/GraphEdge.cpp src/graph/GraphEdge.h src/io/FileHandler.cpp src/io/FileHandler.h src/solvers/BFS.cpp src/solvers/Dijkstra.cpp src/solvers/Solvers.h src/solvers/AStar.cpp src/solvers/comparators/NodeComparator.h src/solvers/comparators/DijkstraComparator.cpp src/solvers/comparators/AStarComparator.cpp)
set(Python_ADDITIONAL_VERSIONS 3.6)
set(PYTHON_EXECUTABLE C:\\Users\\matth\\AppData\\Local\\Programs\\Python\\Python36\\python.exe)
find_package( PythonInterp 3.6 REQUIRED )
set(PYTHON_LIBRARY C:\\Users\\matth\\AppData\\Local\\Programs\\Python\\Python36\\libs\\python36.lib)
find_package(PythonLibs 3.6 REQUIRED)
include_directories ( ${PYTHON_INCLUDE_DIRS} )

add_executable(picture_maze_solver ${SOURCE_FILES})