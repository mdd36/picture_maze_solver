//
// Created by Matthew on 3/10/2018.
//

#ifndef PICTURE_MAZE_SOLVER_NODE_H
#define PICTURE_MAZE_SOLVER_NODE_H

#include <list>
#include <iterator>
#include <set>
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
    int wasSeen();
    void visit(int state);
    void addEdge(GraphEdge* e);
    int getRow();
    int getCol();

private:
    void init(int x, int y, int color);
    list <GraphEdge> neighbors;
    int color;
    int x;
    int y;
    int state;
};


#endif //PICTURE_MAZE_SOLVER_NODE_H
