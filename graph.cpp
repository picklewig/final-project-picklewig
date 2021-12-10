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
    }
    return removed;
}

bool Graph::addEdge(int id, int destination, int weight){
    bool added = false;
    LinkedList* vertexList = findVertexList(id);
    if(vertexList and !vertexList->exists(destination)){
        vertexList->addEdge(destination, weight);
        added = true;
        edges++;
    }
    return added;
}

bool Graph::removeEdge(int id, int destination, int weight){
    bool removed = false;
    LinkedList* vertexList = findVertexList(id);
    if(vertexList and vertexList->deleteEdge(destination, weight)){
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
    cout << "Breadth First Search traversal: ";
    breadthFirstSearch(int id);
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
    bool* visited = new bool[vertices];
    for(int index = 0; index < vertices; index++){
        visited[index] = false;
    }
    Stack* queue(vertices);
    queue->push(id);
    while(!queue->isEmpty()){
        cout << queue->getTop() << " ";
        queue->pop();
        for(int index = 0; index < vertices; index++){
            if(!visited[index]){
                visited[index] = true;
                queue->push(index);
            }
        }
    }
    cout << endl;
}

void Graph::depthFirstSearch(int id){
    bool* visited = new bool[vertices];
    for(int index = 0; index < vertices; index++){
        visited[index] = false;
    }
    depthFirstSearch(id, visited);
    cout << endl;
}

void Graph::depthFirstSearch(int node, bool* visited){
    cout << node << " ";
    visited[node] = true;
    for(int index = 0; index < vertices; index++){
        if(!visited[*index]){
            depthFirstSearch(*index, visited);
        }
    }
}