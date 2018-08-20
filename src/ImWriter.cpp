//
// Created by Matthew on 3/21/2018.
//

typedef unsigned char unchar;

unchar const S_R = 0;
unchar const S_B = 255;

unchar const E_R = 255;
unchar const E_B = 0;

#include <tuple>
#include <list>
#include <fstream>
#include <vector>
#include <sstream>

class ImWriter{
public:
    void write(list<tuple<int, int>>* visitOrder, int numPixelsVisited, vector<vector<string>> rgbFile){
    }

private:
    string calcRGB(float pos, int length){
        float n = pos / (float) length;
        stringstream ss;
        unchar R = (float) S_R * (1.0f-n) + (float) E_R * n;
        unchar B = (float) S_B * (1.0f-n) + (float) E_B * n;
        ss << "(" << R << ", 0, " << B << ")";
        return ss.str();
    }
};