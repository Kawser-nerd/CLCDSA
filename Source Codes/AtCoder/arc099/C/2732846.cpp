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
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const double eps = 1e-6;
const ll MOD = 1000000007;
const ll INF = 1e15;

typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

ll N, M;
vector<int> visited;
Graph g;

P dfs(ll now, int color) {
	P ret = P(0, 0);
	visited[now] = color;
	if (color == 0)
		ret.first++;
	else
		ret.second++;
	for (int i = 0;i < g[now].size();i++) {
		if (visited[g[now][i].dst] == -1) {
			P temp = dfs(g[now][i].dst, 1 - color);
			ret.first += temp.first;
			ret.second += temp.second;
		}
		else if (visited[g[now][i].dst] == color)
			ret.first = -INF;
	}
	return ret;
}

int main() {
	cin >> N >> M;
	g = Graph(N);
	vector<vector<ll>> dist(N, vector<ll>(N, 0));
	for (int i = 0;i < M;i++) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			if (i!=j && dist[i][j] == 0)
				g[i].push_back(Edge(i, j, 1));
	vector<P> v;
	visited.assign(N, -1);
	bool ok = true;
	for (int i = 0;i < N;i++) {
		if (visited[i] == -1) {
			v.push_back(dfs(i, 0));
			ok &= v.back().first >= 0;
		}
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	vector<vector<int>> dp(v.size()+1, vector<int>(N+1));
	dp[0][0] = 1;
	for (int i = 0;i < v.size();i++) {
		P x = v[i];
		for (int from = N;from >= 0;from--) {
			if (from + x.first <= N)
				dp[i+1][from + x.first] = max(dp[i+1][from + x.first], dp[i][from]);
			if (from + x.second <= N)
				dp[i+1][from + x.second] = max(dp[i+1][from + x.second], dp[i][from]);
		}
	}
	ll ans = INF;
	for (ll i = 0;i <= N;i++) {
		if (dp.back()[i] == 1)
			ans = min(ans, i * (i - 1) / 2 + (N - i) * (N - i - 1) / 2);
	}
	cout << ans << endl;
	return 0;
}