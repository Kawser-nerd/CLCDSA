#include <stdio.h>

#define INF 1000000000000000000

#define min(a, b) ((a) < (b) ? a : b)

double adj[100][100];
double d[100];
int flag[100];

void dijkstra(int n, int s) {
	int i;

	for (i = 0; i < n; i++) {
		d[i] = INF;
		flag[i] = 0;
	}

	d[s] = 0;
	while (1) {
		double min;
		int from, to;

		min = INF;
		for (i = 0; i < n; i++)
			if (!flag[i] && d[i] < min)
				min = d[from = i];
		if (min == INF)
			break;

		flag[from] = 1;

		for (to = 0; to < n; to++)
			d[to] = min(d[to], min + adj[from][to]);
	}
}

int main(void) {
	int i, j, k;
	int t, c;

	scanf("%d", &t);
	for (c = 1; c <= t; c++) {
		int n, q;
		long long e[100], s[100];
		long long dis[100][100];

		scanf("%d %d", &n, &q);
		for (i = 0; i < n; i++)
			scanf("%lld %lld", e + i, s + i);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				scanf("%lld", dis[i] + j);
				if (dis[i][j] == -1)
					dis[i][j] = INF;
			}

		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (dis[i][k] + dis[k][j] < dis[i][j])
						dis[i][j] = dis[i][k] + dis[k][j];

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				adj[i][j] = dis[i][j] == INF || e[i] < dis[i][j] ? INF : (double)dis[i][j] / s[i];

		printf("Case #%d:", c);
		for (i = 0; i < q; i++) {
			int u, v;

			scanf("%d %d", &u, &v);
			u--; v--;

			dijkstra(n, u);

			printf(" %.10f", d[v]);
		}
		putchar('\n');
	}

	return 0;
}
