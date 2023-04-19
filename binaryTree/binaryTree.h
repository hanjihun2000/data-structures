#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include <stdbool.h>

typedef struct binaryTreeCDT* binaryTreeADT;
typedef struct treeNodeCDT* treeNodeADT;
#define specialErrNode (treeNodeADT) NULL

binaryTreeADT getEmptyBinaryTree(void);
binaryTreeADT getNonEmptyBinaryTree(treeNodeADT N, binaryTreeADT L, binaryTreeADT R);
binaryTreeADT getLeftSubtree(binaryTreeADT);
binaryTreeADT getRightSubtree(binaryTreeADT);
bool isTreeEmpty(binaryTreeADT);
treeNodeADT getRoot(binaryTreeADT);
treeNodeADT createNewNode(char*, int);
int getTreeHeight(binaryTreeADT);
int getNodeData(treeNodeADT);
char* getNodeKey(treeNodeADT);

#endif // BINARYTREE_H_INCLUDED
