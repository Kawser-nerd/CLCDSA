/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const ll INF = 1e18;
const int N = 100;

int maxd[N], speed[N];
ll d[N][N];
double d2[N][N];

void solve() {
	int n, q;
	scanf("%d%d", &n, &q);
	forn(i, n)
		scanf("%d%d", &maxd[i], &speed[i]);
	forn(i, n)
		forn(j, n)
			scanf("%lld", &d[i][j]);
	forn(i, n)
		d[i][i] = 0;
	forn(i, n)
		forn(j, n)
			if (d[i][j] == -1)
				d[i][j] = INF;
	forn(k, n)
		forn(i, n)
			forn(j, n)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	forn(i, n)
		forn(j, n)
			d2[i][j] = (maxd[i] >= d[i][j] ? 1. * d[i][j] / speed[i] : INF);
	forn(k, n)
		forn(i, n)
			forn(j, n)
				d2[i][j] = min(d2[i][j], d2[i][k] + d2[k][j]);
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b), a--, b--;
		printf(" %.9f", d2[a][b]);
	}
	puts("");

}

int main() {
	int tn;
	scanf("%d", &tn);
	for (int t = 1; t <= tn; t++) {
		printf("Case #%d:", t);
		fprintf(stderr, "Case #%d\n", t);
		solve();
	}
}