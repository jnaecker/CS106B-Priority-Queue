/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	head = NULL;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
    while (head != NULL) {
        Cell* next = head->next;
        delete head;
        head = next;
    }
}

int DoublyLinkedListPriorityQueue::size() {
	int result = 0;
    for (Cell* cell = head; cell != NULL; cell = cell->next) {
        result++;
    }
    return result;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	return (head == NULL);
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
    
    // make new entry
	Cell* newCell = new Cell;
    newCell->value = value;
    newCell->previous = NULL;
    newCell->next = head;
    
    if (head != NULL) {
        // correct pointer of previous first cell
        head->previous = newCell;
    }
    
    // move pointer for head
    head = newCell;

}

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

string DoublyLinkedListPriorityQueue::dequeueMin() {
    if (isEmpty()) {
        error("Queue is empty.");
    }
    
    // find min to remove
    string result = head->value;
    Cell* cellToRemove = head;
    
    for (Cell* cell = head; cell !=NULL; cell = cell->next) {
        if (cell->value < result) {
            result = cell->value;
            cellToRemove = cell;
        }
    }
    
    // clip out cell to remove
    //edge case 1: cell to remove is at beginning of list
    if (cellToRemove->previous == NULL) {
        head = cellToRemove->next;
        cellToRemove->next->previous = NULL;
    }
    
    //edge case 2: cell to remove is at end of list
    else if (cellToRemove->next == NULL) {
        cellToRemove->previous->next = NULL;
    }
    
    // otherwise we are in the middle of the list
    else {
        cellToRemove->previous->next = cellToRemove->next;
        cellToRemove->next->previous = cellToRemove->previous;

    }
    
    delete cellToRemove;
    return result;
    
}

