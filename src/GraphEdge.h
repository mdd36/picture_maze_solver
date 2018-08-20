//
// Created by Matthew on 3/10/2018.
//

#ifndef PICTURE_MAZE_SOLVER_EDGE_H
#define PICTURE_MAZE_SOLVER_EDGE_H

#include <list>
#include <iterator>


class GraphEdge {

public:
    GraphEdge();
    explicit GraphEdge(int weight);
    int getWeight();

private:
    int weight;
};


#endif //PICTURE_MAZE_SOLVER_EDGE_H
