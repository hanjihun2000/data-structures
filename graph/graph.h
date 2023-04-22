#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "../list/list.h"
#include <stdbool.h>

typedef struct graphCDT* graphCDT;
typedef int node;

graphCDT getEmptyGraph(void);
bool isGraphEmpty(graphCDT);

void addNode(graphCDT, node);
bool isNodeExists(graphCDT, node);
listADT getAdjacentNodes(graphCDT, node);
int degree(graphCDT, node);

void addArc(graphCDT, node, node, float);
float getArcWeight(graphCDT, node, node);
bool isArcExists(graphCDT, node, node);

void printAllNodes(graphCDT);
void printAllArcs(graphCDT);

int arcToIndex(graphCDT, node, node);
void indexToArcNodes(graphCDT, int, node*, node*);

#endif // GRAPH_H_INCLUDED
