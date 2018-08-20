//
// Created by Matthew on 3/21/2018.
//

typedef unsigned char unchar;

class ImWriter{
public:
    void write(std::list<GraphNode*>* visitOrder, const std::string &fileName){
        std::stack<GraphNode*> lastConnection;
        lastConnection.push(visitOrder->front());
        visitOrder->pop_front();
        std::unordered_map<GraphNode*, GraphEdge> currentNeighbors = lastConnection.top()->getNeighbors();
        while(!lastConnection.empty()){
            GraphNode* gn = visitOrder->front();
            if(currentNeighbors.find(gn) != currentNeighbors.end()){ // This node is a neighbor of

            }
        }
    }
};