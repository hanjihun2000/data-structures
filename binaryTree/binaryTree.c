#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binaryTree.h"

/*
*   Binary tree data structure.
*/

struct treeNodeCDT {
    char* key;
    int nodeData;
};

struct binaryTreeCDT {
    treeNodeADT root;
    binaryTreeADT lst; // left sub tree
    binaryTreeADT rst; // right sub tree
};

binaryTreeADT getEmptyBinaryTree() {
    return (binaryTreeADT)NULL;
};

binaryTreeADT getNonEmptyBinaryTree(treeNodeADT node, binaryTreeADT lst, binaryTreeADT rst) {
    binaryTreeADT tree = (binaryTreeADT)malloc(sizeof(*tree));
    tree->root = node;
    tree->lst = lst;
    tree->rst = rst;
    return tree;
};

treeNodeADT getRoot(binaryTreeADT tree) {
    if (isTreeEmpty(tree)) {
        exit(EXIT_FAILURE);
    }
    return tree->root;
};

binaryTreeADT getLeftSubtree(binaryTreeADT tree) {
    if (isTreeEmpty(tree)) {
        exit(EXIT_FAILURE);
    }
    return tree->lst;
};

binaryTreeADT getRightSubtree(binaryTreeADT tree) {
    if (isTreeEmpty(tree)) {
        exit(EXIT_FAILURE);
    }
    return tree->rst;
};

bool isTreeEmpty(binaryTreeADT tree) {
    return tree == (binaryTreeADT)NULL;
};

treeNodeADT createNewNode(char* key, int value) {
    treeNodeADT node = (treeNodeADT)malloc(sizeof(*node));
    // +1 is required for the last value '\0' (which indicates the end of char*)
    node->key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(node->key, key);
    node->nodeData = value;
    return node;
};

int getTreeHeight(binaryTreeADT tree) {
    if (isTreeEmpty(tree)) {
        return 0;
    }
    int lHeight = 1 + getTreeHeight(getLeftSubtree(tree));
    int rHeight = 1 + getTreeHeight(getRightSubtree(tree));
    return lHeight > rHeight ? lHeight : rHeight;
};

char* getNodeKey(treeNodeADT node) {
    if (node == specialErrNode) {
        exit(EXIT_FAILURE);
    }
    char* key = (char*)malloc(sizeof(char) * (strlen(node->key) + 1));
    strcpy(key, node->key);
    return key;
};

int getNodeData(treeNodeADT node) {
    return node->nodeData;
};
