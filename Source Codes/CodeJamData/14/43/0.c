#include <stdio.h>
#include <stdlib.h>

typedef struct _edge *edge;

struct _edge {
	int to;
	int cap;
	edge inv;
	edge next;
};

int W, H, B;

int grid[501][101];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int V;
int s, t;
int upTo;
struct _edge cache[7 * 500 * 100 * 2 * 2];
edge allFrom[2 * 500 * 100 + 5];
int seen[2 * 500 * 100 + 5];

void addEdge (int from, int to, int cap) {
	edge e1 = &cache[upTo++];
	edge e2 = &cache[upTo++];
	e1->to = to;
	e1->cap = cap;
	e1->inv = e2;
	e1->next = allFrom[from];
	allFrom[from] = e1;
	e2->to = from;
	e2->cap = 0;
	e2->inv = e1;
	e2->next = allFrom[to];
	allFrom[to] = e2;
}

void clear() {
	int i;
	for (i = 0; i < V; i++) {
		seen[i] = 0;
	}
}

int augment(int at, int t, int f) {
	if (at == t) {
		return 1;
	}
	if (seen[at]) {
		return 0;
	}
	seen[at] = 1;
	edge e;
	for (e = allFrom[at]; e; e = e->next) {
		if (e->cap >= f && augment(e->to, t, f)) {
			e->cap -= f;
			e->inv->cap += f;
			return 1;
		}
	}
	return 0;
}

int maxflow() {
	clear();
	int res = 0;
	while (augment(s, t, 1)) {
		clear();
		res++;
	}
	return res;
}

void handle() {
	upTo = 0;
	scanf ("%d %d %d ", &W, &H, &B);
	int i, j, k;
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			grid[i][j] = 1;
		}
	}
	for (i = 0; i < B; i++) {
		int x1, x2, y1, y2;
		scanf ("%d %d %d %d ", &x1, &y1, &x2, &y2);
		for (j = y1; j <= y2; j++) {
			for (k = x1; k <= x2; k++) {
				grid[j][k] = 0;
			}
		}
	}
	V = W * H * 2 + 2;
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (grid[i][j]) {
				for (k = 0; k < 4; k++) {
					int x = j + dx[k];
					int y = i + dy[k];
					if (x >= 0 && x < W && y >= 0 && y < H) {
						if (grid[y][x]) {
							addEdge((i * W + j) * 2 + 1, (y * W + x) * 2, 1);
						}
					}
				}
				addEdge((i * W + j) * 2, (i * W + j) * 2 + 1, 1);
			}
		}
	}
	s = V - 1;
	t = V;
	for (i = 0; i < W; i++) {
		if (grid[0][i]) {
			addEdge(s, i * 2, 1);
		}
		if (grid[H - 1][i]) {
			addEdge(((H - 1) * W + i) * 2 + 1, t, 1);
		}
	}
	printf ("%d\n", maxflow());
	for (i = 0; i <= V; i++) {
		allFrom[i] = NULL;
	}
}

int main() {
	int t;
	scanf ("%d ", &t);
	int i;
	for (i = 0; i < t; i++) {
		printf ("Case #%d: ", i + 1);
		handle();
	}
	return 0;
}