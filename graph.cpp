//
// Created by Isaac on 12/6/2021.
//

#include "graph.h"

Graph::Graph(){
    vertices = 0;
    edges = 0;
}

bool Graph::addVertex(int id){
    bool added = false;
    bool duplicate = false;
    LinkedList* newList = new LinkedList;
    newList->addEdge(id, -1);//head of linked list represents node in graph, the following list items are edges
    for(LinkedList* list : graph){
        if(list->getHead()->data.id == id){
            duplicate = true;
        }
    }
    if(!duplicate){
        graph.push_back(newList);
        added = true;
        vertices++;
    }
    return added;
}

bool Graph::removeVertex(int id){
    bool deleted = false;
    int index = 0;
    for(LinkedList* list : graph){
        if(list->getHead()->data.id == id){
            graph.erase(graph.begin()+index);
            deleted = true;
            vertices--;
        }
        index++;
    }
    return deleted;
}

bool Graph::addEdge(int id, int destination, int weight){

}

bool Graph::removeEdge(int id, int destination, int weight){

}

bool Graph::isEmpty(){
    bool empty = true;
    if(vertices > 0){
        empty = false;
    }
    return empty;
}

void Graph::printGraph(){

}