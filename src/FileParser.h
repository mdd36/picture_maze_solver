//
// Created by Matthew on 3/11/2018.
//

#ifndef PICTURE_MAZE_SOLVER_FILEPARSER_H
#define PICTURE_MAZE_SOLVER_FILEPARSER_H


#include <vector>
#include "GraphNode.h"

class FileParser {

public:
    GraphNode* createGraph(char* fName);

private:
    vector<vector<int>> parse(char* fName);
    void place(int x, int y, GraphNode* lastInRow, GraphNode* lastInCol);
};


#endif //PICTURE_MAZE_SOLVER_FILEPARSER_H
