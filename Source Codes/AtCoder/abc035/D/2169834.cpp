#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cassert>
#include <tuple>

using namespace std;
typedef long long ll;
const ll INF = 1e15;


using Weight = ll;
class Edge {
public:
	int s, d;
	Weight w;
	Edge() : s(0), d(0), w(0) {}
	Edge(int s, int d, Weight w) : s(s), d(d), w(w) {}
	bool operator < (const Edge &e) const {
		return w != e.w ? w < e.w :
			   s != e.s ? s < e.s :
			   d < e.d;
	}
};
using Graph = vector<vector<Edge>>;

// ??s??????????????????????? O(ElogV)
pair<vector<Weight>, Graph> dijkstra(int s, Graph& g) {
	vector<Weight> dist(g.size(), INF);
	vector<pair<int, Weight>> prev(g.size(), make_pair(-1, 0));
	priority_queue<Edge> que;
	que.push(Edge(-1, s, 0));
	while (!que.empty()) {
		Edge now = que.top();
		now.w *= -1;
		que.pop();
		if (dist[now.d] <= now.w)
			continue;
		dist[now.d] = now.w;
		prev[now.d] = make_pair(now.s, now.w);
		for (auto&& e : g[now.d]) {
			if (e.w < dist[e.d])
				que.push(Edge(e.s, e.d, -(e.w + now.w)));
		}
	}
	Graph f(g.size());
	for (int i = 0;i < prev.size();i++)
		if (prev[i].first != -1)
			f[prev[i].first].push_back(Edge(prev[i].first, i, prev[i].second));
	return make_pair(dist, f);
}


int main() {
	ll N, M, T;
	cin >> N >> M >> T;
	vector<ll> a(N);
	for (int i = 0;i < N;i++)
		cin >> a[i];
	Graph g(N);
	Graph h(N);
	for (int i = 0;i < M;i++) {
		ll s, d, w;
		cin >> s >> d >> w;
		s--; d--;
		g[s].push_back(Edge(s, d, w));
		h[d].push_back(Edge(d, s, w));
	}
	vector<ll> dist1, dist2; Graph f;
	tie(dist1, f) = dijkstra(0, g);
	tie(dist2, f) = dijkstra(0, h);
	ll ans = 0;
	for (int i = 0;i < N;i++)
		if(dist1[i] != INF && dist2[i] != INF)
			ans = max(ans, (T - dist1[i] - dist2[i]) * a[i]);
	cout << ans << endl;
	return 0;
}