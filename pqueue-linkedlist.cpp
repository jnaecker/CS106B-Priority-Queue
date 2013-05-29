/*************************************************************
 * File: pqueue-linkedlist.cpp
 * Name: Jeff Naecker
 * Section: Robert Hintz
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"


/*
 * Constructor
 * ----------------------------------------------------------
 * Constructs a new, empty priority queue backed by a sorted 
 * linked list.
 */
LinkedListPriorityQueue::LinkedListPriorityQueue() {
    head = NULL;
}

/*
 * Destructor
 * ----------------------------------------------------------
 * Cleans up all memory allocated by this priority queue. 
 * Deletes list by starting at head and following next links.
 */
LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	while (head != NULL) {
        Cell* next = head->next;
        delete head;
        head = next;
    }
}

/*
 * Function: size()
 * Usage: int size = pqueue.size()
 * ------------------------------------------------------------
 * Returns the number of elements in the priority queue.
 * Counts elements by starting at head and following next links.
 */
int LinkedListPriorityQueue::size() {
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
bool LinkedListPriorityQueue::isEmpty() {
    return head == NULL;
}

/*
 * Function: enqueue(string value)
 * Usage: pqueue.equeue("foo");
 * ---------------------------------------------------
 * Enqueues a new string into the priority queue. 
 * First creates a new cell with the new value.
 * If list is empty, this is new cell.
 * Deals with two special cases:  new cell is placed
 * first and new cell is placed last. Then deals with 
 * remaining cases.
 */
void LinkedListPriorityQueue::enqueue(string value) {
	Cell* newCell = new Cell;
    newCell->value = value;
    newCell->next = NULL;
    
    if (head == NULL) {
        head = newCell;
        
    } else {
        
        for (Cell* cell = head; cell != NULL; cell = cell->next) {
            Cell* nextCell = cell->next;
            
            if (cell == head && newCell->value <= head->value) {
                newCell->next = head;
                head = newCell;
                return;
            }
            
            if(nextCell == NULL) {
                cell->next = newCell;
                return;
            }
            
            if (value > cell->value && value <= nextCell->value) {
                newCell->next = nextCell;
                cell->next = newCell;
                return;
            }
        }
    }
}

/*
 * Function: peek();
 * Usage: pqueue.peek();
 * ---------------------------------------------------
 * Returns, but does not remove, the lexicographically
 * first string in the priority queue.
 * If queue is empty, reports error.
 * List is already sorted, so returns first value.
 */
string LinkedListPriorityQueue::peek() {
    if (isEmpty()) {
        error("Queue is empty.");
    }
    return head->value;
}

/*
 * Function: dequeueMin()
 * Usage: pqueue.dequeueMin();
 * ---------------------------------------------------
 * Returns and removes the lexicographically first string
 * in the priority queue.
 * If queue is empty, reports error.
 * List is already sorted, so returns first value and moves
 * head down one cell.
 */
string LinkedListPriorityQueue::dequeueMin() {
    string result = peek();
    
    Cell* next = head->next;
    delete head;
    head = next;
    
    return result;
}

