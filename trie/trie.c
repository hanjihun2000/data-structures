#include <stdlib.h>
#include <stdbool.h>
#include "trie.h"

/*
*   Trie data structure.
*/

struct trieCDT {
    int weight;
    // For non-leaf nodes, c is not used.
    char ch;
    // For leaf node, both L and R are NULL.
    trieADT L;
    trieADT R;
};

trieADT getLeaf(char ch, int weight) {
    trieADT trie = (trieADT)malloc(sizeof(*trie));
    trie->weight = weight;
    trie->ch = ch;
    trie->L = (trieADT)NULL;
    trie->R = (trieADT)NULL;
    return trie;
};

// Get new trie using two existing tries.
trieADT getNewTrie(trieADT a, trieADT b){
    trieADT trie = (trieADT)malloc(sizeof(*trie));
    trie->weight = (a->weight + b->weight);
    trie->ch = (char) 0;
    trie->L = a;
    trie->R = b;
    return trie;
};

int getWeight(trieADT trie){
    return trie->weight;
};

char getChar(trieADT trie){
    return trie->ch;
};

trieADT getLeftTrie(trieADT trie){
    return trie->L;
};

trieADT getRightTrie(trieADT trie){
    return trie->R;
};

bool isLeaf(trieADT trie){
    return trie->L == (trieADT) NULL;
};
