#include <iostream>
#include <tuple>
#include <bits/ios_base.h>
#include "io/FileHandler.h"
#include "solvers/DFS.cpp"

int main(int argc, char** argv) {
    std::string fname = "med";
    if(fname.empty() && argc == 0) throw std::invalid_argument("No filename specified in code or through argument");
    std::cout << "BEGINNING MAZE SOLVING" << std::endl;
    FileHandler fileHandler;
    auto grid = fileHandler.readFileToGrid(fname);
    auto headAndTail = fileHandler.createGraph(&grid);
    Solver* solver = new DFS();
    solver->solve(std::get<0>(headAndTail), std::get<1>(headAndTail), &grid);
    fileHandler.writeGridToFile(&grid, fname + solver->getTypeString());
    std::cout << "DONE" << std::endl;
    return 0;
}