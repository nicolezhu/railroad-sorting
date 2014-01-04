/*
Program 1: railroad.h
 
 Author:	  Nicole Zhu
 Contact:     nzhu94@gmail.com
 Submission date:  10/23/13
 
*/

#ifndef RAILROAD_H
#define RAILROAD_H

#include "linkedstack.h"
#include <iostream>

// declares railroad functions that will be implemented in main.cpp
bool Railroad(int[], int);
bool outputFromHoldTrack(int, int, LinkedStack*, LinkedStack*, ostringstream&);
bool putInHold(int, int, LinkedStack*, ostringstream&);


#endif
