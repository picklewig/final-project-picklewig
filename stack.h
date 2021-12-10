/****************
 * Author: Isaac Shepherd
 * file: stack.h
 * header file for stack.cpp, holds class prototypes and defines max size of stack array
 ****************/

#ifndef STACK_H
#define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */

#include "data.h"

class Stack{
public:
    Stack(int);
    ~Stack();

    bool push(int);
    bool pop();
    bool peek(Data&);
    bool isEmpty();
    int getTop();
private:
    int size;
    int top; // this is top index
    Data *stack; // this is stack, it is an array of Data pointers
};

#endif //STACK_H