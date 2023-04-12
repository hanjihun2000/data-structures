#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <stdbool.h>

typedef struct queueCDT* queueADT;
// Define queue element type as integer.
// You can change it to whatever type you want to store in a queue data structure.
typedef int queueElementT;

queueADT getEmptyQueue(void);
void enqueue(queueADT queue, queueElementT element);
queueElementT dequeue(queueADT queue);
int getQueueLength(queueADT queue);
bool isQueueEmpty(queueADT queue);

#endif // QUEUE_H_INCLUDED
