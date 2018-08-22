//
// Created by Matthew on 8/22/2018.
//

#ifndef PICTURE_MAZE_SOLVER_NODECOMPARATOR_H
#define PICTURE_MAZE_SOLVER_NODECOMPARATOR_H

#include "../../graph/GraphNode.h"

class NodeComparator{
public:
    int operator() (const GraphNode* gn1, const GraphNode* gn2){
        return 0;
    };
};
#endif //PICTURE_MAZE_SOLVER_NODECOMPARATOR_H
