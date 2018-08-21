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

/**
 * Initialize the GraphNode
 * @param x x-coord
 * @param y y-coord
 * @param color starting color.
 */
void GraphNode::init(int x, int y, int color) {
    this->x = x;
    this->y = y;
    this->color = color;
    this->neighbors = *(new std::unordered_map<GraphNode*, GraphEdge>());
}

/**
 * @return Color of the this node.
 */
int GraphNode::getColor() {
    return color;
}

/**
 * Visit the node by popping it off the data structure and recoloring it
 * @param newColor WHITE (0), GRAY(1), BLACK(2)
 */
void GraphNode::visit(int newColor){
    this->color = newColor;
}

/**
 * Get edge connecthing this node to other. Raises an exception if none exits
 * @param other GraphNode on other side of edge
 * @return Edge connecting this and other
 * @throws invalid_argument if no such edge exists
 */
GraphEdge GraphNode::getEdgeWith(GraphNode* other) {
    GraphEdge ret = neighbors[other];
    if(&ret == nullptr) throw std::invalid_argument("Nodes don't share an edge.");
    return ret;
}

/**
 *
 * @param n GraphNode this is to share an edge with
 * @param e The edge representing this connection
 */
void GraphNode::addEdge(GraphNode* n, GraphEdge e){
    neighbors[n] = e;
}





