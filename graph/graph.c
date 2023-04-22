#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "graph.h"
#include "../list/list.h"

/*
*   Graph (undirected) data structure.
*/

#define MAX_NODE 100

struct graphCDT {
    float W[MAX_NODE * (MAX_NODE + 1) / 2];
    bool isNodeExists[MAX_NODE];
};

graphCDT getEmptyGraph() {
    graphCDT graph;
    graph = (graphCDT)malloc(sizeof(*graph));
    for (int n = 0; n < MAX_NODE * (MAX_NODE + 1) / 2; n++) {
        graph->W[n] = INFINITY;
    }
    for (int n = 0; n < MAX_NODE; n++) {
        graph->isNodeExists[n] = false;
    }
    return graph;
};

bool isGraphEmpty(graphCDT graph) {
    for (int n = 0; n < MAX_NODE; n++) {
        if (isNodeExists(graph, n)) {
            return false;
        }
    }
    return true;
};

void addNode(graphCDT graph, node i) {
    graph->isNodeExists[i] = true;
};

bool isNodeExists(graphCDT graph, node i) {
    return graph->isNodeExists[i];
};

listADT getAdjacentNodes(graphCDT graph, node i) {
    if (!isNodeExists(graph, i)) {
        exit(EXIT_FAILURE);
    }
    listADT adjList = getEmptyList();
    for (int n = 0; n < MAX_NODE; n++) {
        if (isArcExists(graph, i, n)) {
            adjList = concat(n, adjList);
        }
    }
    return adjList;
};

int degree(graphCDT graph, node i) {
    listADT adjList = getAdjacentNodes(graph, i);
    int degree = 0;
    while (!isListEmpty(adjList)) {
        degree++;
        adjList = getTail(adjList);
    }
    return degree;
};

void addArc(graphCDT graph, node i, node j, float w) {
    if (!isNodeExists(graph, i) || !isNodeExists(graph, j)) {
        exit(EXIT_FAILURE);
    }
    int x;
    if (i > j) {
        x = i + j * MAX_NODE - j * (j + 1) / 2;
    }
    else {
        x = j + i * MAX_NODE - i * (i + 1) / 2;
    }
    graph->W[x] = w;
};

float getArcWeight(graphCDT graph, node i, node j) {
    return graph->W[arcToIndex(graph, i, j)];
};

bool isArcExists(graphCDT graph, node i, node j) {
    int x;
    if (i > j) {
        x = i + j * MAX_NODE - j * (j + 1) / 2;
    }
    else {
        x = j + i * MAX_NODE - i * (i + 1) / 2;
    }
    float f = graph->W[x];
    if (isinf(f)) {
        return false;
    }
    return true;
};

void printAllNodes(graphCDT graph) {
    for (int i = 0; i < MAX_NODE; i++) {
        if (isNodeExists(graph, i)) {
            printf("%d\n", i);
        }
    }
};

void printAllArcs(graphCDT graph) {
    for (int n = 0; n < MAX_NODE * (MAX_NODE + 1) / 2; n++) {
        float f = graph->W[n];
        if (isfinite(f)) {
            int* i = (int*)malloc(sizeof(*i));
            int* j = (int*)malloc(sizeof(*j));
            indexToArcNodes(graph, n, i, j);
            printf("(%d,%d) %d\n", *i, *j, (int)f);
        }
    }
};

int arcToIndex(graphCDT graph, node i, node j) {
    if (!isArcExists(graph, i, j)) {
        exit(EXIT_FAILURE);
    }
    return j + (i * MAX_NODE) - (i * (i + 1) / 2);
};

void indexToArcNodes(graphCDT graph, int x, node* i, node* j) {
    int m = 1;
    int n, x1;
    while (x >= (x1 = m * MAX_NODE - m * (m - 1) / 2)) {
        m++;
    }
    m--;
    n = MAX_NODE + x - x1;
    // The arc is (m,n), or ((*i),(*j))
    (*i) = m;
    (*j) = n;
};
