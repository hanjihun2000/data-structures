#ifndef DIGRAPH_H_INCLUDED
#define DIGRAPH_H_INCLUDED
#include <stdbool.h>
#include "../list/list.h"

typedef struct digraphCDT* digraphADT;

digraphADT getEmptyDigraph(void);
listADT findAdjacentVertexes(digraphADT, int);
int getVertexDegree(digraphADT, int);
void addVertex(digraphADT, int);
void addArc(digraphADT, int, int);
bool isVertexExist(digraphADT, int);
bool isDigraphEmpty(digraphADT);
void TopologicalSort(digraphADT);

#endif // DIGRAPH_H_INCLUDED
