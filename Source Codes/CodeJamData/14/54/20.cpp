#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <set>
using namespace std;

int dp[85][85];

struct Arc {
	int f, s, prev;
} arr[505];

bool was[505];
bool cwas[505];

int beg[85];
int kol = 0;

int c[85];

void addArc(int f, int s) {
	arr[kol].f = f;
	arr[kol].s = s;
	arr[kol].prev = beg[f];
	beg[f] = kol++;

	arr[kol].f = s;
	arr[kol].s = f;
	arr[kol].prev = beg[s];
	beg[s] = kol++;
}

int f[85][85];

int DFS(int x, int y, int fail = 0) {
	if (fail == 2) {
		return 0;
	}
	int ret = 0x80000000;
	for (int i = beg[x]; i != -1; i = arr[i].prev) {
		if (!was[i] && !was[i ^ 1]) {
			was[i] = true;
			bool t = cwas[x];
			cwas[x] = true;
			ret = max(ret, (t ? 0 : c[x]) - DFS(y, arr[i].s));
			cwas[x] = t;
			was[i] = false;
		}
	}
	if (ret == 0x80000000) {
		bool t = cwas[x];
		cwas[x] = true;
		int ret = (t ? 0 : c[x]) -DFS(y, x, fail + 1);
		cwas[x] = t;
		return ret;
	}
	return ret;
}

void Solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	memset(beg, -1, sizeof beg);
	kol = 0;
	for (int i = 0; i < n - 1; ++i) {
		int x;
		cin >> x;
		--x;
		addArc(x, i);
	}
	memset(f, -1, sizeof f);
/*	for (int v = 0; v < n; ++v) {
		queue<int> Q;
		f[v][v] = -2;
		Q.push(v);
		while (!Q.empty()) {
			int cur = Q.front();
			for (int i = beg[cur]; i != -1; i = arr[i].prev) {
				if (f[v][arr[i].s] == -1) {
					f[v][arr[i].s] = cur;
				}
			}
		}
	}*/
	memset(was, 0, sizeof was);
	memset(cwas, 0, sizeof cwas);
	int ret = 0x80000000;
	for (int v1 = 0; v1 < n; ++v1) {
		int tret = 0x7f000000;
		for (int v2 = 0; v2 < n; ++v2) {
			tret = min(tret, DFS(v1, v2));
		}
		ret = max(ret, tret);
	}
	printf("%d\n", ret);
}


int main() {
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; ++I) {
		printf("Case #%d: ", I + 1);
		Solve();
	}
	return 0;
}