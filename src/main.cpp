#include <iostream>
#include <tuple>
#include "FileHandler.h"
#include "DFS.cpp"

using namespace std;

int main() {


    cout << "BEGINNING MAZE SOLVING" << endl;

    FileHandler fileHandler;
    auto grid = fileHandler.readFileToGrid("./../data/simple.txt");
    auto headAndTail = fileHandler.createGraph(&grid);
    Solver* solver = new DFS();
    solver->solve(get<0>(headAndTail), get<1>(headAndTail), &grid);
    for(std::vector<int> row: grid) {
        for (int i : row)
            cout << i << " ";
        cout << endl;
    }
    fileHandler.writeGridToFile(&grid, "./../output/simple_dfs.txt");
    cout << "DONE" << endl;
    return 0;
}