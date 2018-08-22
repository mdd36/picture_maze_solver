//
// Created by Matthew on 8/22/2018.
//

#include <iostream>
#include "Solver.h"
#include "comparators/AStarComparator.cpp"

class AStar : public Solver{

    /**
     * Solve with A*
     * @param head Starting node in the graph
     * @param tail Target node in the graph
     * @param grid Grid to color
     */
    void solve(GraphNode* head, GraphNode* tail, std::vector<std::vector<int>>* grid) override {
        std::cout << "Solving with A*..." << std::endl;
        AStarComparator comp(tail);
        std::priority_queue<GraphNode*, std::vector<GraphNode*>, AStarComparator> pq(comp);
        head->setDist(0);
        pq.push(head);
        while(!pq.empty()){
            GraphNode* top = processTop(grid, &pq);
            if(top == tail){
                paintSolutionPath(grid, tail);
                return;
            }
        }
        throw std::invalid_argument("Graph has no path to tail node");
    }
    // Get type sting
    std::string getTypeString() override {
        return "AStar";
    }
private:

    GraphNode* processTop(std::vector<std::vector<int>>* grid,
                          std::priority_queue<GraphNode*, std::vector<GraphNode*>, AStarComparator>* pq){
        GraphNode* top = pq->top();
        pq->pop();
        paint(grid, top);
        pushNeighbors(top, pq);
        return top;
    }

    void pushNeighbors(GraphNode* top, std::priority_queue<GraphNode*, std::vector<GraphNode*>, AStarComparator>* pq){
        for(std::pair<GraphNode*, GraphEdge> pair : top->getNeighbors()){
            GraphNode* neighbor = pair.first;
            int neighborDist = top->getDist() + top->getEdgeWith(neighbor).getWeight();
            if(neighborDist < neighbor->getDist()){
                neighbor->setDist(neighborDist);
                pq->push(neighbor);
                if(parents.find(neighbor) == parents.end())
                    parents[neighbor] = new std::list<GraphNode*>;
                parents[neighbor]->emplace_back(top);
            }
        }
    }
};