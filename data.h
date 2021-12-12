/****************
 * Author: Isaac Shepherd
 * file: data.h
 * defines structures used to hold edge and vertex data. structures used in graph method arguments
 * and graph traversals
 ****************/

#ifndef DATA_H
#define DATA_H

#include "string"
using std::string;

struct Data {
    int id; //name identifier
    int weight; //used to be string data
    bool visited = false;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

#endif /* DATA_H */

