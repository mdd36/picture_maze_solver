//
// Created by Matthew on 3/10/2018.
//

#include <iostream>
#include "GraphNode.h"

GraphNode::GraphNode(int x, int y, int color){
   init(x,y,color);
}

GraphNode::GraphNode(int x, int y) {
    init(x,y,WHITE);
}

void GraphNode::init(int x, int y, int color) {
    this->x = x;
    this->y = y;
    this->color = color;
    this->neighbors = *(new std::unordered_map<GraphNode*, GraphEdge>());
}

int GraphNode::getColor() {
    return color;
}

void GraphNode::visit(int newColor){
    this->color = newColor;
}

GraphEdge GraphNode::getEdgeWith(GraphNode* other) {
    return neighbors[other];
}

void GraphNode::addEdge(GraphNode* n, GraphEdge e){
    neighbors[n] = e;
}





