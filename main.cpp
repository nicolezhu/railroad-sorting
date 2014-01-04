/*
 Program 1: main.cpp
 
 Author:	  Nicole Zhu
 Contact:     nzhu94@gmail.com
 Submission date:  10/23/13
 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#include "linkedstack.h"
#include "railroad.h"

bool Railroad(int inputOrder[], int numberOfCars, int numberOfTracks) {
    LinkedStack *holdingTracks = (LinkedStack *)malloc(numberOfTracks*sizeof(LinkedStack));
    for (int i=0; i < numberOfTracks; i++) {
        holdingTracks[i] = LinkedStack();
    }
    LinkedStack *outputTrack = new LinkedStack();
    ostringstream railroadMoves;              // stores the "moves" of each railroad car permutation

    int nextCar = 1;
    int index = numberOfCars - 1;
    int currentCar = inputOrder[index];
    
    while (nextCar <= numberOfCars) {
        if (index >= 0) {
            currentCar = inputOrder[index];
            
            // send car straight to output
            if (currentCar == nextCar) {
                outputTrack->push(currentCar);
                railroadMoves << "Move car " << currentCar << " from input to output" << endl;
                nextCar++;
                index--;
            
                // try to output from holding tracks
                if (outputFromHoldTrack(numberOfTracks, nextCar, outputTrack, holdingTracks, railroadMoves)) {
                    nextCar++;
                }
            }
        
            else {
                // if car cannot be sent straight to ouptut, put car in holding track
                if (putInHold(currentCar, numberOfTracks, holdingTracks, railroadMoves)) {
                    index--;
                }
                // output from holding tracks
                else if (outputFromHoldTrack(numberOfTracks, nextCar, outputTrack, holdingTracks, railroadMoves)) {
                    nextCar++;
                }
                // if none of the above work, return error
                else {
                    cout << "permutation ";
                    for (int i=0; i< numberOfCars; i++) {
                        cout << inputOrder[i];
                    }
                    cout << " not feasible" << endl;
                    return false;
                }
            }
        }
        else {
            // try to output from holding tracks
            if (outputFromHoldTrack(numberOfTracks, nextCar, outputTrack, holdingTracks, railroadMoves)) {
                nextCar++;
            }
        }
    }
    cout << railroadMoves.str();           // print moves if permutation is feasible
    return true;
}

bool putInHold(int currentCar, int numberOfTracks, LinkedStack *holdingTracks, ostringstream &moves) {
    // input number will either
    // (1) go on top of already filled track or
    // (2) be placed in empty track
    
    for (int i=0; i<numberOfTracks; i++) {
        if (holdingTracks[i].empty() || (!holdingTracks[i].empty() && holdingTracks[i].top() > currentCar)) {
            moves << "Holding track " << i+1 << " hold car " << currentCar << endl;
            holdingTracks[i].push(currentCar);
            return true;
        }
    }
    return false;
}

bool outputFromHoldTrack(int numberofTracks, int nextCar, LinkedStack *outputTrack, LinkedStack *holdingTracks, ostringstream &moves) {
    // if one of the top elements of holding track can be moved to output track - return true if object is moved, return false otherwise
    for (int i=0; i < numberofTracks; i++) {
        if (holdingTracks[i].top() == nextCar) {
            moves << "Move car " << holdingTracks[i].top() << " from holding track " << i+1 << " to output" << endl;
            outputTrack->push(holdingTracks[i].top());
            holdingTracks[i].pop();
            nextCar++;
            
            return true;
        }
    }
    
    return false;
}

int main () {
    ifstream infile;
    infile.open("input.txt");
    int input[9];
    int counter = 0;
    int numberCars = 0;
    int numberTracks = 0;
    
    if (infile.is_open()) {                   // test if file is open
        while (!infile.eof()) {               // while file is open do the following
            if (counter == 0) {
                infile >> numberCars;         // set number of cars to be the first input from file
            }
            else if (counter == 1) {
                infile >> numberTracks;       // set number of tracks to be the second input from file
            }
            else {
                infile >> input[counter - 2]; // put remaining inputs from file into an input array (which will be the input order)
            }
            counter ++;
        }
    }
    
    Railroad(input, numberCars, numberTracks);
    
    infile.close();                           // close file
}