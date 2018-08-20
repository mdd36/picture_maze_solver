//
// Created by Matthew on 3/11/2018.
//

#ifndef PICTURE_MAZE_SOLVER_FILEPARSER_H
#define PICTURE_MAZE_SOLVER_FILEPARSER_H


#include <vector>
#include "GraphNode.h"

typedef unsigned char unchar;
using namespace std;
class FileParser {

public:
    tuple<GraphNode*, GraphNode*, vector<vector<string>>> createGraph(char* fName);
    void write(vector<vector<tuple<unchar, unchar, unchar>>> data);

private:
    tuple<vector<vector<int>>, vector<vector<string>>> parse(char* fName);
    GraphNode* place(int x, int y, GraphNode* lastInRow, GraphNode* lastInCol);
    std::string join(std::vector<tuple<unchar, unchar, unchar>> v, const std::string &delim);
};


#endif //PICTURE_MAZE_SOLVER_FILEPARSER_H
