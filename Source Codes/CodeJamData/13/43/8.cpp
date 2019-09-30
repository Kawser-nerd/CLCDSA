#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <cassert>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

vector<int> g[2010], order;
int n, a[2010], b[2010], f[2010], ans[2010], inc[2010];
bool u[2010];

void edge(int i, int j) {
	// printf("%d -> %d\n", i, j);
	g[i].pb(j);
	inc[j]++;
}

void dfs(int i) {
	u[i] = true;

	forn(j, g[i].size())
		if (!u[ g[i][j] ])
			dfs( g[i][j] );

	order.pb(i);
}

void calc() {
	forn(i, n) {
		f[i] = 1;
		forn(j, i)
			if (ans[j] < ans[i] && f[j] + 1 > f[i])
				f[i] = f[j] + 1;
	}
}

void solve() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);
	forn(i, n) scanf("%d", &b[i]);
	forn(i, n) g[i].clear(), inc[i] = 0;

	for (int i = 1; i < n; i++) {
		forn(j, i)
			if (a[j] >= a[i]) edge(i, j);
		// int mx = 0;
		for (int j = i - 1; j >= 0; j--)
			if (a[j] == a[i] - 1) {
				edge(j, i);
				break;
			} else if (a[j] < a[i]) edge(j, i);
	}

	for (int i = n-2; i>=0; i--) {
		for (int j = i + 1; j < n; j++)
			if (b[j] >= b[i])  edge(i, j);
		// int mx = 0;
		for (int j = i + 1; j < n; j++)
			if (b[j] == b[i] - 1) {
				edge(j, i);
				break;
			} else if (b[j] < b[i]) edge(j, i);
	}

	memset(u, 0, sizeof(u));
	order.clear();
	forn(i, n) {
		int mj = -1;
		forn(j, n)
			if (inc[j] == 0 && !u[j]) {
				mj = j;
				break;
			}
		order.pb(mj);
		u[mj] = true;
		forn(j, g[mj].size())
			inc[ g[mj][j] ]--;
		// printf("mj = %d\n", mj);
	}


	forn(i, n) ans[ order[i] ] = i + 1;
	forn(i, n) printf(" %d", ans[i]);
	printf("\n");

	calc();
	forn(i, n) if (a[i] != f[i]) fprintf(stderr, "WRONG!!!\n");
	reverse(ans, ans+n);
	calc();
	reverse(f, f+n);
	forn(i, n) if (b[i] != f[i]) fprintf(stderr, "WRONG!!!\n");
	fprintf(stderr, "Check complete.\n");
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d:", q);
		solve();
		fprintf(stderr, "Case %d done.\n", q);
	}
	return 0;
}