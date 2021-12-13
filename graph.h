/****************
 * Author: Isaac Shepherd
 * file: graph.h
 * defines class prototype for graph. includes linkedlist.h and stack.h to use their class
 * architectures in graph. includes vector to hold implied vertices and edges
 * includes iostream of printing
 ****************/

#ifndef L8_SHEPHERD_GRAPH_H
#define L8_SHEPHERD_GRAPH_H

#include "linkedlist.h"
#include "stack.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Graph{
    public:
        Graph();
        ~Graph();

        bool addVertex(int);//will append linked list with head node established to graph, will only require id
        bool removeVertex(int);
        bool addEdge(int, int, int);
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
        bool removeEdge(LinkedList* , int);

};

#endif //L8_SHEPHERD_GRAPH_H
