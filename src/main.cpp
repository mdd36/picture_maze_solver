#include <iostream>
#include <tuple>
#include "FileHandler.h"
#include "DFS.cpp"
#include "ImWriter.cpp"

using namespace std;

int main() {


    cout << "BEGINNING MAZE SOLVING" << endl;

    FileHandler parser;
    auto grid = parser.readFileToGrid("./../data/simple.txt");
    auto headAndTail = parser.createGraph(&grid);
    Solver* solver = new DFS();
    solver->solve(get<0>(headAndTail), get<1>(headAndTail), &grid);
    for(std::vector<int> row: grid) {
        for (int i : row)
            cout << i << " ";
        cout << endl;
    }
    //ImWriter* imWriter = new ImWriter();
    //imWriter->write()

    cout << "DONE" << endl;
    return 0;
}