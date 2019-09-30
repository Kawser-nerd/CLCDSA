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

const int maxN = 6000;

int n, m, x[maxN], y[maxN];
int p[maxN][2][2];

int u, v, z, t;
long long best;

long long dist() {
	long long dx = u - t;
	long long dy = v + z;
	return dx * dx + dy * dy;
}

vector < pair < int, int > > possible[maxN];

void rec(int current) {
	if (current == 4) {
		best = max(best, dist());
		return ;
	}

	int x = current / 2;
	int y = current % 2;
	int steps = p[m][x][y];
	for (int i = 0; i < possible[steps].size(); ++i) {
		int dx = possible[steps][i].first;
		int dy = possible[steps][i].second;

		u += (x == 0 ? dx : -dx);
		v += (x == 0 ? dy : -dy);

		z += (y == 0 ? dx : -dx);
		t += (y == 0 ? dy : -dy);

		rec(current + 1);

		u -= (x == 0 ? dx : -dx);
		v -= (x == 0 ? dy : -dy);

		z -= (y == 0 ? dx : -dx);
		t -= (y == 0 ? dy : -dy);
	}
}

void precalc(int have, int u = 0, int v = 0, int last = 0) {
	if (have > m) {
		return ;
	}
	possible[have].push_back(make_pair(u, v));
	if (last == n) {
		return ;
	}

	for (int i = last; i < n; ++i) {
		for (int j = 1; j <= m - have; ++j) {
			precalc(have + j, u + j * x[i], v + j * y[i], i + 1);
		}
	}
}

void solve(int test) {
	memset(p, 0, sizeof(p));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}

	for (int i = 0; i <= m; ++i) {
		possible[i].clear();
	}

	p[1][1][1] = 1;
	for (int i = 2; i <= m; ++i) {
		p[i][0][0] = p[i - 1][1][0];
		p[i][0][1] = p[i - 1][0][0];
		p[i][1][0] = p[i - 1][1][1];
		p[i][1][1] = p[i - 1][0][1] + 1;
	}

	best = 0;
	u = v = z = t = 0;
	precalc(0);
	for (int moves = m; moves > 0; --moves) {
		m = moves;
		rec(0);
	}

	printf("Case #%d: %.10lf\n", test, sqrt((double)(best)));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << i << endl;
	}
	cerr << clock() << endl;
	return 0;
}