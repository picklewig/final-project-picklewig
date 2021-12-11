//
// Created by Isaac on 12/8/2021.
//

#include "main.h"

int main(){
    int VERTEXSTART = 100;
    const int GRAPHSIZE = 7;
    //create graph object
    Graph testGraph;
    //add vertices
    cout << "adding vertices to graph" << endl;
    for(int index = 0; index < GRAPHSIZE; index++){
        if(testGraph.addVertex(VERTEXSTART)){
            cout << "adding " << VERTEXSTART << " to graph" << endl;
        }
        else{
            cout << VERTEXSTART << " could not be added" << endl;
        }
        VERTEXSTART += 100;
    }

    cout << "testing known duplicate" << endl;
    if(testGraph.addVertex(100)){
        cout << "adding " << 100 << " to graph" << endl;
    }
    else{
        cout << 100 << " could not be added" << endl;
    }

    //start adding edges
    cout << "adding edges to graph" << endl;

    testGraph.addEdge(100, 200, 5);//origin, destination, weight

    testGraph.addEdge(200, 300, 10);//origin, destination, weight

    testGraph.addEdge(300, 400, 20);//origin, destination, weight
};