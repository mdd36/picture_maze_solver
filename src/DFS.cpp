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
    void solve(GraphNode* head, GraphNode* tail, std::vector<std::vector<int>>* grid) override {
        std::cout << "Solving with DFS..." << std::endl;
        std::stack<GraphNode*> s;
        s.push(head);
        while(!s.empty()){
            GraphNode* gn = s.top();
            s.pop();
            if(gn == tail) {
                return;
            }
            gn->visit(GraphNode::BLACK);
            pushNeighbors(gn, &s);
            for(GraphNode* parent : parents[gn])
                colorGrid(gn, parent, grid);
        }
        throw std::invalid_argument("Graph has no path to tail node");
    }

protected:

private:
    std::unordered_map<GraphNode*, std::list<GraphNode*>*> parents;

    void pushNeighbors(GraphNode* gn, std::stack<GraphNode*>* s){
        for(std::pair<GraphNode*, GraphEdge> pair : gn->getNeighbors()){
            GraphNode* neighbor = pair.first;
            if(neighbor->getColor() == GraphNode::WHITE){
                s->push(neighbor);
                neighbor->visit(GraphNode::GRAY);
                if(parents.find(neighbor) == parents.end)
                    parents[neighbor] = new std::list<GraphNode*>;
                parents[neighbor]->emplace_back(gn);
            }
        }
    }
};

