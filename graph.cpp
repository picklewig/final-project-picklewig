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

bool Graph::removeVertex(int id){
    bool removed = false;
    int index = 0;
    Data* copyData;
    for(LinkedList* list : graph){ //deleting vertex requires removing from vector
        if(list->getHead()->data.id == id){
            graph.erase(graph.begin()+index);
            delete list;
            removed = true;
            vertices--;
        }
        if(list->exists(id)){ //removes possible edges going to vertex to be deleted
            list->getEdge(id, copyData);
            if(list->deleteEdge(copyData->id, copyData->weight)){
                edges--;
            }
        }
        index++;
    }//use 2nd for loop and call removeEdge
    return removed;
}

bool Graph::addEdge(int id, int destination, int weight){
    bool added = false;
    LinkedList* vertexList = findVertexList(id);
    LinkedList* destinationList = findVertexList(destination);
    if(vertexList and !vertexList->exists(destination)){
        vertexList->addEdge(destination, weight);
        destinationList->addEdge(id, weight);
        added = true;
        edges++;
    }
    return added;
}

bool Graph::removeEdge(int id, int destination, int weight){
    bool removed = false;
    LinkedList* vertexList = findVertexList(id);
    LinkedList* destinationList = findVertexList(destination);
    if(vertexList and vertexList->deleteEdge(destination)){
        destinationList->deleteEdge(id);
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
