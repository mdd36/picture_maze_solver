//
// Created by Matthew on 8/22/2018.
//

#include <cmath>
#include "NodeComparator.h"

class AStarComparator : public NodeComparator{

public:
    explicit AStarComparator(GraphNode* tail) : NodeComparator(){
        tailCol = tail->getCol();
        tailRow = tail->getRow();
    }

    int operator() (const GraphNode* gn1, const GraphNode* gn2) {
        return (gn1->getDist() > gn2->getDist()) + (calcDist(gn1) > calcDist(gn2));
    }

private:
    int tailRow;
    int tailCol;
    double calcDist(const GraphNode* gn1){
        return sqrt((gn1->getCol()-tailCol)*(gn1->getCol()-tailCol) + (gn1->getRow()-tailRow)*(gn1->getRow()-tailRow));
    }
};