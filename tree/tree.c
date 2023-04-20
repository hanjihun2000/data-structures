#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include "treeNode.h"

/*
*	Tree data structure using treeNodeADT.
*/

struct treeCDT {
    treeNodeADT root;
    int nSubtrees;
    treeADT subtrees[100];
    // The maximum number of subtrees is 100.
    // if nSubtrees = k, then only subtrees[0] to subtrees[k-1] are used.
};

treeADT getEmptyTree() {
    return (treeADT)NULL;
};

// The first argument is a root.
// The second argument is the number of children of a root.
// The other arguments are subtrees of type treeADT.
// The number of followed arguments should be identical as 'num' which is the value of the second argument.
treeADT getNonEmptyTree(treeNodeADT node, int num, ...) {
    treeADT tree = (treeADT)malloc(sizeof(*tree));
    tree->root = node;
    tree->nSubtrees = num;
    if (num > 0) {
        va_list subtrees;
        va_start(subtrees, num);
        for (int i = 0; i < num; i++) {
            tree->subtrees[i] = va_arg(subtrees, treeADT);
        };
        va_end(subtrees);
    };
    return tree;
};

// The second argument (subtree) is added to the first argument as a subtree.
treeADT addSubtree(treeADT tree, treeADT subtree) {
    tree->subtrees[(tree->nSubtrees)++] = subtree;
    return tree;
};

// Returns the n-th subtree, n = 0, 1, 2, ...
treeADT subtree(int n, treeADT tree) {
    return tree->subtrees[n];
};

// Returns the number of children of the root
int numberOfSubtrees(treeADT tree) {
    return tree->nSubtrees;
};

bool isTreeEmpty(treeADT tree) {
    return tree == (treeADT)NULL;
};

treeNodeADT root(treeADT tree) {
    return tree->root;
};
