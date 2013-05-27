/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
    head = NULL;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	while (head != NULL) {
        Cell* next = head->next;
        delete head;
        head = next;
    }
}

int LinkedListPriorityQueue::size() {
    int result = 0;
    for (Cell* cell = head; cell != NULL; cell = cell->next) {
        result++;
    }
    return result;
}

bool LinkedListPriorityQueue::isEmpty() {
    return head == NULL;
}

void LinkedListPriorityQueue::enqueue(string value) {
	Cell* newCell = new Cell;
    newCell->value = value;
    newCell->next = NULL;
    
    // if nothing in pqueue
    if (head == NULL) {
        head = newCell;
        
    } else {
        
        for (Cell* cell = head; cell != NULL; cell = cell->next) {
            Cell* nextCell = cell->next;
            
            // if the current cell is the first
            if (cell == head && newCell->value <= head->value) {
                newCell->next = head;
                head = newCell;
                return;
            }
            
            // if the current cell is the last
            if(nextCell == NULL) {
                cell->next = newCell;
                return;
            }
            
            // otherwise
            if (value > cell->value && value <= nextCell->value) {
                newCell->next = nextCell;
                cell->next = newCell;
                return;
            }
        }
    }
}

string LinkedListPriorityQueue::peek() {
    if (isEmpty()) {
        error("Queue is empty.");
    }
    return head->value;
}

string LinkedListPriorityQueue::dequeueMin() {
    string result = peek();
    
    Cell* next = head->next;
    delete head;
    head = next;
    
    return result;
}

