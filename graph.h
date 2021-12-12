//
// Created by Isaac on 12/5/2021.
//

#ifndef L8_SHEPHERD_GRAPH_H
#define L8_SHEPHERD_GRAPH_H

#include "linkedlist.h"
#include "stack.h"
#include <iostream>
#include "string"
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Graph{
    public:
        Graph();
        ~Graph();

        bool addVertex(int);//will append linked list with head node established to graph, will only require id
        bool removeVertex(int);
        bool addEdge(int, int, int);
        bool removeEdge(LinkedList* , int);
        bool isEmpty();
        void printGraph(int);
        bool vertexExists(int);
        bool edgeExists(int, int);
        void clear();
    private:
        vector<LinkedList*> graph;
        int vertices;//count variables
        int edges;
        LinkedList* findVertexList(int);
        void breadthFirstSearch(int);
        void depthFirstSearch(int);

};

#endif //L8_SHEPHERD_GRAPH_H
