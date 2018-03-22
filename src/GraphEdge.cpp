//
// Created by Matthew on 3/10/2018.
//

#include "GraphEdge.h"
#include <cmath>

GraphEdge::GraphEdge(GraphNode *nodes, int weight) {
    this->nodes = nodes;
    this->weight = weight;
}

GraphEdge::GraphEdge(GraphNode* n1, GraphNode* n2, int weight) {
    this->nodes = (GraphNode*) malloc(2 * sizeof(GraphNode));
    *nodes = *n1;
    *(nodes + 1) = *n2;
    this->weight = weight;
}

int GraphEdge::getWeight() {
    return weight;
}

GraphNode* GraphEdge::getNodes() {
    auto* ret = (GraphNode*) malloc(2 * sizeof(GraphNode));
    *ret = *nodes;
    *(ret + 1) = *(nodes + 1);
    return ret;
}

GraphEdge::~GraphEdge() {
    free(nodes);
}