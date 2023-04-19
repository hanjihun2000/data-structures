#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED
#include <stdlib.h>

typedef struct treeNodeCDT* treeNodeADT;
// Only store one character in a node.
typedef char nodeContentT;

treeNodeADT newNode(nodeContentT);
nodeContentT getNodeContent(treeNodeADT);

#endif // TREENODE_H_INCLUDED
