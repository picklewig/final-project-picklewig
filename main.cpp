/****************
 * Author: Isaac Shepherd
 * file: main.cpp
 * testbed for class graph methods and functionality
 ****************/

#include "main.h"

int main(){
    int VERTEXSTART = 100;
    const int GRAPHSIZE = 7;
    //create graph object
    Graph testGraph;
    cout << endl << "testing to see if graph is empty" << endl;
    if(testGraph.isEmpty()){
        cout << "Graph is empty" << endl;
    }else{
        cout << "graph is not empty" << endl;
    }
    //add vertices
    cout << endl << "adding vertices to graph" << endl;
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
    }else{
        cout << 100 << " could not be added" << endl;
    }

    //start adding edges
    cout << endl << "adding edges to graph" << endl;

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
        testGraph.addEdge(500, 700, 10);
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

    if(testGraph.addEdge(700, 600, 10)){//origin, destination, weight
        cout << "adding edges to node 700" << endl;
    }
    else{
        cout << "could not add edge to node, possibly duplicate" << endl;
    }

    testGraph.printGraph(100);

    if(testGraph.removeVertex(400)){
        cout << "removed vertex: " << 400 << " from graph" << endl;
    }

    testGraph.printGraph(100);

    //testing vertexExists() and edgeExists()
    cout << endl << "Testing exist methods" << endl;
    if(testGraph.vertexExists(100)){
        cout << "vertex 100 exists" << endl;
    } else{
        cout << "vertex does not exist" << endl;
    }
    if(testGraph.vertexExists(1000)){
        cout << "vertex 1000 exists" << endl;
    } else{
        cout << "vertex does not exist" << endl;
    }
    if(testGraph.vertexExists(400)){
        cout << "vertex 400 exists" << endl;
    } else{
        cout << "vertex does not exist" << endl;
    }
    cout << "testing isEmpty() again" << endl;
    if(testGraph.isEmpty()){
        cout << "Graph is empty" << endl;
    }else{
        cout << "graph is not empty" << endl;
    }

    cout << endl << "clearing graph..." << endl;
    testGraph.clear();

    testGraph.printGraph(100);

};