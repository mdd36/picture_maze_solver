//
// Created by Matthew on 3/10/2018.
//

#include "GraphEdge.h"
#include <cmath>

GraphEdge::GraphEdge(){
    this->weight = -1;
}

GraphEdge::GraphEdge(int weight) {
    this->weight = weight;
}

int GraphEdge::getWeight() {
    return weight;
}