#include "Graph.h"
#include <stdlib.h>
#include "Set.h"

void dfs(Graph g, Vertex v, Set s, int* visited) {
	for (Vertex u = 0; u < GraphNumVertices(g); u++) {
		if (GraphIsAdjacent(g,v,u) && visited[u] == 0) {
			visited[u] = 1;
			SetInsert(s, u);
			dfs(g, u, s, visited);
		}
	}
}


Set reachable(Graph g, Vertex src) {
	Set s = newSet();
	SetInsert(s, src);
	int * visited = calloc(GraphNumVertices(g), sizeof(int));
	visited[src] = 1;
	dfs(g, src, s, visited);
	return s;
}

int main(void) {
	Graph g = GraphRead();
	printf("Reachable nodes: \n");
	Set s = reachable(g, 0);
	showSet(s);
	GraphFree(g);
	dropSet(s);
	return 0;
}