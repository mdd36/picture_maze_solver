//
// Created by Matthew on 3/21/2018.
//

//using namespace std;

#include "../graph/GraphNode.h"

class Solver{
public:
    virtual void solve(GraphNode* head, GraphNode* tail, std::vector<std::vector<int>>* grid)= 0;
    static const int RED = 2;

protected:

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
     * Paint the grid between two nodes
     * @param gn1 First node
     * @param gn2 Second node
     * @param grid Grid to paint on
     */
    void colorGrid(GraphNode* gn1, GraphNode* gn2, std::vector<std::vector<int>>* grid){
        int x1 = gn1->getCol();
        int y1 = gn1->getRow();
        int x2 = gn2->getCol();
        int y2 = gn2->getRow();
        int xMin = std::min(x1, x2);
        int yMin = std::min(y1, y2);
        int xMax = std::max(x1, x2);
        int yMax = std::max(y1, y2);
        paintLine(grid, xMin, yMin, xMax, yMax);
    }

private:
    /**
     * Paint the grid between two points
     * @param grid Grid to paint on
     * @param xMin Starting x
     * @param yMin Starting y
     * @param xMax Target x
     * @param yMax Target y
     */
    void paintLine(std::vector<std::vector<int>>* grid, int xMin, int yMin, int xMax, int yMax) const {
        if(xMin != xMax && yMin != yMax) throw new std::invalid_argument("One dimension must agree -- trying to paint diagonal");
        while(xMin < xMax){
            (*grid)[yMin][xMin] = RED;
            ++xMin;
        }
        while(yMin < yMax){
            (*grid)[yMin][xMin] = RED;
            ++yMin;
        }
        (*grid)[yMax][xMax] = RED;
    };
};
