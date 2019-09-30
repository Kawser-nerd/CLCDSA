#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 200;
const int maxT = 1010;

bool d[maxN][maxT][maxN];
int n, x[maxN], y[maxN], t[maxN];

vector < pair < int, int > > g[maxN][maxT];

void dfs(int index, int time, int count) {
	if (d[index][time][count]) {
		return ;
	}

	d[index][time][count] = true;

	for (int i = 0; i < g[index][time].size(); ++i) {
		dfs(g[index][time][i].first, g[index][time][i].second, count + 1);
	}
}

int ab(int x) {
	return x > 0 ? x : -x;
}

void solve(int test) {
	memset(d, 0, sizeof(d));

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &x[i], &y[i], &t[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < maxT; ++j) {
			g[i][j].clear();

			for (int k = 0; k < n; ++k) {
				if (k != i) {
					int start_time = t[i] + j;
					int need = start_time + max(ab(x[i] - x[k]), ab(y[i] - y[k])) * 100;

					int cur_time = max(start_time + 750, need);

					if (cur_time <= t[k] + 1000) {
						int start = max(cur_time, t[k]);
						g[i][j].push_back(make_pair(k, (start - t[k])));
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		int d = max(ab(x[i]), ab(y[i]));
		if (d * 100 <= t[i] + 1000) {
			int start = max(d * 100, t[i]);
			dfs(i, (start - t[i]), 1);
		}
	}

	

	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < maxT; ++j) {
			for (int k = 0; k <= n; ++k) {
				if (d[i][j][k]) {
					res = max(res, k);
				}
			}
		}
	}

	printf("Case #%d: %d\n", test, res);
}

void gen() {
	int n = 100;
	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d %d %d\n", rand(), rand(), rand() * rand() + rand());
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	/*printf("100\n");
	for (int i = 0; i < 100; ++i) {
		gen();
	}*/

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << i << endl;
	}
	cerr << clock() << endl;
	return 0;
}