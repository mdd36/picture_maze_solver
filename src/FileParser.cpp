//
// Created by Matthew on 3/11/2018.
//

#include <fstream>
#include <sstream>
#include <vector>
#include "FileParser.h"

static GraphNode* FileParser::createGraph(char* fName) {
    vector<vector<int>> raw = parse(fName);
    GraphNode* lastInRow = nullptr;
    auto* lastInCol = (GraphNode**) malloc(raw[0].size() * sizeof(GraphNode*));
    for(int i = 0; i < raw.size(); ++i){
        for(int j = 0; j < raw[0].size(); ++j){
            if(raw[i][j] == 0){
                lastInRow = nullptr;
                lastInCol[j] = nullptr;
                continue;
            }
            if(raw[i][j+1] ^ raw[i][j-1]){
                place(i,j, lastInRow, lastInCol[j]);
            }else if(raw[i+1][j] ^ raw[i-1][j]){
                place(i,j, lastInRow, lastInCol[j]);
            }
            else if(raw[i+1][j] & raw[i-1][j] & raw[i][j+1] & raw[i][j-1]){
                place(i,j, lastInRow, lastInCol[j]);
            }
        }
        lastInRow = nullptr;
    }

    free(lastInCol);
    free(lastInRow);

}

static vector<vector<int>> FileParser::parse(char *fName) {
    fstream file(fName, ios::in);
    string line;
    vector<vector<int>> raw;
    int i = 0;
    while(getline(file, line)){
        int val;
        stringstream ss(line);
        raw.emplace_back();
        while(ss >> val){
            raw[i].push_back(val);
        }
        ++i;
    }
    return raw;
}

static void FileParser::place(int x, int y, GraphNode* lastInRow, GraphNode* lastInCol){
    auto* n1 = new GraphNode(x,y);
    if(!lastInRow){
        int weight = lastInRow->getCol() - n1->getCol();
        auto* e = new GraphEdge(n1, lastInRow, weight);
        n1->addEdge(e);
        lastInRow->addEdge(e);
        lastInRow = n1;
    }
    if(!lastInCol){ //Can probably be refactored into its own subroutine
        int weight = n1->getRow() - lastInCol->getRow();
        auto* e = new GraphEdge(n1, lastInCol, weight);
        n1->addEdge(e);
        lastInCol->addEdge(e);
        lastInCol = n1;
    }
}
