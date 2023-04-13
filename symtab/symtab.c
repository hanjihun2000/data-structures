
//  1. Please choose which data structure implementation you want to use.
//  2. Then, comment out the other(s) if it exists. Press (Ctrl + Shift + /) keys for Window users. 

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symtab.h"

/*
*   Symbol table data structure using seperate chaining collision implementation and hash function.
*       -   Separate chaining method is basically using a 'linked list' strucuture.
*           It will chain (link) elements if their hash values are identical.
*/

#define MAX 100

typedef struct cellT {
    char* key;
    void* value;
    struct cellT* next;
} cellT;

struct symtabCDT {
    cellT* buckets[MAX];
};

// This is a hash function that generates a specific hash value to each element in the range of [0, 100).
int hash(char* s, int nBuckets) {
    unsigned long hashCode = 0UL;
    for (int i = 0; s[i] != '\0'; i++) {
        hashCode = (hashCode << 5) + s[i];
    };
    return (int)(hashCode % nBuckets);
};

symtabADT getEmptySymtab() {
    symtabADT table = (symtabADT)malloc(sizeof(*table));
    for (int i = 0; i < MAX; i++) {
        table->buckets[i] = NULL;
    };
    return table;
};

static cellT* findCell(cellT* cp, char* key) {
    while (cp != NULL ? strcmp(cp->key, key) != 0 : 0) {
        cp = cp->next;
    };
    return cp;
};

void enter(symtabADT table, char* key, void* value) {
    int hashCode = hash(key, MAX);
    cellT* cp = findCell(table->buckets[hashCode], key);
    if (cp == NULL) {
        cp = (cellT*)malloc(sizeof(*cp));
        cp->key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
        strcpy(cp->key, key);
        cp->next = table->buckets[hashCode];
        table->buckets[hashCode] = cp;
    };
    cp->value = value;
};

void* lookup(symtabADT table, char* key) {
    int hashCode = hash(key, MAX);
    cellT* cp = findCell(table->buckets[hashCode], key);
    if (cp == NULL) {
        return NULL;
    };
    return cp->value;
};

bool isSymtabEmpty(symtabADT table) {
    for (int i = 0; i < MAX; i++) {
        if (table->buckets[i] != NULL) {
            return false;
        }
    }
    return true;
};

void forEachEntryDo(symtabFnT f, symtabADT table) {
    cellT* cp;
    for (int i = 0; i < MAX; i++) {
        for (cp = table->buckets[i]; cp != NULL; cp = cp->next) {
            f(cp->key, cp->value);
        }
    }
};

/*
*   Symbol table data structure using quadratic probing collision implementation and hash function.
*/

//typedef struct bucketT {
//    int status; // 1 if the bucket contains key-value pair, or 0 otherwise    
//    char* key;
//    void* value;
//} bucketT;
//
//struct symtabCDT {
//    bucketT buckets[MAX];
//};
//
//symtabADT getEmptySymtab() {
//    symtabADT table = (symtabADT)malloc(sizeof(*table));
//    for (int i = 0; i < MAX; i++) {
//        table->buckets[i].status = 0;
//        table->buckets[i].key = NULL;
//        table->buckets[i].value = NULL;
//    };
//    return table;
//};
//
//int hash(char* key, int nBuckets) {
//    unsigned long hashCode = 0UL;
//    for (int i = 0; key[i] != '\0'; i++) {
//        // (hashCode << 5) means hashCode to the power of 5, which is hashCode^5
//        hashCode = (hashCode << 5) + (unsigned long)key[i];
//    };
//    return (int)(hashCode % nBuckets);
//};
//
//static int findBucket(symtabADT table, char* key, int hashCode) {
//    int index = hashCode;
//    for (int i = 0; i < MAX; i++) {
//        if (table->buckets[hashCode].status == 0 || strcmp(table->buckets[hashCode].key, key) == 0) {
//            return hashCode;
//        }
//        // search another index using quadratic probing
//        index = (hashCode + i * i) % MAX;
//    };
//    return index;
//};
//
//void enter(symtabADT table, char* key, void* value) {
//    int hashCode = hash(key, MAX);
//    int index = findBucket(table, key, hashCode);
//    if (table->buckets[index].status == 0) {
//        table->buckets[index].status = 1;
//        table->buckets[index].key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
//        strcpy(table->buckets[index].key, key);
//    }
//    table->buckets[index].value = value;
//};
//
//void* lookup(symtabADT table, char* key) {
//    int hashCode = hash(key, MAX);
//    int index = findBucket(table, key, hashCode);
//    if (table->buckets[index].status == 0) {
//        return NULL;
//    }
//    return table->buckets[index].value;
//};
//
//bool isSymtabEmpty(symtabADT table) {
//    for (int i = 0; i < MAX; i++) {
//        if (table->buckets[i].status == 1) {
//            return false;
//        }
//    }
//    return true;
//};
//
//void forEachEntryDo(symtabFnT f, symtabADT table) {
//    for (int i = 0; i < MAX; i++) {
//        if (table->buckets[i].status == 1) {
//            f(table->buckets[i].key, table->buckets[i].value);
//        }
//    }
//};
