/**************
 * author: Isaac Shepherd
 * file: linkedlist.cpp
 **************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    clearList();
}

Node* LinkedList::getHead(){
    return head;
}

Node* LinkedList::createEdge(int id, int weight){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.weight = weight;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

bool LinkedList::addEdge(int id, int weight){
    bool added = false;
    if(head == NULL){
        head = createEdge(id, weight);
        added = true;
    }
    else if(id > 0 and weight > 0){
        Node *current = head; //head initially is NULL
        while(id > current->data.id and current->next != NULL){
            current = current->next;
        }
        if(id < current->data.id and current->prev != NULL){ //adds new body
            Node *insertEdge = createEdge(id, weight);
            insertEdge->next = current;
            insertEdge->prev = current->prev;
            current->prev->next = insertEdge;
            current->prev = insertEdge;
            added = true;
        }
        if(current->next == NULL){ //adds new tail node
            Node *insertEdge = createEdge(id, weight);
            insertEdge->prev = current;
            current->next = insertEdge;
            added = true;
        }
    }
    return added;
}

bool LinkedList::deleteEdge(int id){
    bool deleted = false;
    Node *current = head;
    while(current and id != current->data.id){
        current = current->next;
    }
    if(current and id == current->data.id) {
        if (current->prev != NULL and current->next == NULL) { //deletes tail node
            current->prev->next = NULL;
        } else if (current->next != NULL and current->prev == NULL) { //deletes head node
            current->next->prev = NULL;
            head = current->next;
        } else if(current->next != NULL and current->prev != NULL){ //deletes middle node
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        if(current == head){
            head = NULL;
        }
        delete current;
        deleted = true;
    }
    return deleted;
}

bool LinkedList::getEdge(int id, Data* emptyStruct){
    bool gotten = false;
    Node *current = head;

    while(current->next != NULL and id != current->data.id){
        current = current->next;
    }
    if(id == current->data.id){
        emptyStruct->id = current->data.id;
        emptyStruct->weight = current->data.weight;
        gotten = true;
    }
    return gotten;
}

void LinkedList::printList(bool backwards){
    Node *current = head;
    int nodeNumber = 0;

    if(!backwards){
        while(current){
            nodeNumber++;
            cout << current->data.id;
            if(current->next != NULL){
                cout << " --> ";
            }else{
                cout << endl;
            }
            current = current->next;
        }
    } else{
        while(current and current->next != NULL){
            current = current->next;
        }
        while(current){
            nodeNumber++;
            cout << current->data.id;
            if(current->next != NULL){
                cout << " --> ";
            }else{
                cout << endl;
            }
            current = current->prev;
        }
    }
    if(nodeNumber == 0){
        cout << "EMPTY" << endl;
    }
}

int LinkedList::getCount(){
    Node *current = head;
    int nodeCount = 0;

    while(current){
        current = current->next;
        nodeCount++;
    }
    return nodeCount;
}

void LinkedList::clearList(){
    Node *current = head;

    while(head and head->next){
        current = current->next;
        head = current;
        delete current->prev;
    }
    delete head;
    head = NULL;
}

bool LinkedList::exists(int id){
    bool found = false;
    Node *current = head;

    while(current){
        if(current->data.id == id){
            found = true;
        }
        current = current->next;
    }
    return found;
}