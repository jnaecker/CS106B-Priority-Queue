/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"

/*
 * Constructor
 * ----------------------------------------------------------
 * Constructs a new, empty priority queue backed by a vector.
 */
DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	head = NULL;
}

/*
 * Destructor
 * ----------------------------------------------------------
 * Cleans up all memory allocated by this priority queue.
 * This is the canonical code to walk through a linked list
 * and delete each cell.
 */
DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
    while (head != NULL) {
        Cell* next = head->next;
        delete head;
        head = next;
    }
}

/*
 * Function: size()
 * Usage: int size = pqueue.size()
 * ----------------------------------------------------
 * Returns the number of elements in the priority queue.
 * Counts by walking through list cell-by-cell.
 */

int DoublyLinkedListPriorityQueue::size() {
	int result = 0;
    for (Cell* cell = head; cell != NULL; cell = cell->next) {
        result++;
    }
    return result;
}

/*
 * Function: isEmpty()
 * Usage: if (pqueue.isEmpty())
 * ---------------------------------------------------
 * Returns whether or not the priority queue is empty.
 */
bool DoublyLinkedListPriorityQueue::isEmpty() {
	return (head == NULL);
}

/*
 * Function: enqueue(string value)
 * Usage: pqueue.equeue("foo");
 * ----------------------------------------------
 * Enqueues a new string into the priority queue.
 * First makes a new cell.
 * Since backing list is unsorted, just appends
 * this cell onto head of list.
 */
void DoublyLinkedListPriorityQueue::enqueue(string value) {
    
	Cell* newCell = new Cell;
    newCell->value = value;
    newCell->previous = NULL;
    newCell->next = head;
    
    if (head != NULL) {
        head->previous = newCell;
    }
    
    head = newCell;
}

/*
 * Function: peek()
 * Usage: pqueue.peek();
 * ---------------------------------------------------
 * Returns, but does not remove, the lexicographically
 * first string in the priority queue.
 * If queue is empty, reports error.
 * To find alphabetically first string, loops over all
 * elements in the vector.
 */
string DoublyLinkedListPriorityQueue::peek() {
	if (isEmpty()) {
        error("Queue is empty.");
    }
    
    string result = head->value;
    for (Cell* cell = head; cell !=NULL; cell = cell->next) {
        if (cell->value < result) {
            result = cell->value;
        }
    }
    
    return result;
}


/*
 * Function: dequeueMin()
 * Usage: pqueue.dequeueMin();
 * ---------------------------------------------------
 * Returns and removes the lexicographically first string
 * in the priority queue.
 * If queue is empty, reports error.
 * To find alphabetically first string, loops over all
 * elements in the vector.  Then removes this cell.
 */
string DoublyLinkedListPriorityQueue::dequeueMin() {
    if (isEmpty()) {
        error("Queue is empty.");
    }
    
    string result = head->value;
    Cell* cellToRemove = head;
    
    for (Cell* cell = head; cell !=NULL; cell = cell->next) {
        if (cell->value < result) {
            result = cell->value;
            cellToRemove = cell;
        }
    }
    
    remove(cellToRemove);
    return result;
    
}

/*
 * Function: remove(Cell* cellToRemove)
 * Usage: remove(cellToRemove);
 * ---------------------------------------------------
 * Removes given cell from list.  First deals with special 
 * cases where cell is at head or tail of list.  
 */
void DoublyLinkedListPriorityQueue::remove(Cell* cellToRemove) {
    
    if (cellToRemove->previous == NULL) {
        head = cellToRemove->next;
        if ( cellToRemove->next != NULL) {
            cellToRemove->next->previous = NULL;
        }
    }
    
    else if (cellToRemove->next == NULL) {
        cellToRemove->previous->next = NULL;
    }
    
    else {
        cellToRemove->previous->next = cellToRemove->next;
        cellToRemove->next->previous = cellToRemove->previous;
        
    }
    
    delete cellToRemove;
    
}
