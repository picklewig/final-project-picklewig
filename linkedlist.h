/**************
 * author: Isaac Shepherd
 * file: linkedlist.h
 **************/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include "string"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

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
