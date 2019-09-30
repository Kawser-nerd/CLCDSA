#include "stdio.h"
#include "memory.h"
#include "assert.h"

#define MAXN 500
#define EPS 1e-10

int n;
int res[MAXN][MAXN];
int ca[MAXN][MAXN];
int e[MAXN][MAXN];
int d[MAXN];
int g[MAXN];


int poisk (int v, int w) {
	assert (v != 1);
	if (res[v][w] >= 0) return res[v][w];
	int cc = 0;
	int i;
	for (i = 0; i < n; i++) if (e[v][i] && v != i) {
		cc ++;
	}
	if (e[v][1]) {
		res[v][w] = cc;
		return cc;
	}
	int bi = -n;
	for (i = 0; i < n; i++) if (e[v][i] && d[i] == d[v] - 1) {
		int j;
		int dd = -2 - ca[v][i];
		if (w < n) dd -= (ca[w][i] - 1);
		dd += poisk (i, v);
		if (dd > bi) bi = dd;
	}
	assert (bi > -n);
	res[v][w] = bi + cc;
	return res[v][w];
}

int main () {
	int tn;
	scanf ("%d\n", &tn);
	int i;
	
	int tt;

	for (tt = 0; tt < tn; tt++) {
		int ee;
		scanf ("%d %d", &n, &ee);
		for (i = 0; i < n; i++) {
			g[i] = 0;
			d[i] = n + 1;
	  }
	  int j;
	  for (i = 0; i <= n; i++)
	  	for (j = 0; j <= n; j++) {
	  		e[i][j] = 0;
	  		res[i][j] = -1;
	  		ca[i][j] = 0;
	  	}
		for (i = 0; i < ee; i++) {
			int x, y;
			scanf ("%d,%d", &x, &y);
			e[x][y] = 1;
			e[y][x] = 1;
		}

		d[1] = 0;
		for (i = 0; i < n; i++) {
			int bb = n;
			int bi = -1;
			int j;
			for (j = 0; j < n; j++) if (!g[j] && bb > d[j]) {
				bi = j;
				bb = d[j];
			}
			assert (bi >= 0);
			if (bi == 0) break;
			g[bi] = 1;
			for (j = 0; j < n; j++) if (!g[j] && e[bi][j] && d[j] > bb + 1) {
				d[j] = bb + 1;
			} 
		}
		assert (d[0] <= n);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) if (i < j && abs (d[i] - d[j]) > 0 && abs (d[i]-d[j]) <= 2) {
				int k;
				for (k = 0; k < n; k++) if (k != i && k != j && e[k][i] && e[k][j]) {
					ca[i][j] ++;
				}
				ca[j][i] = ca[i][j];
				//fprintf (stderr, "%d %d %d\n", i, j, ca[i][j]);
			}
		printf ("Case #%d: %d %d\n", tt + 1, d[0] - 1, poisk (0, n));
	}
	return 0;
}
