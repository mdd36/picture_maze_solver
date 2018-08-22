//
// Created by Matthew on 3/10/2018.
//

#ifndef PICTURE_MAZE_SOLVER_NODE_H
#define PICTURE_MAZE_SOLVER_NODE_H

#include <list>
#include <iterator>
#include <set>
#include <unordered_map>
#include "GraphEdge.h"

class GraphNode {

public:
    static const int WHITE = 0;
    static const int GRAY = 1;
    static const int BLACK = 2;

    GraphNode(int x, int y, int color);
    GraphNode(int x, int y);
    GraphEdge getEdgeWith(GraphNode* other);
    int getColor();
    void visit(int state);
    void addEdge(GraphNode* n, GraphEdge e);

    int setDist(int dist) {distance = dist;};
    int getDist() const{return distance;};
    int getRow() const {return y;};
    int getCol() const {return x;};

    bool operator==(const GraphNode &other) const{
        return (this->x == other.x && this->y == other.y);
    };

    unsigned long operator()(const GraphNode& k) const {
        return (229 * ((((std::hash<int>()(k.getCol()))) ^ (std::hash<int>()(k.getRow()))) << 1)) % 743;
    }

    std::unordered_map<GraphNode*, GraphEdge> getNeighbors() const {
        std::unordered_map<GraphNode*, GraphEdge> ret = neighbors;
        return ret;
    };


private:
    void init(int x, int y, int color);
    std::unordered_map <GraphNode*, GraphEdge> neighbors;
    int color;
    int x;
    int y;
    int distance;
};



#endif //PICTURE_MAZE_SOLVER_NODE_H
