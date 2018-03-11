//
// Created by Matthew on 3/10/2018.
//

#ifndef PICTURE_MAZE_SOLVER_NODE_H
#define PICTURE_MAZE_SOLVER_NODE_H

#include <list>
#include <iterator>
#include "GraphEdge.h"

using namespace std;

class GraphEdge;

class GraphNode {

public:
    GraphNode(int x, int y, int color);
    GraphNode(int x, int y);
    void setEdges(list <GraphEdge>* connections);
    list<GraphEdge> getEdges();
    void setColor(int newColor);
    int getColor();
    bool wasSeen();

private:
    void init(int x, int y, int color);
    list <GraphEdge> neighbors;
    int color;
    int x;
    int y;
    bool seen;
};


#endif //PICTURE_MAZE_SOLVER_NODE_H
