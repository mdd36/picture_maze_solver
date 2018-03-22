//
// Created by Matthew on 3/21/2018.
//

#include <stack>
#include <vector>
#include <tuple>
#include "Solver.cpp"

static const int POPPED = 2;
static const int ON_STACK = 1;
static const int NOT_SEEN = 0;
using namespace std;

class DFS : public Solver{

public:
    void solve(GraphNode* head, GraphNode* tail) override {
        auto s = new stack<GraphNode*>();
        vector<tuple<int, int>> visited;
        s->push(head);

        while(!s->empty()){
            GraphNode* node = s->top();
            node->visit(POPPED);

            visited.push_back(make_tuple(node->getCol(), node->getRow()));
            if(node == tail){
                return;
            }

            for(GraphEdge e : node->getEdges()){
                GraphNode* adjNodes = e.getNodes();
                if(adjNodes == node && ((adjNodes+1)->wasSeen() == NOT_SEEN)){
                    s->push(adjNodes+1);
                    (adjNodes+1)->visit(ON_STACK);
                }else if((adjNodes + 1) == node && (adjNodes->wasSeen() == NOT_SEEN)){
                    s->push(adjNodes);
                    adjNodes->visit(ON_STACK);
                }
            }
            s->pop();
        }

    }

};

