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

    if(testGraph.addEdge(100, 200, 5)){//origin, destination, weight
        cout << "adding edges to node 100" << endl;
        testGraph.addEdge(100, 300, 5);
    }
    else{
        cout << "could not add edge to node, possibly duplicate" << endl;
    }

    if(testGraph.addEdge(200, 300, 10)){//origin, destination, weight
        cout << "adding edges to node 200" << endl;
        testGraph.addEdge(200, 400, 5);
    }
    else{
        cout << "could not add edge to node, possibly duplicate" << endl;
    }

    if(testGraph.addEdge(300, 400, 20)){//origin, destination, weight
        cout << "adding edges to node 300" << endl;
        testGraph.addEdge(300, 700, 10);
    }
    else{
        cout << "could not add edge to node, possibly duplicate" << endl;
    }

    if(testGraph.addEdge(400, 700, 20)){//origin, destination, weight
        cout << "adding edges to node 400" << endl;
        testGraph.addEdge(400, 500, 5);
    }
    else{
        cout << "could not add edge to node, possibly duplicate" << endl;
    }

    if(testGraph.addEdge(500, 600, 5)){//origin, destination, weight
        cout << "adding edges to node 500" << endl;
        testGraph.addEdge(500, 200, 10);
    }
    else{
        cout << "could not add edge to node, possibly duplicate" << endl;
    }
    //duplicate edge already created by node 500
    if(testGraph.addEdge(600, 500, 5)){//origin, destination, weight
        cout << "adding edges to node 600" << endl;
    }
    else{
        cout << "could not add edge to node, possibly duplicate" << endl;
    }

    if(testGraph.addEdge(700, 500, 10)){//origin, destination, weight
        cout << "adding edges to node 700" << endl;
        testGraph.addEdge(700, 600, 5);
    }
    else{
        cout << "could not add edge to node, possibly duplicate" << endl;
    }

    testGraph.printGraph(100);
};