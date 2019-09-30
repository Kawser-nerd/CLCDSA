#include <iostream>
#include <vector>
#include <map>
using namespace std;

class UnionFind {
public:
	UnionFind(int n) : par(n), rank(n) {
		for (int i = 0; i < n; i++)	par[i] = i;
	}
	int find(int x) {
		return par[x] == x ? x : par[x] = find(par[x]);
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (rank[x] < rank[y]) {
			par[x] = y;
		} else {
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}
private:
	vector<int> par, rank;
};

int main() {
	int N, K, L;
	cin >> N >> K >> L;
	
	UnionFind uf1(N), uf2(N);
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf1.unite(a, b);
	}
	for (int i = 0; i < L; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		uf2.unite(a, b);
	}
	
	map<int, int> gid1, gid2;
	vector<int> g1(N), g2(N);
	for (int i = 0; i < N; i++) {
		int p1 = uf1.find(i);
		int p2 = uf2.find(i);
		if (!gid1.count(p1)) {
			int id = gid1.size();
			gid1[p1] = id;
		}
		if (!gid2.count(p2)) {
			int id = gid2.size();
			gid2[p2] = id;
		}
		g1[i] = gid1[p1];
		g2[i] = gid2[p2];
	}

	map<pair<int, int>, int> nums;
	for (int i = 0; i < N; i++) {
		nums[make_pair(g1[i], g2[i])]++;
	}
	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << nums[make_pair(g1[i], g2[i])];
	}
	cout << endl;
	
	return 0;
}