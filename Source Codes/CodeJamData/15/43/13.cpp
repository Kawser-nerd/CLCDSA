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

map<string, int> lut;
int Lut;
vi spli(const string& inp) {
	istringstream iss(inp);
	vi ret;
	string w;
	while (iss >> w) {
		if (!lut.count(w))
			lut[w] = Lut++;
		ret.push_back(lut[w]);
	}
	return ret;
}

int solve() {
	Lut = 0;
	lut.clear();
	int N;
	cin >> N;
	cin.ignore(100, '\n');
	vector<vi> wl(N);
	string line;
	rep(i,0,N) {
		getline(cin, line);
		wl[i] = spli(line);
	}
#define INP(i) (2*(i))
#define OUTP(i) (2*(i) + 1)
	const int S = 2*Lut;
	const int T = 2*Lut + 1;
	const ll inf = 1 << 30;
	PushRelabel pr(2*Lut + 2);
	trav(x, wl[0])
		pr.add_edge(S, INP(x), inf);
	trav(x, wl[1])
		pr.add_edge(OUTP(x), T, inf);
	rep(i,2,N) {
		trav(x, wl[i]) trav(y, wl[i]) {
			pr.add_edge(OUTP(x), INP(y), inf);
		}
	}
	rep(i,0,Lut)
		pr.add_edge(INP(i), OUTP(i), 1);
	return (int)pr.maxflow(S, T);
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d: %d\n", i+1, solve());
	}
}
