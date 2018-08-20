//
// Created by Matthew on 3/11/2018.
//


typedef unsigned char unchar;

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <sstream>
#include "FileHandler.h"

const static std::string BW[] = {"(0,0,0)", "(255,255,255)"};


std::vector<std::vector<int>> FileHandler::readFileToGrid(const std::string &fname) {
    std::fstream file(fname);
    std::string line;
    std::vector<std::vector<int>> raw;
    while(getline(file, line)){
        std::vector<int> row;
        for(int j  = 0; j < line.size() - 1; ++j){
            char ch = line[j];
            int pixel = ch - '0';
            row.push_back(pixel);
        }
        raw.push_back(row); // Do this here since this action is by value, not reference
    }
    return raw;
}

/**
 * Build a graph represented by the file name. Nodes are placed only at 'decision points', or places where the maze
 * splits into multiple paths. Returns the head and tail of the graph for solving. Also builds the return data RGB
 * vector that will be written to a file as the solution.
 * @param fName Name of the file containing the maze.
 * @return The head and tail of the graph. Vector of RGB strings used when exporting the solution
 */
std::tuple<GraphNode*, GraphNode*> FileHandler::createGraph(std::vector<std::vector<int>>* grid) {
    GraphNode* head = nullptr;
    GraphNode* tail = nullptr;
    GraphNode* lastInRow = nullptr;
    GraphNode* lastInCol[grid[0].size()] ={nullptr};
    for(int i = 0; i < grid->size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            if((*grid)[i][j] == 0){ // If we found a wall
                lastInRow = nullptr;
                lastInCol[j] = nullptr;
                continue;
            }
            // Check bounds. If OoB, treat it as a wall. May not be needed since all mazes are bounded by walls
            int bottom = i+1 < grid->size() ? (*grid)[i+1][j] : 0;
            int top = i-1 < 0 ? 0 : (*grid)[i-1][j];
            int left = j-1 < 0 ? 0 : (*grid)[i][j-1];
            int right = j+1 < grid[0].size() ? (*grid)[i][j+1] : 0;
            if((left != right) || (top != bottom) || (top && bottom && left && right)){ // At a junction
                GraphNode* temp = place(j,i, &lastInRow, &lastInCol[j]);
                if(!head) head = temp;
                tail = temp; // Since tail is the last non-wall we visit
            }
        }
    }
    return std::make_tuple(head, tail);
}

/**
 * Place a  graph node at this (x,y) and connect it to adjacent nodes if no walls are between them
 * @param x X coord
 * @param y Y coord
 * @param lastInRow Last graph node seen in this row. If a wall was seen more recently than the last node, is nullptr
 * @param lastInCol Last graph node seen in this col. If a wall was seen more recently than the last node, is nullptr
 * @return The created graph node
 */
GraphNode* FileHandler::place(int x, int y, GraphNode** lastInRow, GraphNode** lastInCol){
    auto* n1 = new GraphNode(x,y);
    if(*lastInRow){
        int weight = (*lastInRow)->getCol() - n1->getCol();
        auto* e = new GraphEdge(weight);
        n1->addEdge(*lastInRow, *e);
        (*lastInRow)->addEdge(n1, *e);
    }
    if(*lastInCol){ //Can probably be refactored into its own subroutine
        int weight = n1->getRow() - (*lastInCol)->getRow();
        auto* e = new GraphEdge(weight);
        n1->addEdge(*lastInCol, *e);
        (*lastInCol)->addEdge(n1, *e);
    }
    *lastInRow = n1;
    *lastInCol = n1;
    return n1;
}

/**
 * Take an iterable data collection and concatinate it all into a string, seperated by the delim
 * @param v vector of data to be connected
 * @param delim String to be inserted between each entry of v
 * @return A string containing all values of v seperated by delim
 */
std::string FileHandler::join(std::vector<std::tuple<unchar, unchar, unchar>> v, const std::string &delim){
    std::stringstream ss;
    for(int i = 0; i < v.size(); ++i){
        // TODO Convert tuples to strings
        // ss << v[i];
        if(i != v.size()-1) ss << delim;
    }
    return ss.str();
}
