#include <stdio.h>

typedef struct {
	int b;
	int next;
	int snext;
} edge_t;

int edgen;
edge_t edges[5000];
int dist[500];
int graph[500];
int sgraph[500];

int qk, qn, queue[500];

int threatn;
int threat[500];

int bestthreat;

void dfs(int a, int l)
{
	int e;
	for (e = graph[a]; e != -1; e = edges[e].next) {
		int b = edges[e].b;
		if (threat[b] == -1) {
			threat[b] = l;
			threatn++;
		}
	}
	for (e = graph[a]; e != -1; e = edges[e].next) {
		int b = edges[e].b;
		if (b == 1) {
			if (l == dist[1] && threatn > bestthreat) bestthreat = threatn;
			goto end;
		}
	}
/*
	for (e = sgraph[a]; e != -1; e = edges[e].snext) {
		int b = edges[e].b;
		dfs(b, l+1);
	}
*/
	for (e = graph[a]; e != -1; e = edges[e].next) {
		int b = edges[e].b;
		if (threat[b] == l) dfs(b, l+1);
	}
end:
	for (e = graph[a]; e != -1; e = edges[e].next) {
		int b = edges[e].b;
		if (threat[b] == l) {
			threat[b] = -1;
			threatn--;
		}
	}
}

int main(void)
{
	int t, ti;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		int p, w, i, e;
		scanf("%d %d", &p, &w);
		for (i = 0; i < p; i++) graph[i] = sgraph[i] = dist[i] = threat[i] = -1;
		edgen = 0;
		for (i = 0; i < w; i++) {
			int a, b;
			scanf("%d,%d", &a, &b);
			edges[edgen].b = b;
			edges[edgen].next = graph[a];
			graph[a] = edgen++;
			edges[edgen].b = a;
			edges[edgen].next = graph[b];
			graph[b] = edgen++;
		}
		qk = 0;
		qn = 1;
		queue[0] = 0;
		dist[0] = 0;
		while (qk < qn) {
			int a, d;
			a = queue[qk++];
			d = dist[a];
			for (e = graph[a]; e != -1; e = edges[e].next) {
				int b = edges[e].b;
				if (dist[b] == -1) {
					queue[qn++] = b;
					dist[b] = d+1;
				}
/*
				if (dist[b] == d+1) {
					edges[e].snext = sgraph[a];
					sgraph[a] = e;
				}
*/
			}
		}
		threat[0] = 0;
		threatn = 1;
		bestthreat = 0;
		dfs(0, 1);
		printf("Case #%d: %d %d\n", ti, dist[1]-1, bestthreat-dist[1]);
	}
	return 0;
}