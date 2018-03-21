//
// Created by Matthew on 3/11/2018.
//

#include <fstream>
#include <vector>
#include <iostream>
#include "FileParser.h"

GraphNode* FileParser::createGraph(char* fName) {
    vector<vector<int>> raw = parse(fName);
    vector<vector<int>> ret;
    GraphNode* lastInRow = nullptr;
    auto* lastInCol = (GraphNode**) malloc(raw[0].size() * sizeof(GraphNode*));
    for(int i = 0; i < raw.size(); i++){
        ret.push_back(*(new vector<int>));
        cout << i << endl;
        for(int j = 0; j < raw[0].size(); j++){
            ret[i].push_back(raw[i][j]);
            if(raw[i][j] == 0){
                lastInRow = nullptr;
                lastInCol[j] = nullptr;
                continue;
            }
            int top = i+1 < raw.size() ? raw[i+1][j] : 0;
            int bottom = i-1 < 0 ? 0 : raw[i-1][j];
            int left = j-1 < 0 ? 0 : raw[i][j-1];
            int right = j+1 < raw[0].size() ? raw[i][j+1] : 0;



            if((left ^ right) || (top ^ bottom) || (top && bottom && left && right)){
                place(j,i, lastInRow, lastInCol[j]);
                //cout << "hello there!" << endl;
                cout << "top ^ bottom is " << (top ^ bottom) << endl;
                cout << "right ^ left is " << (left ^ right) << endl;
                cout << "is four way is " << (top && bottom && left && right) << endl;
                ret[i][j] = 2;
            }
        }
        //Not needed since all mazes are bounded in walls, so it gets reset anyway
        //lastInRow = nullptr;
    }
    free(lastInCol);
    free(lastInRow);

    ofstream outfile("./../data/modified.txt");
    for(auto row : ret) {
        for (int val : row)
            outfile << val;
        outfile << endl;
    }

}

vector<vector<int>> FileParser::parse(char *fName) {
    fstream file(fName);
    string line;
    vector<vector<int>> raw;
    int i = 0;
    while(getline(file, line)){
        raw.push_back(*(new vector<int>));
        for(int j  = 0; j < line.size() - 1; ++j){
            char ch = line[j];
            raw[i].push_back(ch - '0');
        }
        ++i;
    }
    return raw;
}

void FileParser::place(int x, int y, GraphNode* lastInRow, GraphNode* lastInCol){
    auto* n1 = new GraphNode(x,y);
    if(lastInRow){
        int weight = lastInRow->getCol() - n1->getCol();
        auto* e = new GraphEdge(n1, lastInRow, weight);
        n1->addEdge(e);
        lastInRow->addEdge(e);
        lastInRow = n1;
    }
    if(lastInCol){ //Can probably be refactored into its own subroutine
        int weight = n1->getRow() - lastInCol->getRow();
        auto* e = new GraphEdge(n1, lastInCol, weight);
        n1->addEdge(e);
        lastInCol->addEdge(e);
        lastInCol = n1;
    }
}
