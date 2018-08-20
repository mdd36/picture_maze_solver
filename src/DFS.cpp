//
// Created by Matthew on 3/21/2018.
//

#include <stack>
#include <vector>
#include <tuple>
#include "Solver.h"
#include "GraphNode.h"

class DFS : public Solver{
public:
    void solve(GraphNode* head, GraphNode*) override {
        cout << "Solving with DFS..." << endl;
    }
};

