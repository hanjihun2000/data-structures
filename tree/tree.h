#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "treeNode.h"

typedef struct treeCDT* treeADT;

treeADT getEmptyTree(void);
treeADT getNonEmptyTree(treeNodeADT, int, ...);
treeADT addSubtree(treeADT, treeADT);
treeADT subtree(int, treeADT);
int numberOfSubtrees(treeADT);
bool isTreeEmpty(treeADT);
treeNodeADT root(treeADT);

#endif // TREE_H_INCLUDED
