//
// Created by Matthew on 3/10/2018.
//

#include "GraphNode.h"

GraphNode::GraphNode(int x, int y, int color){
   init(x,y,color);
}

GraphNode::GraphNode(int x, int y) {
    init(x,y,1);
}

void GraphNode::init(int x, int y, int color) {
    this->x = x;
    this->y = y;
    this->color = color;
    seen = false;
}

void GraphNode::setEdges(list<GraphEdge>* connections) {
    neighbors = *connections;
}

int GraphNode::getColor() {
    return color;
}

bool GraphNode::wasSeen() {
    return seen;
}

void GraphNode::setColor(int newColor) {
    color = newColor;
}

list<GraphEdge> GraphNode::getEdges() {
    list<GraphEdge> ret;
    for(GraphEdge e : neighbors){
        ret.push_back(*(new GraphEdge(e.getNodes(), e.getWeight())));
    }
    return ret;
}

#include "GraphNode.h"
