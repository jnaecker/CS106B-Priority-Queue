/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"

/* Starting size for the heap.*/
const int DEFAULT_SIZE = 8;

/*
 * Constructor
 * ----------------------------------------------------------
 * Constructs a new, empty priority queue backed by a heap.
 */
HeapPriorityQueue::HeapPriorityQueue() {
	allocatedLength = DEFAULT_SIZE;
    logicalLength = 0;
    elems = new string[allocatedLength];
}

/*
 * Destructor
 * ----------------------------------------------------------
 * Cleans up all memory allocated by this priority queue.
 * Since we are using a single array, just need one delete[].
 */
HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] elems;
}

/*
 * Function: size()
 * Usage: int size = pqueue.size()
 * ----------------------------------------------------
 * Returns the number of elements in the priority queue.
 */
int HeapPriorityQueue::size() {
    return logicalLength;
}

/*
 * Function: isEmpty()
 * Usage: if (pqueue.isEmpty())
 * ---------------------------------------------------
 * Returns whether or not the priority queue is empty.
 */
bool HeapPriorityQueue::isEmpty() {
    return (size() == 0);
}

/*
 * Function: enqueue(string value)
 * Usage: pqueue.equeue("foo");
 * ----------------------------------------------
 * Enqueues a new string into the priority queue.
 * If more space is needed, grow() is first called.
 * New string is placed at end of array and
 * a bubble up is performed.
 */
void HeapPriorityQueue::enqueue(string value) {
    
	if (logicalLength == allocatedLength) {
        grow();
    }
    
    elems[logicalLength] = value;
    logicalLength++;
    
    bubbleUp(logicalLength - 1);
}

/*
 * Function: peek()
 * Usage: pqueue.peek();
 * ---------------------------------------------------
 * Returns, but does not remove, the lexicographically
 * first string in the priority queue.
 * If queue is empty, reports error.
 * Because of heap structure, alphabetically first 
 * string is first element in array.
 */
string HeapPriorityQueue::peek() {
    if (isEmpty()) {
        error("Queue is empty.");
    }
	return elems[0];
}

/*
 * Function: dequeueMin()
 * Usage: pqueue.dequeueMin();
 * ---------------------------------------------------
 * Returns and removes the lexicographically first string
 * in the priority queue.
 * If queue is empty, reports error.
 * Because of heap structure, alphabetically first
 * string is first element in array.  This element is
 * returned by peek(), and then last element in array
 * is put at first position in array.  Bubble-down
 * is then performed.
 */
string HeapPriorityQueue::dequeueMin() {
	string result = peek();
    
    string end = elems[logicalLength-1];
    logicalLength--;
    elems[0] = end;

    bubbleDown(0);
    
    return result;
}

/*
 * Function: grow()
 * Usage: grow()
 * ---------------------------------------------------
 * Grows the array when more space is needed.
 * Creates new array that is double the size and then
 * copies all elements over there.
 */
void HeapPriorityQueue::grow() {
    
    allocatedLength*=2;
    
    string* newElems = new string[allocatedLength];
        
    for (int i = 0; i < logicalLength; i++) {
        newElems[i] = elems[i];
    }
    
    delete[] elems;
    elems = newElems;
    
}

/*
 * Function: bubbleUp(int childPos)
 * Usage: bubbleUp(logicalLength - 1)
 * ---------------------------------------------------
 * Method to bubble up a newly-placed node to get a valid heap.
 * Compares node to its parent and swaps if child
 * comes alphabetically before parent.  Then calls
 * itself on parent position to continue bubble-up
 * process.
 */
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

/*
 * Function: bubbleDown(int parentPos)
 * Usage: bubbleDown(0)
 * --------------------------------------------------------------
 * Method to bubble down a node to get a valid heap.
 * Swaps parent with smaller child if parent is bigger than this
 * child.  Deals with special cases where there
 * are no children or just one child.  Recursively calls
 * itself to continue bubble-down process.
 */
void HeapPriorityQueue::bubbleDown(int parentPos) {
    
    int childPosLeft = 2*(parentPos + 1 ) - 1;
    int childPosRight = 2*(parentPos + 1 );
    
    if (childPosLeft > logicalLength - 1) return;
    
    int childMinPos = childPosLeft;
    
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





