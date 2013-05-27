/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
	Vector<string> elems;
}

VectorPriorityQueue::~VectorPriorityQueue() {
	// TODO: Fill this in!
}

int VectorPriorityQueue::size() {
    return elems.size();
}

bool VectorPriorityQueue::isEmpty() {
    return elems.size() == 0;
}

void VectorPriorityQueue::enqueue(string value) {
	elems += value;
}

string VectorPriorityQueue::peek() {
	if (isEmpty()) {
        error("Nothing in queue.");
    }
    
    string result = elems[0];
    for (int i = 1; i < elems.size(); i++) {
        if (elems[i] < result) {
            result = elems[i];
        }
        
    }
    return result;
    
}

string VectorPriorityQueue::dequeueMin() {
	if (isEmpty()) {
        error("Nothing in queue.");
    }
    
    int loc = 0;
    string first = elems[loc];
    for (int i = 1; i < elems.size(); i++) {
        if (elems[i] < first) {
            first = elems[i];
            loc = i;
        }
        
    }
    
    elems.remove(loc);
    return first;
}

