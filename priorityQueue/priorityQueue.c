#include <stdlib.h>
#include <stdbool.h>
#include "priorityQueue.h"

/*
*   Priority queue data structure using heap.
*/

struct priorityQueueCDT {
    priorityQueueElementT heap[1000]; // You can set this value to whatever value you want.
    int numOfElem;
};

priorityQueueADT getEmptyPriorityQueue() {
    priorityQueueADT pQueue = (priorityQueueADT)malloc(sizeof(*pQueue));
    pQueue->numOfElem = 0;
    return pQueue;
};

void priorityEnqueue(priorityQueueADT pQueue, priorityQueueElementT element) {
    // Enqueue an element into a proper index position based on the priority rule.
    // In this implementation, the smallest element has the highest priority.
    int index;
    for (index = (pQueue->numOfElem)++; index == 0 ? false : pQueue->heap[(index - 1) / 2] > element; index = (index - 1) / 2) {
        pQueue->heap[index] = pQueue->heap[(index - 1) / 2];
    }
    pQueue->heap[index] = element;
};

priorityQueueElementT priorityDequeue(priorityQueueADT pQueue) {
    if (isPriorityQueueEmpty(pQueue)) {
        exit(EXIT_FAILURE);
    }
    priorityQueueElementT result, last;
    int index, child;
    // Dequeue (return) the first element, since it is the smallest element in a priority queue.
    result = pQueue->heap[0];
    // Rearrange the heap array based on the priority rule.
    last = pQueue->heap[--(pQueue->numOfElem)];
    for (index = 0; 2 * index + 1 < pQueue->numOfElem; index = child) {
        child = 2 * index + 1;
        if (child + 1 < pQueue->numOfElem && pQueue->heap[child + 1] < pQueue->heap[child]) {
            child++;
        }
        if (last > pQueue->heap[child]) {
            pQueue->heap[index] = pQueue->heap[child];
        }
        else {
            break;
        }
    }
    pQueue->heap[index] = last;
    return result;
};

bool isPriorityQueueEmpty(priorityQueueADT pQueue) {
    return pQueue->numOfElem == 0;
};
