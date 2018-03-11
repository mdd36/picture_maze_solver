//
// Created by Matthew on 3/11/2018.
//

#include <fstream>
#include <sstream>
#include <vector>
#include "FileParser.h"

static GraphNode* FileParser::createGraph(char* fName) {
    vector<vector<int>> raw = parse(fName);
    for(int i = 0; i < raw[0].size(); ++i){
        for(int j = 0; j < raw.size(); ++j){
            if(raw[i][j] == 0) continue;
            if(raw[i][j+1] ^ raw[i][j-1]){

            }else if(raw[i+1][j] ^ raw[i-1][j]){

            }
            else if(raw[i+1][j] & raw[i-1][j] & raw[i][j+1] & raw[i][j-1]){

            }
        }
    }

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

static void FileParser::place(int x, int y){
    GraphNode n1 = new GraphNode(x,y);
}
