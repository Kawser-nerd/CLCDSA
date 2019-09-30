#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};
typedef vector<vector<Edge> > graph;

struct PushRelabel {
	graph g;
	vector<Flow> exc;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), exc(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		Edge a = {t, sz(g[t]), 0, cap};
		Edge b = {s, sz(g[s]), 0, rcap};
		g[s].push_back(a);
		g[t].push_back(b);
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!exc[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; exc[e.dest] += f;
		back.f -= f; back.c += f; exc[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; exc[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -exc[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (exc[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(exc[u], cur[u]->c));
				else ++cur[u];
		}
	}
};

int solve() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<vi> ed(N);
	rep(i,0,M) {
		int u, v;
		cin >> u >> v;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	vi dist(N, -1);
	vector<vi> prevs(N);
	vector<vi> q(N+3);
	q[0] = {0};
	dist[0] = 0;
	rep(i,0,N+2) {
		vi q2 = q[i];
		trav(par, q2) trav(x, ed[par]) {
			if (dist[x] == -1) {
				dist[x] = i+1;
				q[i+1].push_back(x);
			}
			if (dist[x] == i+1)
				prevs[x].push_back(par);
		}
	}
	int fdist = dist[N-1];
	assert(fdist != -1);

	vi good(N);
	{
		vi q = {N-1};
		while (!q.empty()) {
			int x = q.back();
			q.pop_back();
			good[x] = 1;
			trav(y, prevs[x])
				q.push_back(y);
		}
	}

	vi ren(N), nvert;
	rep(i,0,N) {
		if (good[i])
			ren[i] = sz(nvert),
			nvert.push_back(i);
		else
			ren[i] = -1;
	}
	vector<vi> ed2(sz(nvert));
	rep(i,0,N) {
		if (good[i])
		trav(x, ed[i]) if(good[x]) ed2[ren[i]].push_back(ren[x]);
	}
	assert(nvert.back() == N-1);
	assert(nvert.front() == 0);
	N = sz(nvert);

	{
		int N2 = N + N - 2;
		PushRelabel pr(N2);
		rep(i,0,N) {
#define FROM(x) (x == 0 || x == N-1 ? x : x + N - 1)
#define TO(x) x
			trav(x, ed2[i]) {
				assert(x < N);
				pr.add_edge(FROM(i), TO(x), 10000);
			}
			if (i != 0 && i != N-1)
				pr.add_edge(TO(i), FROM(i), 1);
		}
		if (pr.maxflow(0, N-1) <= K-1)
			fdist++;
		// cout << "max flow = " << pr.maxflow(0, N-1) << endl;
	}

	// trav(i, nvert) cout << i << ' '; cout << endl;
	return fdist + 1;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i + 1 << ": ";
		cout << solve() << endl;
	}
}
