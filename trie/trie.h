#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED
#include <stdlib.h>
#include <stdbool.h>

typedef struct trieCDT* trieADT;

trieADT getLeaf(char, int);
trieADT getNewTrie(trieADT, trieADT);
trieADT getLeftTrie(trieADT);
trieADT getRightTrie(trieADT);
int getWeight(trieADT);
char getChar(trieADT);
bool isLeaf(trieADT);

#endif // TRIE_H_INCLUDED
