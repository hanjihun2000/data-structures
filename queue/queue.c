
//  1. Please choose which data structure implementation you want to use.
//  2. Then, comment out the other(s) if it exists. Press (Ctrl + Shift + /) keys for Window users.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

/*
*   Queue data structure using linked list implementation.
*/

// cellT contains an element to store and a pointer that points to the next cellT.
// This structure is called a 'linked list'.
typedef struct cellT {
    queueElementT value;
    struct cellT* next;
} cellT;

// queueADT points to queueCDT which has two cellT pointers, front and rear.
struct queueCDT {
    cellT* front;
    cellT* rear;
};

queueADT getEmptyQueue(void) {
    queueADT queue;
    queue = (queueADT)malloc(sizeof(*queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
};

void enqueue(queueADT queue, queueElementT element) {
    cellT* cp;
    cp = (cellT*)malloc(sizeof(*cp));
    cp->value = element;
    cp->next = NULL;

    if (queue->front == NULL) {
        queue->front = cp;
    }
    else {
        queue->rear->next = cp;
    }
    queue->rear = cp;
};

queueElementT dequeue(queueADT queue) {
    queueElementT result;
    if (queue->front == NULL) {
        exit(EXIT_FAILURE);
    }
    result = queue->front->value;
    queue->front = queue->front->next;
    return result;
};

int getQueueLength(queueADT queue) {
    int n = 0;
    cellT* cp;
    for (cp = queue->front; cp != NULL; cp = cp->next) {
        n++;
    }
    return n;
};

bool isQueueEmpty(queueADT queue){
    return queue->front == NULL;
}

/*
*   Queue data structure using circular implementation.
*/

//#define MAX 100
//
//
//struct queueCDT {
//    // Max number of elements is 99 in this implementation.
//    queueElementT elements[MAX];
//    int front;
//    int rear;
//};
//
//queueADT getEmptyQueue() {
//    queueADT queue;
//    queue = (queueADT)malloc(sizeof(*queue));
//    queue->front = 1;
//    queue->rear = 0;
//    return queue;
//}
//
//void enqueue(queueADT queue, queueElementT element) {
//    // Check if a queue is full.
//    if (queue->front == (queue->rear + 2) % MAX) {
//        printf("Queue is Full!\n");
//        exit(EXIT_FAILURE);
//    }
//    int n = (queue->rear += 1) % MAX;
//    queue->rear = n;
//    queue->elements[queue->rear] = element;
//}
//
//queueElementT dequeue(queueADT queue) {
//    // Check if a queue is empty.
//    if (queue->front == (queue->rear + 1) % MAX) {
//        printf("Queue is Empty!\n");
//        exit(EXIT_FAILURE);
//    }
//    queueElementT result = queue->elements[queue->front];
//    int n = (queue->front += 1) % MAX;
//    queue->front = n;
//    return result;
//}
//
//int getQueueLength(queueADT queue) {
//    int result;
//    if (queue->front == (queue->rear + 1)) {
//        result = 0;
//    }
//    else if (queue->front <= queue->rear) {
//        result = queue->rear - queue->front + 1;
//    }
//    else {
//        result = (MAX - queue->front) + queue->rear + 1;
//    }
//    return result;
//}
//
//bool isQueueEmpty(queueADT queue) {
//    return (queue->front == (queue->rear + 1) % MAX);
//}
