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
    std::vector<GraphNode*> solve(GraphNode* head, GraphNode* tail) override {
        cout << "Solving with DFS..." << endl;
        std::stack<GraphNode*> s;
        std::vector<GraphNode*> ret;
        s.push(head);
        while(!s.empty()){
            GraphNode* gn = s.top();
            ret.emplace_back(gn);
            s.pop();
            if(gn == tail)
                return ret;
            gn->visit(GraphNode::BLACK);
            pushNeighbors(gn, &s);
        }
        throw std::invalid_argument("Graph has no path to tail node");
    }

private:
    void pushNeighbors(GraphNode* gn, stack<GraphNode*>* s){
        for(std::pair<GraphNode*, GraphEdge> pair : gn->getNeighbors()){
            GraphNode* neighbor = pair.first;
            if(neighbor->getColor() == GraphNode::WHITE){
                s->push(neighbor);
                neighbor->visit(GraphNode::GRAY);
            }
        }
    }
};

