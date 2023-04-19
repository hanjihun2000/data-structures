#include <stdlib.h>
#include "treeNode.h"

/*
*	Supplementary treeNode data structure.
*/

struct treeNodeCDT {
	nodeContentT content;
};

treeNodeADT newNode(nodeContentT content) {
	treeNodeADT node = (treeNodeADT)malloc(sizeof(*node));
	node->content = content;
	return node;
};

nodeContentT getNodeContent(treeNodeADT node) {
	return node->content;
};
