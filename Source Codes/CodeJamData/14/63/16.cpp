#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
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
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;


struct Arc {
	int f, s, prev;
} arr[100005];

int beg[10005], kol = 0;

void AddArc(int f, int s) {
	arr[kol].f = f;
	arr[kol].s = s;
	arr[kol].prev = beg[f];
	beg[f] = kol++;

	arr[kol].f = s;
	arr[kol].s = f;
	arr[kol].prev = beg[s];
	beg[s] = kol++;
}

map<vector<int>, int> M;
int qc = 0;

int tp[10005];

int d[10005];
int c[10005];

void DFS(int v, int depth = 0, int p = -1) {
	d[v] = depth;
	for (int i = beg[v]; i != -1; i = arr[i].prev) {
		if (arr[i].s == p) {
			continue;
		}
		DFS(arr[i].s, depth + 1, v);
	}
}

int DFS2(int v1, int v2, int depth, int p = -1) {
	if (v1 == v2) {
		if (depth == 0) {
			return v1;
		}
		else {
			return -2;
		}
	}
	for (int i = beg[v1]; i != -1; i = arr[i].prev) {
		if (arr[i].s == p) {
			continue;
		}
		int v = DFS2(arr[i].s, v2, depth - 1, v1);
		if (v >= 0) {
			return v;
		}
		else if (v == -2) {
			if (depth == 0) {
				v = v1;
			}
			return v;
		}
	}
	return -1;
}

int DFS3(int v, int depth = 0, int p = -1) {
	if (c[v]) {
		return c[v];
	}
	vector<int> clr;
	for (int i = beg[v]; i != -1; i = arr[i].prev) {
		if (arr[i].s == p) {
			continue;
		}
		clr.push_back(DFS3(arr[i].s, depth + 1, v));
	}
	sort(clr.begin(), clr.end());
	clr.push_back(depth);
	clr.push_back(tp[v]);
	const auto itr = M.find(clr);
	if (itr != M.end()) {
		return itr->second;
	}
	return M[clr] = ++qc;
}

bool Solve(int target, int p = -1) {
	vector<int> clr;
	for (int i = beg[target]; i != -1; i = arr[i].prev) {
		if (arr[i].s == p) {
			continue;
		}
		clr.push_back(DFS3(arr[i].s));
	}
	vector<char> paired;
	sort(clr.begin(), clr.end());
	for (int i = 0; i + 1 < clr.size(); ++i) {
		if (clr[i] == clr[i + 1]) {
			paired.push_back(1);
			paired.push_back(1);
			++i;
		}
		else {
			paired.push_back(0);
		}
	}
	if (paired.size() != clr.size()) {
		paired.push_back(0);
	}
	vector<int> failed;
	for (int i = 0; i < paired.size(); ++i) {
		if (!paired[i]) {
			failed.push_back(clr[i]);
		}
	}
	if (failed.size() > 2 || failed.size() == 2 && p != -1) {
		return false;
	}
	for (int j = 0; j < failed.size(); ++j) {
		for (int i = beg[target]; i != -1; i = arr[i].prev) {
			if (arr[i].s == p || DFS3(arr[i].s) != failed[j]) {
				continue;
			}
			if (!Solve(arr[i].s, target)) {
				return false;
			}
		}
	}
	return true;
}

void Solve() {
	M.clear();
	memset(beg, -1, sizeof beg);
	kol = 0;
	int n;
	scanf("%d", &n);
	char buf[10];
	for (int i = 0; i < n; ++i) {
		scanf("%s", buf);
		tp[i] = buf[0] - 'A';
	}
	for (int i = 0; i < n - 1; ++i) {
		int f, s;
		scanf("%d%d", &f, &s);
		AddArc(f - 1, s - 1);
	}
	DFS(0);
	int v1 = 0, v2 = 0, b1 = -1, b2 = -1;
	for (int i = 0; i < n; ++i) {
		if (d[i] > b1) {
			b1 = d[i];
			v1 = i;
		}
	}
	DFS(v1);
	for (int i = 0; i < n; ++i) {
		if (d[i] > b2) {
			b2 = d[i];
			v2 = i;
		}
	}
	int diam = b2, target = 0;
	if (diam & 1) {
		int vv1 = DFS2(v1, v2, diam / 2);
		int vv2 = DFS2(v1, v2, diam / 2 + 1);
		int vv3 = n;
		++n;
		for (int i = 0; i < kol; ++i) {
			if (arr[i].f == vv1 && arr[i].s == vv2) {
				arr[i].s = vv3;
				arr[i ^ 1].s = vv3;
				arr[kol].f = vv3;
				arr[kol + 1].f = vv3;

				arr[kol].s = vv1;
				arr[kol + 1].s = vv2;

				arr[kol].prev = -1;
				arr[kol + 1].prev = kol;
				beg[vv3] = kol + 1;
				kol += 2;
				break;
			}
		}
		target = vv3;
	}
	else {
		target = DFS2(v1, v2, diam / 2);
	}

	qc = 0;
	memset(c, 0, sizeof c);
	DFS3(target);
	if (Solve(target)) {
		puts("SYMMETRIC");
	}
	else {
		puts("NOT SYMMETRIC");
	}
}

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int tc = 0;
	int T;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++tc);
		Solve();
	}
	return 0;
}