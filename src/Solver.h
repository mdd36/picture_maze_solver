//
// Created by Matthew on 3/21/2018.
//

//using namespace std;

#include "GraphNode.h"

class Solver{
public:
    virtual std::vector<GraphNode*> solve(GraphNode* head, GraphNode* tail)= 0;
};
