//
// Created by Matthew on 3/21/2018.
//

typedef unsigned char unchar;

unchar const S_R = 0;
unchar char const S_B = 255;

unchar char const E_R = 255;
unchar char const E_B = 0;

#include <tuple>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

class ImWriter{
public:
    void write(list<tuple<int, int>>* visitOrder, int numPixelsVisited, string fName){
        fstream infile ("./../data/" + fName);
        vector<vector<tuple<unchar, unchar, unchar>>> old; //TODO: = FileParser method to read file to vectors
        float i = -1;
        while((visitOrder+1)){
            tuple<int,int> front = (visitOrder->front());
            visitOrder->pop_front();
            tuple<int,int> next = (visitOrder->front());
            int comX= get<0>(front);
            int comY = get<1>(front);
            for(int j =  get<0>(front); j < get<0>(next); ++j){
                int x = comX + j;
                old[comY][x] = calcRGB(++i, numPixelsVisited);
            }

            //float stepFrac = ++i / ((float) numPixelsVisited);

        }
        ofstream outfile ("./../resources/" + fName);

        outfile.close();
    }

private:
    tuple<unchar, unchar, unchar> calcRGB(float pos, int length){
        float n = pos / (float) length;
        unchar R = (float) S_R * (1.0f-n) + (float) E_R * n;
        unchar B = (float) S_B * (1.0f-n) + (float) E_B * n;
        return make_tuple(R, 0, B);
    }
};