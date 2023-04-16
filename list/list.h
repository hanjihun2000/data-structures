#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdbool.h>

typedef struct listCDT* listADT;
typedef int listElementT;

listADT getEmptyList(void);
listADT concat(listElementT, listADT);
listElementT getHead(listADT);
listADT getTail(listADT);
bool isListEmpty(listADT);

#endif // LIST_H_INCLUDED
