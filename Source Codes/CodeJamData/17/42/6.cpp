#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#include <ext/pb_ds/priority_queue.hpp>

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF {
	int N;
	vector<vi> ed, red;
	vector<VL> cap, flow, cost;
	vi seen;
	VL dist, pi;
	vector<pii> par;

	MCMF(int N) :
		N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
		seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
		ed[from].push_back(to);
		red[to].push_back(from);
	}

	void path(int s, int t) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		auto relax = [&](int i, ll cap, ll cost, int dir) {
			ll val = di - pi[i] + cost;
			if (cap && val < dist[i]) {
				dist[i] = val;
				par[i] = {s, dir};
				if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
				else q.modify(its[i], {-dist[i], i});
			}
		};

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			trav(i, ed[s]) if (!seen[i])
				relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
			trav(i, red[s]) if (!seen[i])
				relax(i, flow[i][s], -cost[i][s], 0);
		}
		rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s, t), seen[t]) {
			ll fl = INF;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
			totflow += fl;
			for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
				if (r) flow[p][x] += fl;
				else flow[x][p] -= fl;
		}
		rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
		return {totflow, totcost};
	}

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
				trav(to, ed[i]) if (cap[i][to])
					if ((v = pi[i] + cost[i][to]) < pi[to])
						pi[to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

void solve() {
	int N, C, M;
	cin >> N >> C >> M;
	vi person[2];
	rep(i,0,M) {
		int pos, who;
		cin >> pos >> who;
		who--;
		person[who].push_back(pos);
	}
	sort(all(person[0]));
	sort(all(person[1]));

	MCMF mcmf(sz(person[0]) + sz(person[1]) + 2);
	int S = M;
	int T = M+1;
	int A = sz(person[0]);
	int B = sz(person[1]);
	rep(i,0,A) {
		rep(j,0,B) {
			int w = (person[0][i] == person[1][j] ? 1 : 0);
			if (w && person[0][i] == 1) continue;
			mcmf.addEdge(i, A+j, 1, w);
		}
	}
	rep(i,0,A) {
		mcmf.addEdge(S, i, 1, 0);
	}
	rep(i,0,B) {
		mcmf.addEdge(i+A, T, 1, 0);
	}
	auto pa = mcmf.maxflow(S, T);
	cout << A+B-pa.first << ' ' << pa.second << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit | cin.eofbit | cin.badbit);
	cin.tie(0);
	int T;
	cin >> T;
	rep(i,0,T) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
