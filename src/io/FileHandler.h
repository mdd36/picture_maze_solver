//
// Created by Matthew on 3/11/2018.
//

#ifndef PICTURE_MAZE_SOLVER_FILEPARSER_H
#define PICTURE_MAZE_SOLVER_FILEPARSER_H


#include <vector>
#include "../graph/GraphNode.h"

typedef unsigned char unchar;
class FileHandler {

public:
    std::vector<std::vector<int>> readFileToGrid(const std::string &fname);
    std::tuple<GraphNode*, GraphNode*> createGraph(std::vector<std::vector<int>>* grid);
    void writeGridToFile(std::vector<std::vector<int>>* grid, const std::string &fname);

private:
    GraphNode* place(int x, int y, GraphNode** lastInRow, GraphNode** lastInCol);
    std::string join(std::vector<int> v, const std::string &delim);
};


#endif //PICTURE_MAZE_SOLVER_FILEPARSER_H
