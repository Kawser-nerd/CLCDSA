#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_c"
#define y0 ____y0
#define y1 ____y1
const ldb pi = acos(-1.0);
const int N = 1111;
const int INF = (int) 1.5e9;
int t, w, h, n, ans, x0[N], y0[N], x1[N], y1[N], d[N];
bool used[N];

int cost(int i, int j) {
	int l = 0, r = INF;
	while (l < r) {
		int q = (l + r + 1) / 2;
		if ((max(x0[i] - q, x0[j]) <= min(x1[i] + q, x1[j])) && (max(y0[i] - q, y0[j]) <= min(y1[i] + q, y1[j])))
			r = q - 1;
		else
			l = q;
	}
	return l;
}

int main() {
	assert(freopen(taskname".in", "r", stdin));
	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d%d", &w, &h, &n), n += 2;
		x0[0] = -1, y0[0] = 0, x1[0] = -1, y1[0] = h - 1;
		x0[1] = w, y0[1] = 0, x1[1] = w, y1[1] = h - 1;
		for (int i = 2; i < n; ++i)
			scanf("%d%d%d%d", &x0[i], &y0[i], &x1[i], &y1[i]);
		for (int i = 0; i < n; ++i) {
			d[i] = (i == 0) ? 0 : INF;
			used[i] = false;
		}
		while (!used[1]) {
			int i = -1;
			for (int j = 0; j < n; ++j)
				if (!used[j] && ((i == -1) || (d[j] < d[i]))) i = j;
			assert(i != -1);
			used[i] = true;
			for (int j = 0; j < n; ++j)
				d[j] = min(d[j], d[i] + cost(i, j));
		}
		printf("Case #%d: %d\n", it + 1, d[1]);
	}
	return 0;
}

