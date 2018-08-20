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
#include "FileParser.h"

using namespace std;

const static string BW[] = {"(0,0,0)", "(255,255,255)"};

/**
 * Build a graph represented by the file name. Nodes are placed only at 'decision points', or places where the maze
 * splits into multiple paths. Returns the head and tail of the graph for solving. Also builds the return data RGB
 * vector that will be written to a file as the solution.
 * @param fName Name of the file containing the maze.
 * @return The head and tail of the graph. Vector of RGB strings used when exporting the solution
 */
tuple<GraphNode*, GraphNode*, vector<vector<string>>> FileParser::createGraph(char* fName) {
    auto parsed = parse(fName);
    vector<vector<int>> raw = static_cast<vector<vector<int>> &&>(get<0>(parsed));
    vector<vector<string>> rgb = static_cast<vector<vector<string>> &&>(get<1>(parsed));
    GraphNode* head = nullptr;
    GraphNode* tail = nullptr;
    GraphNode* lastInRow = nullptr;
    GraphNode* lastInCol[raw[0].size()] ={nullptr};
    for(int i = 0; i < raw.size(); ++i){
        for(int j = 0; j < raw[0].size(); ++j){
            if(raw[i][j] == 0){ // If we found a wall
                lastInRow = nullptr;
                lastInCol[j] = nullptr;
                continue;
            }
            // Check bounds. If OoB, treat it as a wall. May not be needed since all mazes are bounded by walls
            int bottom = i+1 < raw.size() ? raw[i+1][j] : 0;
            int top = i-1 < 0 ? 0 : raw[i-1][j];
            int left = j-1 < 0 ? 0 : raw[i][j-1];
            int right = j+1 < raw[0].size() ? raw[i][j+1] : 0;
            if((left != right) || (top != bottom) || (top && bottom && left && right)){ // At a junction
                GraphNode* temp = place(j,i, &lastInRow, &lastInCol[j]);
                if(!head) head = temp;
                tail = temp; // Since tail is the last non-wall we visit
            }
        }
    }
    return make_tuple(head, tail, rgb);
}

/**
 * Write the RGB tuples from the solved maze to the output file
 * @param data List of RGB tuples from solving the maze
 */
void FileParser::write(vector<vector<tuple<unchar, unchar, unchar>>> data) {
    ofstream outfile ("./../resources/temp.txt");
    for(const vector<tuple<unchar, unchar, unchar>> &row : data){
        outfile << join(row, ",") << endl;
    }
    outfile.close();
}

/**
 * Read the file pixel by pixel and build a temporary list of 1's and 0's to represent it
 * @param fName Name of the file opened
 * @return A vector of ints used to build the graph and a vector of strings used to export the solution later
 */
tuple<vector<vector<int>>, vector<vector<string>>> FileParser::parse(char *fName) {
    fstream file(fName);
    string line;
    vector<vector<int>> raw;
    vector<vector<string>> rgb;
    int i = 0;
    while(getline(file, line)){
        raw.push_back(*(new vector<int>));
        rgb.push_back(*(new vector<string>));
        for(int j  = 0; j < line.size() - 1; ++j){
            char ch = line[j];
            int pixel = ch - '0';
            raw[i].push_back(pixel);
            if(j == line.size()-2) rgb[i].push_back(BW[pixel]);
            else rgb[i].push_back(BW[pixel] + ",");
        }
        ++i;
    }
    return make_tuple(raw, rgb);
}

/**
 * Place a  graph node at this (x,y) and connect it to adjacent nodes if no walls are between them
 * @param x X coord
 * @param y Y coord
 * @param lastInRow Last graph node seen in this row. If a wall was seen more recently than the last node, is nullptr
 * @param lastInCol Last graph node seen in this col. If a wall was seen more recently than the last node, is nullptr
 * @return The created graph node
 */
GraphNode* FileParser::place(int x, int y, GraphNode** lastInRow, GraphNode** lastInCol){
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
string FileParser::join(vector<tuple<unchar, unchar, unchar>> v, const string &delim){
    stringstream ss;
    for(int i = 0; i < v.size(); ++i){
        // TODO Convert tuples to strings
        // ss << v[i];
        if(i != v.size()-1) ss << delim;
    }
    return ss.str();
}
