//
// Created by Isaac on 12/8/2021.
//

#include "main.h"

int main(){
    //create graph object
    Graph testGraph;
    //add vertices
    cout << "adding vertices to graph" << endl
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
    if(testGraph.addVertex(VERTEXSTART)){
        cout << "adding " << VERTEXSTART << " to graph" << endl;
    }
    else{
        cout << VERTEXSTART << " could not be added" << endl;
    }
};