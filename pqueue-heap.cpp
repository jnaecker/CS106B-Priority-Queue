/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"

const int DEFAULT_SIZE = 8;

HeapPriorityQueue::HeapPriorityQueue() {
	allocatedLength = DEFAULT_SIZE;
    logicalLength = 0;
    elems = new string[allocatedLength];
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] elems;
}

int HeapPriorityQueue::size() {
    return logicalLength;
}

bool HeapPriorityQueue::isEmpty() {
    return (size() == 0);
}

void HeapPriorityQueue::enqueue(string value) {
    
	if (logicalLength == allocatedLength) {
        grow();
    }
    
    elems[logicalLength] = value;
    logicalLength++;
    
    bubbleUp(logicalLength -1);
}

string HeapPriorityQueue::peek() {
    if (isEmpty()) {
        error("Queue is empty.");
    }
	return elems[0];
}

string HeapPriorityQueue::dequeueMin() {
	string result = peek();
    
    string end = elems[logicalLength-1];
    logicalLength--;
    elems[0] = end;

    bubbleDown(0);
    
    return result;
}

void HeapPriorityQueue::grow() {
    
    allocatedLength*=2;
    
    string* newElems = new string[allocatedLength];
        
    for (int i = 0; i < logicalLength; i++) {
        newElems[i] = elems[i];
    }
    
    delete[] elems;
    elems = newElems;
    
}


void HeapPriorityQueue::bubbleUp(int childPos) {
    
    if (childPos != 0) {
        
        int parentPos = ((childPos + 1) / 2) - 1;
        string child = elems[childPos];
        string parent = elems[parentPos];
        
        if (child < parent) {
            elems[childPos] = parent;
            elems[parentPos] = child;
            bubbleUp(parentPos);
        }
        
    }

}

void HeapPriorityQueue::bubbleDown(int parentPos) {
    
    int childPosLeft = 2*(parentPos + 1 ) - 1;
    int childPosRight = 2*(parentPos + 1 );
    
    // edge case 1: no children
    if (childPosLeft > logicalLength - 1) return;
    
    // edge case 2: one child only
    int childMinPos = childPosLeft;
    
    // main case: has two children
    if (childPosRight <= logicalLength - 1) {
        childMinPos = elems[childPosLeft] < elems[childPosRight] ? childPosLeft : childPosRight;
    }
    
    string childMin = elems[childMinPos];
    string parent = elems[parentPos];
    
    if (parent > childMin) {
        elems[parentPos] = childMin;
        elems[childMinPos] = parent;
        bubbleDown(childMinPos);
    }
    
    
}





