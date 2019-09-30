#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1e9
#define PI acos(-1)
typedef long long ll;
typedef pair<int, int> p_ii;

struct UF {
	vector<int> v;
	UF(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	vector<p_ii>all;
	int n, k, l;
	cin >> n >> k >> l;
	int i, j;
	struct UF s(n), t(n);
	for (i = 0; i < k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		s.unite(a, b);
	}
	for (i = 0; i < l; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		t.unite(a, b);
	}
	for (i = 0; i < n; i++)all.push_back({ s.find(i),t.find(i) });
	sort(all.begin(), all.end());

	for (i = 0; i < n; i++) {
		p_ii tmp = { s.find(i), t.find(i) };
		int ans = upper_bound(all.begin(), all.end(), tmp) - lower_bound(all.begin(), all.end(), tmp);
		if (i != 0)printf(" ");
		printf("%d", ans);
	}
	printf("\n");

	return 0;
}