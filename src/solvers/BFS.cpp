//
// Created by Matthew on 8/22/2018.
//

#include <iostream>
#include <queue>
#include "Solver.h"

class BFS : public Solver{

public:
    /**
     * Solve the maze by running BFS on the graph.
     * @param head Starting node
     * @param tail Target node
     * @param grid Grid to color as the search occurs
     */
    void solve(GraphNode* head, GraphNode* tail, std::vector<std::vector<int>>* grid) override {
        std::cout << "Solving with BFS..." << std::endl;
        std::queue<GraphNode*> q;
        q.push(head);
        while(!q.empty()){
            GraphNode* top = processesTop(grid, &q);
            if(top == tail) return;
        }
        throw std::invalid_argument("Graph has no path to tail node");
    }

    /**
     * @return String for the type of solver used
     */
    std::string getTypeString() override {
        return "BFS";
    }

private:

    /**
     * Take the top node off the queue, paint the grid, and push its unvisited neighbors
     * @param grid Return grid to paint
     * @param q Queue used in the BFS
     * @return Graph node popped off the top of the queue
     */
    GraphNode* processesTop(std::vector<std::vector<int>>* grid, std::queue<GraphNode*>* q){
        GraphNode* top = q->front();
        q->pop();
        paint(grid, top);
        top->visit(GraphNode::BLACK);
        pushNeighbors(top, q);
        return top;
    }

    /**
     * Push all the neighbors of a graph node to the stack.
     * @param gn GraphNode whose neighbors to push
     * @param q Pointer to the queue to push the neighbors onto
     */
    void pushNeighbors(GraphNode* gn, std::queue<GraphNode*>* q){
        for(std::pair<GraphNode*, GraphEdge> pair : gn->getNeighbors()){
            GraphNode* neighbor = pair.first;
            if(neighbor->getColor() == GraphNode::WHITE){
                q->push(neighbor);
                if(parents.find(neighbor) == parents.end())
                    parents[neighbor] = new std::list<GraphNode*>;
                parents[neighbor]->emplace_back(gn);
            }
        }
    }

};