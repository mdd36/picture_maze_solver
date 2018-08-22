//
// Created by Matthew on 8/22/2018.
//

#include "Solver.h"
#include "Dijkstra.cpp"
#include "comparators/AStarComparator.cpp"

class AStar : public Solver{

    void solve(GraphNode* head, GraphNode* tail, std::vector<std::vector<int>>* grid) override {
        //Dijkstra::solve(new AStarComparator(tail), head, tail, grid);
    }

    std::string getTypeString() override {
        return "A*";
    }
};