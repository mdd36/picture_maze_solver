//
// Created by Matthew on 8/22/2018.
//

#pragma once
#include "../../graph/GraphNode.h"
#include "NodeComparator.h"

class DijkstraComparator : public NodeComparator{
public:
    int operator() (const GraphNode* gn1, const GraphNode* gn2) {
        return gn1->getDist() > gn2->getDist();
    }
};