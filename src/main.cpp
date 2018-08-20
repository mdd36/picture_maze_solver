#include <iostream>
#include <tuple>
#include "FileParser.h"
#include "DFS.cpp"
#include "ImWriter.cpp"

using namespace std;

int main() {


    cout << "BEGINNING MAZE SOLVING" << endl;

    auto parser = new FileParser();
    auto headAndTail = parser->createGraph("./../data/simple.txt");
    Solver* solver = new DFS();
    solver->solve(get<0>(headAndTail), get<1>(headAndTail), &grid);
    //ImWriter* imWriter = new ImWriter();
    //imWriter->write()

    cout << "DONE" << endl;
    return 0;
}