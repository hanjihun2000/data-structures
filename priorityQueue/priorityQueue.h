#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED
#include <stdbool.h>

typedef struct priorityQueueCDT* priorityQueueADT;
typedef int priorityQueueElementT;

priorityQueueADT getEmptyPriorityQueue(void);
void priorityEnqueue(priorityQueueADT, priorityQueueElementT);
priorityQueueElementT priorityDequeue(priorityQueueADT);
bool isPriorityQueueEmpty(priorityQueueADT);

#endif // PRIORITYQUEUE_H_INCLUDED
