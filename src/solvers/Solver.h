//
// Created by Matthew on 3/21/2018.
//

#pragma once
#include "../graph/GraphNode.h"
#include <vector>

class Solver{
public:
    virtual void solve(GraphNode* head, GraphNode* tail, std::vector<std::vector<int>>* grid)= 0;
    virtual std::string getTypeString()= 0;
    static const int RED = 2;
    static const int BLUE = 3;

protected:

    std::unordered_map<GraphNode*, std::list<GraphNode*>*> parents;

    /**
     * Paint connections from this node to all its parents.
     * @param color Color to paint on the grid. 2 for RED, 3 for BLUE
     * @param grid Pointer to grid to paint on
     * @param gn Pointer to the GraphNode to draw paths
     */
    void paint(int color, std::vector<std::vector<int>>* grid, GraphNode* gn) {
        if(parents[gn] != nullptr)  // If we have parent, ie aren't head
            for (auto it = parents[gn]->begin(); it != parents[gn]->end(); ++it)
                colorGrid(color, gn, *it, grid);
    }

    /**
     * Overload of paint to use RED to color the grid.
     * @param grid Pointer to grid to paint on
     * @param gn Pointer to the GraphNode to draw paths
     */
    [[deprecated]]
    void paint(std::vector<std::vector<int>>* grid, GraphNode* gn) {
        paint(RED, grid, gn);
    }

    /**
     * Paint the grid between two nodes
     * @param color Color to paint on the grid. 2 for RED, 3 for BLUE
     * @param gn1 First node
     * @param gn2 Second node
     * @param grid Grid to paint on
     */
    void colorGrid(int color, GraphNode* gn1, GraphNode* gn2, std::vector<std::vector<int>>* grid){
        int x1 = gn1->getCol();
        int y1 = gn1->getRow();
        int x2 = gn2->getCol();
        int y2 = gn2->getRow();
        int xMin = std::min(x1, x2);
        int yMin = std::min(y1, y2);
        int xMax = std::max(x1, x2);
        int yMax = std::max(y1, y2);
        paintLine(color, grid, xMin, yMin, xMax, yMax);
    }

    void paintSolutionPath(std::vector<std::vector<int>>* grid, GraphNode* tail){
        std::queue<GraphNode*> q;
        q.push(tail);
        while(!q.empty()){
            GraphNode* gn = q.front();
            q.pop();
            if(parents[gn]) {
                GraphNode *parent = parents[gn]->back();
                colorGrid(BLUE, gn, parent, grid);
                q.push(parent);
            }
        }
    }

private:
    /**
     * Paint the grid between two points
     * @param color Color to paint on the grid. 2 for RED, 3 for BLUE
     * @param grid Grid to paint on
     * @param xMin Starting x
     * @param yMin Starting y
     * @param xMax Target x
     * @param yMax Target y
     */
    void paintLine(int color, std::vector<std::vector<int>>* grid, int xMin, int yMin, int xMax, int yMax) const {
        if(xMin != xMax && yMin != yMax) throw std::invalid_argument("One dimension must agree -- trying to paint diagonal");
        (*grid)[yMin][xMin] = color;
        while(xMin < xMax){
            (*grid)[yMin][xMin] = color;
            ++xMin;
        }
        while(yMin < yMax){
            (*grid)[yMin][xMin] = color;
            ++yMin;
        }
        (*grid)[yMax][xMax] = color;
    };
};

//struct Colors{
//    static int RED = 2;
//    static int BLUE = 3;
//};