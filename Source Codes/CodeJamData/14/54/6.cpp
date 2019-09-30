#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 100;
const int inf = 1000000000;
vector < int > g[maxN];
int n, c[maxN], h[maxN];

void read_data(int test) {
}

bool broken[maxN][maxN];

bool is_reachable(int u, int v) {
	vector < bool > used(n + 1, false);
	used[u] = true;
	queue < int > q;
	q.push(u);

	while (!q.empty()) {
		int t = q.front();
		q.pop();

		for (int i = 0; i < g[t].size(); ++i) {
			if (!broken[t][g[t][i]] && !used[g[t][i]]) {
				used[g[t][i]] = true;
				q.push(g[t][i]);
			}
		}
	}
	return used[v];
}

int get(int v) {
	vector < int > d(n + 1, -1);
	d[v] = h[v];
	queue < int > q;
	q.push(v);

	while (!q.empty()) {
		int t = q.front();
		q.pop();

		for (int i = 0; i < g[t].size(); ++i) {
			if (!broken[t][g[t][i]] && d[g[t][i]] == -1) {
				d[g[t][i]] = d[t] + h[g[t][i]];
				q.push(g[t][i]);
			}
		}
	}

	return *max_element(d.begin(), d.end());
}

int rec(int u, int v, int first = 0, int second = 0, int move = 0) {
	if (!is_reachable(u, v)) {
		first += get(u);
		second += get(v);
		if (move == 0) {
			return first - second;
		} else {
			return second - first;
		}
	}

	if (u == v) {
		bool all_broken = true;
		for (int i = 0; i < g[u].size(); ++i) {
			if (!broken[u][g[u][i]]) {
				all_broken = false;
			}
		}
		if (all_broken && h[u] == 0) {
			if (move == 0) {
				return first - second;
			} else {
				return second - first;
			}
		}
	}

	if (move == 0) {
		int res = -inf;
		for (int i = 0; i < g[u].size(); ++i) {
			if (!broken[u][g[u][i]]) {
				int oldu = h[u];
				h[u] = 0;
				broken[u][g[u][i]] = broken[g[u][i]][u] = true;
				res = max(res, -rec(g[u][i], v, first + oldu, second, 1));
				h[u] = oldu;
				broken[u][g[u][i]] = broken[g[u][i]][u] = false;
			}
		}
		if (res == -inf) {
			int oldu = h[u];
			h[u] = 0;
			res = max(res, -rec(u, v, first + oldu, second, 1));
			h[u] = oldu;
		}
		return res;
	} else {
		int res = -inf;
		for (int i = 0; i < g[v].size(); ++i) {
			if (!broken[v][g[v][i]]) {
				int oldv = h[v];
				h[v] = 0;
				broken[v][g[v][i]] = broken[g[v][i]][v] = true;
				res = max(res, -rec(u, g[v][i], first, second + oldv, 0));
				h[v] = oldv;
				broken[v][g[v][i]] = broken[g[v][i]][v] = false;
			}
		}
		if (res == -inf) {
			int oldv = h[v];
			h[v] = 0;
			res = max(res, -rec(u, v, first, second + oldv, 0));
			h[v] = oldv;
		}
		return res;
	}
}

int calc(int u, int v) {
	memset(broken, 0, sizeof(broken));
	for (int i = 1; i <= n; ++i) {
		h[i] = c[i];
	}

	return rec(u, v);
}

void solve(int test) {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		g[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int j;
		cin >> j;
		g[i].push_back(j);
		g[j].push_back(i);
	}

	int res = -inf;
	for (int i = 1; i <= n; ++i) {
		int cur = inf;
		for (int j = 1; j <= n; ++j) {
			cur = min(cur, calc(i, j));
		}
		res = max(res, cur);
	}
	printf("Case #%d: %d\n", test, res);
}

int main(int argc, char* argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen(argv[3], "w", stdout);

	int left_bound, right_bound;
	//sscanf(argv[1], "%d", &left_bound);
	//sscanf(argv[2], "%d", &right_bound);

	int tests;
	scanf("%d", &tests);
	left_bound = 1;
	right_bound = tests;
	for (int i = 1; i <= tests; ++i) {
		if (i >= left_bound && i <= right_bound) {
			solve(i);
			cerr << i << ": " << clock() << endl;
		} else {
			read_data(i);
		}
	}
	return 0;
}