
//  1. Please choose which data structure implementation you want to use.
//  2. Then, comment out the other(s) if it exists. Press (Ctrl + Shift + /) keys for Window users. 

#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/*
*   List data structure using linked list implementation.
*/

struct listCDT {
    listElementT head;
    listADT tail;
};

listADT getEmptyList() {
    return ((listADT)NULL);
};

listADT concat(listElementT element, listADT list) {
    listADT l = (listADT)malloc(sizeof(*l));
    l->head = element;
    l->tail = list;
    return (l);
};

listElementT getHead(listADT list) {
    if (isListEmpty(list)) {
        exit(EXIT_FAILURE);
    }
    return list->head;
};

listADT getTail(listADT list) {
    if (isListEmpty(list)) {
        exit(EXIT_FAILURE);
    }
    return list->tail;
};

bool isListEmpty(listADT list) {
    return (list == NULL);
};

/*
*   List data structure using array implementation.
*/

//#define MAX 100
//
//struct listCDT {
//	listElementT elements[MAX];
//	int length;
//};
//
//listADT getEmpytyList() {
//	listADT L = (listADT)malloc(sizeof(*L));
//	L->length = 0;
//	return L;
//};
//
//listADT concat(listElementT element, listADT list) {
//	listADT L = (listADT)malloc(sizeof(*L));
//	L->elements[0] = element;
//	for (int i = 0; i < list->length; i++) {
//		L->elements[i + 1] = list->elements[i];
//	}
//	L->length = list->length + 1;
//	return L;
//};
//
//listElementT getHead(listADT list) {
//	if (isListEmpty(list)) {
//		exit(EXIT_FAILURE);
//	}
//	return list->elements[0];
//};
//
//listADT getTail(listADT list) {
//	if (isListEmpty(list)) {
//		exit(EXIT_FAILURE);
//	}
//	if (list->length == 1) {
//		return getEmptyList();
//	}
//	listADT L = (listADT)malloc(sizeof(*L));
//	for (int i = 0; i < list->length; i++) {
//		L->elements[i] = L->elements[i + 1];
//	}
//	L->length = list->length - 1;
//	return L;
//};
//
//bool isListEmpty(listADT list) {
//	return (list->length == 0);
//};
