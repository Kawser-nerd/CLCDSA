#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const ll INF = 1e15;
const double eps = 1e-6;
const ll MOD = 1000000007;

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
			f[i].push_back(Edge(i, prev[i].first, prev[i].second));
	return make_pair(dist, f);
}


int main() {
	ll N;
	cin >> N;
	Graph g(N);
	for (int i = 0;i < N-1;i++) {
		ll v, w;
		cin >> v >> w;
		v--;
		w--;
		g[v].push_back(Edge(v, w, 1));
		g[w].push_back(Edge(w, v, 1));
	}
	vector<Weight> dist;
	Graph h;
	tie(dist, h) = dijkstra(0, g);
	pair<ll, int> node = P(-1, -1);
	for (int i = 0;i < N;i++)
		node = max(make_pair(dist[i], i), node);
	tie(dist, h) = dijkstra(node.second, g);
	pair<ll, int> node2 = P(-1, -1);
	for (int i = 0;i < N;i++)
		node2 = max(make_pair(dist[i], i), node2);

	vector<int> line(N, false);
	ll now = node2.second;
	line[node.second] = true;
	while (now != node.second) {
		line[now] = true;
		now = h[now][0].d;
	}
	bool ok = true;
	vector<ll> cnt(N);
	for (int i = 0;i < N;i++) {
		bool nowok = false;
		for (int j = 0;j < g[i].size();j++) {
			if (line[g[i][j].d] || line[i])
				nowok = true;
			if (!line[i] && line[g[i][j].d])
				cnt[g[i][j].d]++;
		}
		ok &= nowok;
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	vector<ll> ans(N);
	ll l = 0;
	ll r = N - 1;
	ll rest = N;
	ll nownode = node2.second;
	ll maxright = r;
	vector<ll> retu;
	retu.push_back(nownode);
	while (rest > 0) {
		ans[r] = rest - cnt[nownode];
		for (int i = 0;i < cnt[nownode];i++) {
			r--;
			ans[r] = rest - i;
		}
		r--;
		rest -= 1 + cnt[nownode];
		if (h[nownode].empty())
			break;
		nownode = h[nownode][0].d;
		retu.push_back(nownode);
	}
	
	vector<ll> ans2(N);
	l = 0;
	r = N - 1;
	rest = N;
	nownode = retu.back();
	retu.pop_back();
	maxright = r;
	while (rest > 0) {
		ans2[r] = rest - cnt[nownode];
		for (int i = 0;i < cnt[nownode];i++) {
			r--;
			ans2[r] = rest - i;
		}
		r--;
		rest -= 1 + cnt[nownode];
		if (retu.empty())
			break;
		nownode = retu.back();
		retu.pop_back();
	}

	ans = min(ans, ans2);

	for (int i = 0;i < N;i++) {
		cout << ans[i];
		if (i == N - 1)
			cout << endl;
		else cout << " ";
	}
	return 0;
}