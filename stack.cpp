/*****************
 * author: Isaac Shepherd
 * file: stack.cpp
 * defines methods for class Stack, incorporates use of the user defined data struct "Data"
 * includes stack.h
 ******************/

// each cpp includes ONLY it's header directly!
#include "stack.h"

Stack::Stack(){
    top = -1;
}

// function to insert data into stack
bool Stack::push(int id){
    bool pushed = false;
    if(top < STACK_SIZE-1)
    {
        stack[++top] = new Data;
        stack[top]->id = id;
        pushed = true;
    }
    return pushed;
}

// function to remove data from the top of the stack
bool Stack::pop(){
    bool popped = true;
    if(isEmpty()){
        popped = false;
    }
    else{
        delete stack[top--];
    }
    return popped;
}

bool Stack::peek(Data &myData){
    bool peeked = true;
    if(isEmpty()){
        peeked = false;
        myData.id = -1;
    }
    else{
        myData.id = stack[top]->id;
    }
    return peeked;
}

// function to check if stack is empty
bool Stack::isEmpty(){
    return top < 0;
}

int Stack::getTop(){
    return top;
}