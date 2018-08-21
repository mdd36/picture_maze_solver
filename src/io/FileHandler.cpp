//
// Created by Matthew on 3/11/2018.
//

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <sstream>
#include "FileHandler.h"

/**
 * Export the solution stored in a grid to a file.
 * @param grid Solution determined by the solver
 * @param fname Output file name, without extension. Path set to output/txt/fname
 */
void FileHandler::writeGridToFile(std::vector<std::vector<int>> *grid, const std::string &fname) {
    std::cout << "Writing solution to file..." << std::endl;
    std::ofstream out ("./../output/txt/" + fname + ".txt", std::ios::trunc);
    for(const std::vector<int> &row: *grid) {
        out << join(row, ",") << std::endl;
    }
    out.close();
}

/**
 * Open and read the txt file of the maze into a grid of integers.
 * @param fname Filename, without extension. Searches in data folder.
 * @return vector<vector<int>> for the grid, 0 for wall and 1 for open.
 */
std::vector<std::vector<int>> FileHandler::readFileToGrid(const std::string &fname) {
    std::fstream file("./../input/" + fname + ".txt");
    std::string line;
    std::vector<std::vector<int>> raw;
    while(getline(file, line)){
        addLine(line, raw);
    }
    return raw;
}

/**
 * Read a line from the file into a vector of ints
 * @param line Line to be read
 * @param raw Vector of vectors for the grid
 */
void FileHandler::addLine(const std::string &line, std::vector<std::vector<int>> &raw) const {
    std::vector<int> row;
    for(int j  = 0; j < line.size() - 1; ++j){
            char ch = line[j];
            int pixel = ch - '0';
            row.push_back(pixel);
        }
    raw.push_back(row); // Do this here since this action is by value, not reference
}

/**
 * Build a graph represented by the grid. Nodes are placed only at 'decision points', or places where the maze
 * splits into multiple paths. Returns the head and tail of the graph for solving.
 * @param grid Pointer to the vector grid.
 * @return The head and tail of the graph.
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
            placeAndSetNeighbors(grid, lastInRow, lastInCol, i, j, head, tail);
        }
    }
    return std::make_tuple(head, tail);
}

/**
 * Check if this location is a decision point, and place a GraphNode if it is.
 * @param grid Grid of ints used to build the grid
 * @param lastInRow Last GraphNode seen in this row
 * @param lastInCol Array of GraphNode* to represent the last GraphNode seen in each column
 * @param i Row index of potential node
 * @param j Column index of potential node
 * @param head First node placed in the graph representing the starting point
 * @param tail Last node placed in the graph, representing the exit of the maze
 */
void FileHandler::placeAndSetNeighbors(const std::vector<std::vector<int>> *grid, GraphNode *&lastInRow,
                                       GraphNode** lastInCol, int i, int j, GraphNode *&head, GraphNode *&tail) {
    // Check bounds. If OoB, treat it as a wall. May not be needed since all mazes are bounded by walls
    int bottom = i+1 < grid->size() ? (*grid)[i+1][j] : 0;
    int top = i-1 < 0 ? 0 : (*grid)[i-1][j];
    int left = j-1 < 0 ? 0 : (*grid)[i][j-1];
    int right = j+1 < grid[0].size() ? (*grid)[i][j+1] : 0;
    if((left != right) || (top != bottom) || (top && bottom && left && right)){ // At a junction
        GraphNode* temp = place(j, i, &lastInRow, &lastInCol[j]);
        if(!head) head = temp;
        tail = temp; // Since tail is the last non-wall we visit
    }
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
 * Take an iterable data collection and concatenate it all into a string, seperated by the delim
 * @param v vector of data to be connected
 * @param delim String to be inserted between each entry of v
 * @return A string containing all values of v seperated by delim
 */
std::string FileHandler::join(std::vector<int> v, const std::string &delim){
    std::stringstream ss;
    for(int i = 0; i < v.size(); ++i){
        ss << v[i];
        if(i != v.size()-1) ss << delim;
    }
    return ss.str();
}
