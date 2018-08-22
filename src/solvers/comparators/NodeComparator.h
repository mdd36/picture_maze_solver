//
// Created by Matthew on 8/22/2018.
//

#ifndef PICTURE_MAZE_SOLVER_NODECOMPARATOR_H
#define PICTURE_MAZE_SOLVER_NODECOMPARATOR_H

#include "../../graph/GraphNode.h"

class NodeComparator{
public:
    /**
     * Compare the GraphNodes to put then into ascending order by some metric
     * @param gn1 First graph node
     * @param gn2 Second graph node
     * @return -1, 0, or 1 if the gn1 is less than, equal to, or greater than gn2
     */
    virtual int operator() (const GraphNode* gn1, const GraphNode* gn2) = 0;
};
#endif //PICTURE_MAZE_SOLVER_NODECOMPARATOR_H
