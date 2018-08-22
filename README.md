# picture_maze_solver
A pictorial maze solver as a C++ exercise. This is not the most efficent solution to the problem and is not in the most "C++" coding style.
This was mostly for learning, not efficency.
## Details
The solver uses Python to create a .txt file of the maze picture, which gets read into the C++ program as a grid. It then builds a graph, placing nodes at decision points on the grid and connecting adjacent nodes as long as no walls seperate them. It can solve the maze using DFS, BFS, Dijkstra's, or A*, coloring visited squares red and all squares used on its path blue. The resulting integer grid is exported to a .txt file, and another Python script can rebuild the image with colors from there.
