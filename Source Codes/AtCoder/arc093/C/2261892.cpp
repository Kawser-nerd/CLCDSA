#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;

struct UF {
	int par[1000];
	UF() { for (int i = 0; i < 1000; i++) par[i] = i; }
	int root(int x) { if (x == par[x]) return x; return par[x] = root(par[x]); }
	void unit(int x, int y) { par[root(x)] = root(y); }
	int isSame(int x, int y) { return root(x) == root(y); }
};

struct Edge {
	int src, dst, cost;
	Edge(int src, int dst, int cost) { this->src = src; this->dst = dst; this->cost = cost; }
	Edge() {}
};
bool operator < (const Edge &e, const Edge &f) {
	return e.cost < f.cost;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int INF = 1e+15;
int n, m, x;
Edges edges;
Graph tree;
UF uf;
int score[1000][1000];

void bfs(int s) {
	int i;
	typedef pair<int, int> P;
	priority_queue<P, vector<P>, greater<P> > que;

	for (i = 0; i < n; i++) score[s][i] = INF;
	que.push(P(0, s)); score[s][s] = 0;
	while (!que.empty()) {
		P now = que.top(); que.pop();
		int cst = now.first;
		int pos = now.second;
		for (i = 0; i < tree[pos].size(); i++) {
			int npos = tree[pos][i].dst;
			int ncst = tree[pos][i].cost; if (ncst < cst) ncst = cst;
			if (score[s][npos] > ncst) {
				score[s][npos] = ncst;
				que.push(P(ncst, npos));
			}
		}
	}
}

int mod = 1000000007;

signed main() {
	int i;
	
	cin >> n >> m >> x;
	for (i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w; u--; v--;
		edges.push_back(Edge(u, v, w));
	}
	sort(edges.begin(), edges.end());
	
	int mst = 0;
	tree.resize(n);
	for (i = 0; i < edges.size(); i++) {
		int u = edges[i].src;
		int v = edges[i].dst;
		if (uf.isSame(u, v)) continue;
		uf.unit(u, v);
		tree[u].push_back(Edge(u, v, edges[i].cost));
		tree[v].push_back(Edge(v, u, edges[i].cost));
		mst += edges[i].cost;
	}
	if (mst > x) { cout << 0 << endl; return 0; }
	
	for (i = 0; i < n; i++) {
		bfs(i);
	}
	
	int cnt1 = 0, cnt2 = 0;
	for (i = 0; i < edges.size(); i++) {
		int u = edges[i].src;
		int v = edges[i].dst;
		int Y = edges[i].cost - score[u][v];
		if (Y < x - mst) { }
		else if (Y == x - mst) { cnt1++; }
		else { cnt2++; }
	}
	if (x == mst) cnt1--;
	
	//2 * cnt1???1????? * cnt2????????
	int ans1 = 1, ans2 = 1;
	for (i = 0; i < cnt1; i++) { ans1 *= 2; ans1 %= mod; } ans1 = (ans1 + mod - 1) % mod;
	for (i = 0; i < cnt2; i++) { ans2 *= 2; ans2 %= mod; }
	int ans = 2 * ans1 % mod * ans2 % mod;
	cout << ans << endl;
	return 0;
}