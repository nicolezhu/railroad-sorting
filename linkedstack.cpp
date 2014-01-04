/*
 Program 1: linkedstack.cpp
 
 Author:	  Nicole Zhu
 Contact:     nzhu94@gmail.com
 Submission date:  10/23/13
 
*/

#include <iostream>
#include "linkedstack.h"

using namespace std;

LinkedStack::LinkedStack() {             // constructor
    first = NULL;
}

LinkedStack::~LinkedStack() {      // destructor
    if (first == NULL) {
        return;
    }
    
    while(first != NULL) {
        node *tmp = first;
        first = first->next;
        delete tmp;
    }
}

LinkedStack::LinkedStack(LinkedStack& other) {     // copy constructor
    first = other.first;
    
}

void LinkedStack::push(int num) {                 // push function (pushes a new node onto the stack unless the stack is full)
    node *tmp = new node;
    if (tmp == NULL) {
        cout << "Stack is full. \n";
        return;
    }
    
    tmp->next = first;
    tmp->d = num;
    first = tmp;
}

int LinkedStack::pop() {                        // pop function (pops a node unless stack is empty)
    if (first == NULL) {
        cout << "Stack is empty. \n";
        return 0;
    }
    
    node *tmp = first;
    int val = first->d;
    first = first->next;
    delete tmp;
    return val;
}

bool LinkedStack::empty() {                     // empty function (determines if a LinkedStack is empty)
    return (first == NULL);
}

int LinkedStack::top() {                        // top function (displays the top element of a LinkedStack)
    if(first != NULL) {
        return first->d;
    }
    else return 0;
}