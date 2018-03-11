//
// Created by Matthew on 3/11/2018.
//

#ifndef PICTURE_MAZE_SOLVER_FILEPARSER_H
#define PICTURE_MAZE_SOLVER_FILEPARSER_H


#include "GraphNode.h"

class FileParser {

public:
    static GraphNode* createGraph(char* fName);

private:
    static vector<vector<int>> parse(char* fName);
    static void place(int x, int y);
};


#endif //PICTURE_MAZE_SOLVER_FILEPARSER_H
