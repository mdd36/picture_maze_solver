//
// Created by Matthew on 3/21/2018.
//

//using namespace std;

#include "GraphNode.h"

class Solver{
public:
    virtual void solve(GraphNode* head, GraphNode* tail, int*** grid)= 0;
    static const int RED = 3;

protected:
    void colorGrid(GraphNode* gn1, GraphNode* gn2, int*** grid){
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
    void paintLine(int **const *grid, int xMin, int yMin, int xMax, int yMax) const {
        while(xMin < xMax){
            *grid[xMin][yMin] = RED;
            ++xMin;
        }
        while(yMin < yMax){
            *grid[xMin][yMin] = RED;
            ++yMin;
        }
    };
};
