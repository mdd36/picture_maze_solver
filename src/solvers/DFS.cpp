//
// Created by Matthew on 3/21/2018.
//

#include <stack>
#include <vector>
#include <tuple>
#include <iostream>
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
            GraphNode* top = processTop(grid, &s);
            if(top == tail){
                paintSolutionPath(grid, tail);
                return;
            }
        }
        throw std::invalid_argument("Graph has no path to tail node");
    }

    /**
     * @return String for the type of solver used
     */
    std::string getTypeString() override {
        return "DFS";
    }

    /**
     * Take the top node off the stack, paint the grid, and push its unvisited neighbors
     * @param grid Return grid to paint
     * @param s Queue used in the stack
     * @return Graph node popped off the top of the queue
     */
    GraphNode* processTop(std::vector<std::vector<int>> *grid, std::stack<GraphNode *> *s) {
        GraphNode* gn = s->top();
        s->pop();
        paint(grid, gn);
        gn->visit(GraphNode::BLACK);
        pushNeighbors(gn, s);
        return gn;
    }

private:
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
            }
        }
    }
};

