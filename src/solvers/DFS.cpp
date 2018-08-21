//
// Created by Matthew on 3/21/2018.
//

#include <stack>
#include <vector>
#include <tuple>
#include "Solver.h"
#include "../graph/GraphNode.h"

class DFS : public Solver{
public:
    /**
     * Solve the maze by running DFS on the graph.
     * @param head Starting node
     * @param tail Target node
     * @param grid Grid to color as the search occurs
     */
    void solve(GraphNode* head, GraphNode* tail, std::vector<std::vector<int>>* grid) override {
        std::cout << "Solving with DFS..." << std::endl;
        std::stack<GraphNode*> s;
        s.push(head);
        while(!s.empty()){
            GraphNode* gn = s.top();
            s.pop();
            paint(grid, gn);
            if(gn == tail) return;
            gn->visit(GraphNode::BLACK);
            pushNeighbors(gn, &s);
        }
        throw std::invalid_argument("Graph has no path to tail node");
    }

private:
    std::unordered_map<GraphNode*, std::list<GraphNode*>*> parents;

    /**
     * Paint connections from this node to all its parents.
     * @param grid Pointer to grid to paint on
     * @param gn Pointer to the GraphNode to draw paths
     */
    void paint(std::vector<std::vector<int>>* grid, GraphNode* gn) {
        if(parents[gn] != nullptr)  // If we have parent, ie aren't head
            for (auto it = parents[gn]->begin(); it != parents[gn]->end(); ++it)
                colorGrid(gn, *it, grid);
    }

    /**
     * Push all the neighbors of a graph node to the stack.
     * @param gn GraphNode whose neighbors to push
     * @param s Pointer to the stack to push the neighbors onto
     */
    void pushNeighbors(GraphNode* gn, std::stack<GraphNode*>* s){
        for(std::pair<GraphNode*, GraphEdge> pair : gn->getNeighbors()){
            GraphNode* neighbor = pair.first;
            if(neighbor->getColor() == GraphNode::WHITE){
                s->push(neighbor);
                neighbor->visit(GraphNode::GRAY);
                if(parents.find(neighbor) == parents.end())
                    parents[neighbor] = new std::list<GraphNode*>;
                parents[neighbor]->emplace_back(gn);
                auto l = parents[neighbor]->begin();
                for(; l != parents[neighbor]->end(); ++l)
                    std::cout<<*l<<std::endl;
                std::cout << "";
            }
        }
    }
};

