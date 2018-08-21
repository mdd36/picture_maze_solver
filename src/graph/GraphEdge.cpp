//
// Created by Matthew on 3/10/2018.
//

#include "GraphEdge.h"

/**
 * Default constructor for unordered_map
 */
GraphEdge::GraphEdge(){
    this->weight = -1;
}

/**
 * @param weight starting weight of this edge
 */
GraphEdge::GraphEdge(int weight) {
    this->weight = weight;
}

/**
 * @return weight of this edge
 */
int GraphEdge::getWeight() {
    return weight;
}