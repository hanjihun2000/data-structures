#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "digraph.h"
#include "../list/list.h"
#include "../queue/queue.h"

/*
*	Digraph (Directed graph) data structure.
*/

#define MAX 10

struct digraphCDT {
	listADT vertexes[MAX];
	bool isExists[MAX];
};

digraphADT getEmptyDigraph(void) {
	digraphADT graph = (digraphADT)malloc(sizeof(*graph));
	for (int i = 0; i < MAX; i++) {
		graph->isExists[i] = false;
	}
	return graph;
};

// "n" in below functions' argument represents a vertex number "n" where 0 <= n < MAX.

listADT findAdjacentVertexes(digraphADT graph, int n) {
	if (!isVertexExist(graph, n)) {
		exit(EXIT_FAILURE);
	}
	return graph->vertexes[n];
};

static bool isMember(listADT list, int n) {
	if (isListEmpty(list)) {
		return false;
	}
	if (getHead(list) == n) {
		return true;
	}
	return isMember(getTail(list), n);
};

int getVertexDegree(digraphADT graph, int n) {
	int degree = 0;
	for (int i = 0; i < MAX; i++) {
		if (isVertexExist(graph, i)) {
			if (isMember(graph->vertexes[i], n)) {
				degree++;
			}
		}
	}
	return degree;
};

void addVertex(digraphADT graph, int n) {
	if (!isVertexExist(graph, n)) {
		graph->vertexes[n] = getEmptyList();
		graph->isExists[n] = true;
	}
};
 
// Add arc from vertex 'n' to vertex 'm'.
// "n" indicates a vertex where it starts and "m" shows a vertex where it ends.
void addArc(digraphADT graph, int n, int m) {
	if (isVertexExist(graph, n) && isVertexExist(graph, m)) {
		graph->vertexes[n] = concat(m, graph->vertexes[n]);
	}
};

bool isVertexExist(digraphADT graph, int n) {
	return graph->isExists[n];
};

bool isDigraphEmpty(digraphADT graph) {
	for (int i = 0; i < MAX; i++) {
		if (isVertexExist(graph, i)) {
			return false;
		}
	}
	return true;
};

void TopologicalSort(digraphADT graph) {
	queueADT queue = getEmptyQueue();
	int degreeOfVertexes[MAX];
	for (int i = 0; i < MAX; i++) {
		if (isVertexExist(graph, i)) {
			degreeOfVertexes[i] = getVertexDegree(graph, i);
			if (degreeOfVertexes[i] == 0) {
				enqueue(queue, i);
			}
		}
	}
	while (!isQueueEmpty(queue)) {
		int vertex = dequeue(queue);
		printf("Dequeue vertex %d.\n", vertex);
		for (listADT list = findAdjacentVertexes(graph, vertex); !isListEmpty(list); list = getTail(list)) {
			if (--degreeOfVertexes[getHead(list)] == 0) {
				enqueue(queue, getHead(list));
			}
		}
	}
};
