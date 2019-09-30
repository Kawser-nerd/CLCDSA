#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 80 + 10, INF = ~0U >> 3;

vector<int> E[MAX_N];
int n, C[MAX_N];

int eid[MAX_N][MAX_N];
bool used[MAX_N];

int memo[MAX_N][MAX_N][MAX_N][MAX_N][2];
bool save[MAX_N][MAX_N][MAX_N][MAX_N][2];

int dfs(int s1, int e1, int s2, int e2, bool opMove = true) { //1 moves
	if (save[s1][e1][s2][e2][opMove])
		return memo[s1][e1][s2][e2][opMove];

	save[s1][e1][s2][e2][opMove] = true;
	int&ret = memo[s1][e1][s2][e2][opMove] = -INF;

	if (!opMove) {
		ret = C[e1];

		for (int nxt : E[e1]) {
			int e = eid[e1][nxt];
			if (used[e])
				continue;
			used[e] = true;
			int old = C[e1];
			C[e1] = 0;
			ret = max(ret, old + dfs(s1, nxt, s2, e2, false));
			C[e1] = old;
			used[e] = false;
		}

		return ret;
	}

	for (int nxt : E[e1]) {
		int e = eid[e1][nxt];
		if (used[e])
			continue;
		used[e] = true;
		int old = C[e1];
		C[e1] = 0;
		ret = max(ret, old - dfs(s2, e2, s1, nxt));
		C[e1] = old;
		used[e] = false;
	}

	if (ret == -INF) {
		int old = C[e1];
		C[e1] = 0;
		ret = old - dfs(s2, e2, s1, e1, false);
		C[e1] = old;
		return ret;
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		printf("Case #%d: ", nc);
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> C[i];
			E[i].clear();
		}
		for (int i = 0; i < n - 1; ++i) {
			int a;
			cin >> a, --a;
//			cout << a << " <-> " << i << endl;
			E[a].push_back(i), E[i].push_back(a);
			eid[a][i] = eid[i][a] = i;
		}

		memset(save, 0, sizeof save);
		memset(used, 0, sizeof used);

		int best = -INF;
		for (int a = 0; a < n; ++a) {
			int ret = INF;
			for (int b = 0; b < n; ++b) {
				ret = min(ret, dfs(a, a, b, b));
			}
			best = max(best, ret);
		}
		cout << best << endl;
	}
}
