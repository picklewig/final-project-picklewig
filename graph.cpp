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
    //got to delete possible branches that connect to removed vertex
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

bool Graph::vertexExists(int id){
    bool exists = false;
    for(LinkedList* list : graph){
        if(list->getHead()->data.id == id){
            exists = true;
        }
    }
    return exists;
}

bool Graph::edgeExists(int id, int weight){
    bool exists = false;
    Data* copyData;
    for(LinkedList* list : graph){
        if(list->getEdge(id, copyData)){
            if(copyData->weight == weight){
                exists = true;
            }
        }
    }
    return exists;
}