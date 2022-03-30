#include "Graph.h"
#include <stdlib.h>

bool isEulerPath(Graph g, Edge e[], int nE) {
	// 1. Number of edges === number of edges in the graph
	int edges = 0;
	int nV = GraphNumVertices(g);
	for (int v = 0; v < nV; v++) {
		for (int u = v + 1; u < nV; u++) {
			if (GraphIsAdjacent(g, u, v)) edges++;
		}
	}
	if (nE != edges) return false;
	// 2. No edge is repeated in our edge array
	int ** seen = malloc(nV*sizeof(int*));
	for (int i = 0; i < nV; i++) {
		seen[i] = calloc(nV, sizeof(int));
	}
	for (int i = 0; i < nE; i++) {
		if (seen[e[i].v][e[i].w] == 1) return false;
		seen[e[i].v][e[i].w] = 1;
		seen[e[i].w][e[i].v] = 1;
	}
	return true;
}

int main(void) {
	Graph g = GraphRead();
	int nE;
	Edge* e = EdgeRead(&nE);
	printf("Is Euler path? %s\n", isEulerPath(g, e, nE) ? "True" : "False");
	GraphFree(g);
	free(e);
	return 0;
}