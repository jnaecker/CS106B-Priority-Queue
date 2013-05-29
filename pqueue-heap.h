/**********************************************
 * File: pqueue-heap.h
 * Name: Jeff Naecker
 * Section: Robert Hintz
 *
 * A priority queue class backed by a binary
 * heap.
 */
#ifndef PQueue_Heap_Included
#define PQueue_Heap_Included

#include <string>
using namespace std;

/* A class representing a priority queue backed by an
 * binary heap.
 */
class HeapPriorityQueue {
    
public:
    
	/* Constructs a new, empty priority queue backed by a binary heap. */
	HeapPriorityQueue();
	
	/* Cleans up all memory allocated by this priority queue. */
	~HeapPriorityQueue();
	
	/* Returns the number of elements in the priority queue. */
	int size();
	
	/* Returns whether or not the priority queue is empty. */
	bool isEmpty();
	
	/* Enqueues a new string into the priority queue. */
	void enqueue(string value);
	
	/* Returns, but does not remove, the lexicographically first string in the
	 * priority queue.
	 */
	string peek();
	
	/* Returns and removes the lexicographically first string in the
	 * priority queue.
	 */
	string dequeueMin();

private:
    
    /* Stores the length of the array that holds the heap.*/
    int allocatedLength;
    
    /* Stores the actual number of elements in the heap.*/
    int logicalLength;
    
    /* The array representing the heap.*/
    string* elems;
    
    /* Grows the array when more space is needed.*/
    void grow();
    
    /* Method to bubble up a newly-placed node to get a valid heap. */
    void bubbleUp(int childPos);
    
    /* Method to bubble down a node to get a valid heap. */
    void bubbleDown(int parentPos);
    
};

#endif
