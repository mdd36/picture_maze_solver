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
    state = 0;
}

void GraphNode::setEdges(list<GraphEdge>* connections) {
    neighbors = *connections;
}

int GraphNode::getColor() {
    return color;
}

int GraphNode::wasSeen() {
    return state;
}

void GraphNode::visit(int state){
    this->state = state;
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

void GraphNode::addEdge(GraphEdge* e){
    neighbors.push_back(*e);
}

int GraphNode::getRow(){
    return y;
}

int GraphNode::getCol(){
    return x;
}

#include "GraphNode.h"
