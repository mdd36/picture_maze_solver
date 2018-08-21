#include <iostream>
#include <tuple>
#include "io/FileHandler.h"
#include "solvers/DFS.cpp"

int main() {
    std::cout << "BEGINNING MAZE SOLVING" << std::endl;
    FileHandler fileHandler;
    auto grid = fileHandler.readFileToGrid("./../data/simple.txt");
    auto headAndTail = fileHandler.createGraph(&grid);
    Solver* solver = new DFS();
    solver->solve(std::get<0>(headAndTail), std::get<1>(headAndTail), &grid);
    fileHandler.writeGridToFile(&grid, "./../output/simple_dfs.txt");
    std::cout << "DONE" << std::endl;
    return 0;
}