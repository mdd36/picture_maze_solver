//
// Created by Matthew on 3/10/2018.
//

#ifndef PICTURE_MAZE_SOLVER_EDGE_H
#define PICTURE_MAZE_SOLVER_EDGE_H

#include <list>
#include <iterator>
#include "GraphNode.h"

class GraphNode;

class GraphEdge {

public:
    GraphEdge(GraphNode* nodes, int weight);
    int getWeight();
    GraphNode* getNodes();

private:
    int weight;
    GraphNode* nodes;
};


#endif //PICTURE_MAZE_SOLVER_EDGE_H
