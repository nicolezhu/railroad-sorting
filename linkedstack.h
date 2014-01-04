/*
 Program 1: linkedlist.h
 
 Author:	  Nicole Zhu
 Contact:     nzhu94@gmail.com
 Submission date:  10/23/13
 
*/

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <iostream>

// define structure of a node in list
struct node {
    int d;
    node *next;
};

// define class LinkedStack
class LinkedStack {
private:
    node *first;
    
public:
    LinkedStack();         // constructor
    ~LinkedStack();         // destructor
    LinkedStack(LinkedStack& other); // copy constructor
    
    // stack functions: push, pop, empty, top
    void push(int num);
    int pop();
    bool empty();
    int top();
};

#endif
