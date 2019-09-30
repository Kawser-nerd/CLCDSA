#include <stdio.h>
#include <stdlib.h>

#define MOD_BY 1000000007

/*
N nodes
N-1 edges
renketu
-> KI
*/

int N;
struct edge_t {
	int a, b;
} edge[2000001];
int edge_start[1000000];

int cmp(const void* x, const void* y) {
	const struct edge_t* xx = x;
	const struct edge_t* yy = y;
	if (xx->a > yy->a) return 1;
	if (xx->a < yy->a) return -1;
	if (xx->b > yy->b) return 1;
	if (xx->b < yy->b) return -1;
	return 0;
}

int mul(int x, int y) {
	int ret = 0;
	int cur = x;
	while (y > 0) {
		if ((y & 1) == 1) {
			if ((ret = ret + cur) >= MOD_BY) ret -= MOD_BY;
		}
		if ((cur = cur + cur) >= MOD_BY) cur -= MOD_BY;
		y >>= 1;
	}
	return ret;
}

/* [edge][0->prev is white 1->pre is black] */
int memo[1000000][2];

int search(int e, int p, int parent) {
	int ret = 1, ret2 = 0, i;
	if (memo[e][p] != 0) return ~memo[e][p];
	/* siroku nuru */
	for (i = edge_start[e]; edge[i].a == e; i++) {
		if (edge[i].b != parent) ret = mul(ret, search(edge[i].b, 0, e));
	}
	/* kuroku nuru */
	if (p == 0) {
		ret2 = 1;
		for (i = edge_start[e]; edge[i].a == e; i++) {
			if (edge[i].b != parent) ret2 = mul(ret2, search(edge[i].b, 1, e));
		}
		if ((ret += ret2) >= MOD_BY) ret -= MOD_BY;
	}
	return ~(memo[e][p] = ~ret);
}

int main(void) {
	int i;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N - 1; i++) {
		if (scanf("%d%d", &edge[i * 2].a, &edge[i * 2].b) != 2) return 1;
		/* dekurimennto suru!! */
		edge[i * 2 + 1].a = --edge[i * 2].b;
		edge[i * 2 + 1].b = --edge[i * 2].a;
	}
	qsort(edge, N * 2 - 2, sizeof(*edge), cmp);
	edge[N * 2 - 2].a = edge[N * 2 - 2].b = N; /* ban-hei */
	/* sono node kara nobiru edge no saisyo no soezi wo motomeru */
	for (i = N * 2 - 3; i >= 0; i--) {
		edge_start[edge[i].a] = i;
	}
	printf("%d\n", search(0, 0, -1));
	return 0;
}