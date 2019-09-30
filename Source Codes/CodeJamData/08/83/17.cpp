#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

const long long int MD = 1000000009;

int n, k;
int g[500][501], p[500], d[500];
bool mark[500];
long long int res;

void read_data () {
	cin >> n >> k;
	memset (g, 0, sizeof (g));

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;

		++g[u][0]; g[u][g[u][0]] = v;
		++g[v][0]; g[v][g[v][0]] = u;
	}
}

void dfs_solve (int u, int h) {
	if (mark[u]) return;
	mark[u] = true;

	for (int e = 1; e <= g[u][0]; ++e)
		if (!mark[g[u][e]]) ++d[u];

	if (h == 0) {
		for (int i = 0; i < d[u]; ++i)
			res = (res * (k - i)) % MD;

		for (int e = 1; e <= g[u][0]; ++e)
		{ p[g[u][e]] = u; dfs_solve (g[u][e], h+1); }
	} else if (h == 1) {
		int q = d[p[u]];

		for (int i = 0; i < d[u]; ++i)
			res = (res * (k - i - q)) % MD;

		for (int e = 1; e <= g[u][0]; ++e)
		{ p[g[u][e]] = u; dfs_solve (g[u][e], h+1); }
	} else {
		int q = d[p[u]];
		
		for (int i = 0; i < d[u]; ++i)
			res = (res * (k - i - q - 1)) % MD;

		for (int e = 1; e <= g[u][0]; ++e)
		{ p[g[u][e]] = u; dfs_solve (g[u][e], h+1); }
	}
}

void solve () {
	memset (mark, 0, sizeof (mark));
	memset (d, 0, sizeof (d));
	res = 1;
	dfs_solve (0, 0);

	cout << res << endl;
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t+1 << ": ";

		read_data ();
		solve ();
	}

	return 0;
}
