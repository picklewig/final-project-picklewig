//
// Created by Isaac on 12/5/2021.
//

#ifndef L8_SHEPHERD_GRAPH_H
#define L8_SHEPHERD_GRAPH_H

#include "linkedlist.h"
#include <iostream>
#include "string"
#include <vector>

using std::cout;
using std::endl;
using std::string;

class Graph{
    public:
        Graph();
        ~Graph();

        addNode();//will append to graph vector
        removeNode();
        addEdge();
        removeEdge();
        isEmpty();
        printGraph();
    private:
        vector<LinkedList> graph;
};

#endif //L8_SHEPHERD_GRAPH_H
