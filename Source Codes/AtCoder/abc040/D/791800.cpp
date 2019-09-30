#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> P;

const int MX = 200005;

struct UF {
	int n;
	vector<int> d;
	UF() {}
	UF(int n): n(n), d(n, -1) {}
	int root(int v) {
		if (d[v] < 0) return v;
		return d[v] = root(d[v]);
	}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (size(x) < size(y)) swap(x, y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	int size(int v) { return -d[root(v)]; }
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<P>> e(MX);
	for (int i = 0; i < m; ++i) {
		int a, b, y;
		scanf("%d%d%d", &a, &b, &y);
		--a, --b;
		e[y].push_back(P(a,b));
	}
	int q;
	scanf("%d", &q);
	vector<vector<P>> qs(MX);
	for (int qi = 0; qi < q; ++qi) {
		int v, w;
		scanf("%d%d", &v, &w);
		--v;
		qs[w].push_back(P(v, qi));
	}
	UF t(n);
	vector<int> ans(q);

	for (int i = MX - 1; i >= 0; --i) {
		for (P p: qs[i]) {
			int v = p.first, qi = p.second;
			ans[qi] = t.size(v);
		}
		for (P p: e[i]) {
			int a = p.first, b = p.second;
			t.unite(a, b);
		}
	}
	for (int i = 0; i < q; ++i) {
		printf("%d\n", ans[i]);
	}

	return 0;
}