//
// Created by Isaac on 12/6/2021.
//

#include "graph.h"

Graph::Graph(){
    vertices = 0;
    edges = 0;
}

Graph::~Graph(){
    clear();
}

bool Graph::addVertex(int id){
    bool added = false;
    bool duplicate = false;
    LinkedList* newList = new LinkedList;
    newList->addEdge(id, -1);//head of linked list represents graph vertex, following list items are edges
    if(vertexExists(id)){
        duplicate = true;
    }
    if(!duplicate){
        graph.push_back(newList);
        added = true;
        vertices++;
    }
    return added;
}

bool Graph::removeVertex(int vertexToDeleteId){
    bool removed = false;
    int index = 0;
    for(LinkedList* list : graph){ //deleting vertex requires removing from vector
        if(list->getHead()->data.id == vertexToDeleteId){
            graph.erase(graph.begin()+index);
            delete list;
            removed = true;
            vertices--;
        }
        index++;
    }
    for(LinkedList* list : graph){//for linkedlist in vector, delete edges to deleted vertex
        removeEdge(list, vertexToDeleteId);
    }
    return removed;
}

bool Graph::addEdge(int vertexId, int destinationId, int weight){
    bool added = false;
    LinkedList* vertexList = findVertexList(vertexId);
    LinkedList* destinationList = findVertexList(destinationId);

    if(vertexList and !vertexList->exists(destinationId)){
        vertexList->addEdge(destinationId, weight);
        destinationList->addEdge(vertexId, weight);
        added = true;
        edges++;
    }
    return added;
}

bool Graph::removeEdge(LinkedList* vertex, int destinationId){//make 1 parameter, id to be removed
    bool removed = false;
    if(vertex){//possibly this
        vertex->deleteEdge(destinationId);
        removed = true;
        edges--;
    }
    return removed;
}

bool Graph::isEmpty(){
    bool empty = true;
    if(vertices > 0){
        empty = false;
    }
    return empty;
}

void Graph::printGraph(int id){ //will call traversal methods
    cout << "Displaying Adjacency list: " << endl;
    for(LinkedList* list : graph){
        list->printList();
    }
    cout << "Breadth First Search traversal: ";
    //breadthFirstSearch(id);
    cout << "Depth First Search traversal: ";
    //depthFirstSearch(id);
    cout << endl;
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

void Graph::clear(){
    int index = 0;
    for(LinkedList* list : graph){
        delete list;
        graph.erase(graph.begin()+index);
        index++;
    }
    vertices = 0;
    edges = 0;
}

LinkedList *Graph::findVertexList(int id){
    LinkedList* vertex = NULL;
    for(LinkedList* list : graph){
        if(list->getHead()->data.id == id){
            vertex = list;
        }
    }
    return vertex;
}

void Graph::breadthFirstSearch(int id){

}

void Graph::depthFirstSearch(int id){

}
