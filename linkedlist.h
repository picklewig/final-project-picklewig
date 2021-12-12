/**************
 * author: Isaac Shepherd
 * file: linkedlist.h
 * holds class method prototypes for class linkedlist. includes data.h to use node structures as members of
 * linked list
 **************/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>

using std::cout;
using std::endl;

class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        //methods will be used inside Graph methods
        bool addEdge(int, int);
        bool deleteEdge(int);
        bool getEdge(int, Data*);
        void printList(bool = false);
        int getCount();
        void clearList();
        bool exists(int);
        Node* getHead();
    private:
        Node *head;
        Node *createEdge(int, int);
};

#endif
