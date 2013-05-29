/*************************************************************
 * File: pqueue-vector.cpp
 * Name: Jeff Naecker
 * Section: Robert Hintz
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"

/* 
 * Constructor
 * ----------------------------------------------------------
 * Constructs a new, empty priority queue backed by a vector. 
 */
VectorPriorityQueue::VectorPriorityQueue() {
	Vector<string> elems;
}

/* 
 * Destructor
 * ----------------------------------------------------------
 * Cleans up all memory allocated by this priority queue. 
 * Don't need to do anything here since memory is handled
 * by vector class.
 */
VectorPriorityQueue::~VectorPriorityQueue() {

}

/* 
 * Function: size()
 * Usage: int size = pqueue.size()
 * ----------------------------------------------------
 * Returns the number of elements in the priority queue. 
 */
int VectorPriorityQueue::size() {
    return elems.size();
}

/* 
 * Function: isEmpty()
 * Usage: if (pqueue.isEmpty())
 * ---------------------------------------------------
 * Returns whether or not the priority queue is empty. 
 */
bool VectorPriorityQueue::isEmpty() {
    return (elems.size() == 0);
}

/* 
 * Function: enqueue(string value)
 * Usage: pqueue.equeue("foo");
 * ----------------------------------------------
 * Enqueues a new string into the priority queue. 
 * Since backing vector is unsorted, just appends 
 * entry onto back of vector.
 */
void VectorPriorityQueue::enqueue(string value) {
	elems += value;
}

/* 
 * Function: enqueue(string value)
 * Usage: pqueue.equeue("foo");
 * ---------------------------------------------------
 * Returns, but does not remove, the lexicographically 
 * first string in the priority queue.
 * If queue is empty, reports error.
 * To find alphabetically first string, loops over all 
 * elements in the vector.
 */
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

/* 
 * Function: enqueue(string value)
 * Usage: pqueue.equeue("foo");
 * ---------------------------------------------------
 * Returns and removes the lexicographically first string 
 * in the priority queue.
 * If queue is empty, reports error.
 * To find alphabetically first string, loops over all
 * elements in the vector.
 */
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

