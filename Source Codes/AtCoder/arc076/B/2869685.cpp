// D.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; } else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<II> vx, vy;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		vx.push_back(II(x, i));
		vy.push_back(II(y, i));
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	priority_queue<III, vector<III> > q;
	for (int i = 1; i < n; ++i) {
		q.push(III(vx[i - 1].first - vx[i].first, II(vx[i - 1].second, vx[i].second)));
		q.push(III(vy[i - 1].first - vy[i].first, II(vy[i - 1].second, vy[i].second)));
	}
	int ans = 0;
	UnionFind uf(n);
	while (q.size()) {
		III top = q.top();
		q.pop();
		if (uf.root(top.second.first) != uf.root(top.second.second)) {
			uf.unite(top.second.first, top.second.second);
			ans -= top.first;
		}
	}
	cout << ans << endl;
	return 0;
}