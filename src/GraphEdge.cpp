//
// Created by Matthew on 3/10/2018.
//

#include "GraphEdge.h"
#include <cmath>

GraphEdge::GraphEdge(GraphNode *nodes, int weight) {
    this->nodes = nodes;
    this->weight = weight;
}

int GraphEdge::getWeight() {
    return weight;
}

GraphNode* GraphEdge::getNodes() {
    auto* ret = (GraphNode*) malloc(2 * sizeof(GraphNode));
    ret[0] = nodes[0];
    ret[1] = nodes[1];
    return ret;
}


