// examples of data structures for adjacency matrix and adjacency list - needs to be augmented with a List ADT

// Adjacency Matrix
struct matrix {
	int** g;
	int nV;
};

struct matrix * newMatrix(int nV) {
	struct matrix * m = malloc(sizeof(struct matrix));
	m->nV = nV;
	m->g = malloc(nV*sizeof(int*));
	for (int i = 0; i < nV; i++) {
		m->g[i] = malloc(nV*sizeof(int));
		// init g[i][j] to -1
		for (int j = 0; j < nV; j++) {
			m->g[i][j] = -1;
		}

	}
	return m;
}

void insert(struct matrix * m, int u, int v) {
	m->g[u][v] = 1;
	m->g[v][u] = 1;
}


// Adjacency List
struct graphList {
	List * g;
	int nV;
};


struct graphList * newList(int nV) {
	struct graphList* n = malloc(sizeof(struct graphList));
	n->nV = nV;
	n->g = malloc(nV*sizeof(List));
	// iterate through and set to NULL
	for (int i = 0; i < nV; i++) {
		n->g[i] = NULL;
	}
}

void insert(struct graphList * n, int u, int v) {
	ListAppend(n->g[u], v);
	ListAppend(n->g[v], u);
}