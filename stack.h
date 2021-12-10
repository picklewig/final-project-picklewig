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
    /* 
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */
    bool push(int);
    bool pop();
    bool peek(Data&);
    bool isEmpty();
    int getTop();
private:

    // these are the only attributes you need. do not modify them or add any
    int size;
    int top; // this is your top index
    Data *stack[]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H