// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;


template<class FlowT>
struct MaxFlow {
	static const int maxn = 10000; // change
	static const int maxm = 2000000; // change
	static const FlowT FlowEPS = FlowT(1e-7); // change
	static const FlowT FlowINF = FlowT(1<<29); // change

	int n, m;
	int to[2*maxm], prv[2*maxm], hed[maxn];
	FlowT cap[2*maxm];
	int dis[maxn], pos[maxn];

	void init(int _n) { n = _n, m = 0; memset (hed, -1, n * sizeof hed[0]); }

	inline void add_edge(int x, int y, FlowT c) {
		to[m] = y, cap[m] = c, prv[m] = hed[x], hed[x] = m++;
		to[m] = x, cap[m] = 0, prv[m] = hed[y], hed[y] = m++;
	}

	bool bfs(int source, int sink) {
		static int que[maxn], head, tail;
		memset(dis, -1, n * sizeof dis[0]); head = tail = 0;
		dis[source] = 0; que[tail++] = source;
		while(head < tail) {
			int u = que[head++];
			for(int e = hed[u]; e != -1; e = prv[e])
				if(cap[e] > FlowEPS && dis[to[e]] == -1)
					dis[to[e]] = dis[u]+1, que[tail++] = to[e];
			if(dis[sink] != -1) break;
		}
		return dis[sink] != -1;
	}

	FlowT dfs(int u, int sink, FlowT add = FlowINF) {
		if(u == sink) return add;
		FlowT res = 0;
		for(int &e = pos[u]; e != -1; e = prv[e])
			if(cap[e] > FlowEPS && dis[to[e]] == dis[u]+1) {
				FlowT cur = dfs(to[e], sink, min(add, cap[e]));
				cap[e] -= cur, cap[e^1] += cur, add -= cur, res += cur;
				if(add <= FlowEPS/2) break;
			}
		return res;
	}

	FlowT getflow(int source, int sink) {
		FlowT flow = 0;
		while(bfs(source, sink)) {
			memcpy(pos, hed, n * sizeof hed[0]);
			flow += dfs(source, sink);
		}
		return flow;
	}

	void cut(int u, bool clr = 1) { // u = source --> pos[setA] = 1, pos[setB] = 0;
		if(clr) memset(pos, 0, n * sizeof pos[0]);
		if(pos[u]) return; pos[u] = 1;
		for(int e = hed[u]; e != -1; e = prv[e])
			if(cap[e] > FlowEPS) cut(to[e], 0);
	}
};
MaxFlow<int> graph;

////////////////////////////////////////////////////////////////////////////////

int solve() {
	int n;
	cin >> n >> ws;

	map<string, int> id;
	graph.init(n + 2000 + (n-2) * 10);
	rep(i, n) {
		string line;
		getline(cin, line);
		istringstream iss(line);
		for(string word; iss >> word; ) {
			if(id.find(word) == id.end()) {
				int tmp = sz(id);
				id[word] = tmp;
			}
			int w = id[word];
			graph.add_edge(i, n + 2*w+0, 99999);
			graph.add_edge(n + 2*w+1, i, 99999);
		}
	}
	rep(i, sz(id)) graph.add_edge(n + 2*i+0, n + 2*i+1, 1);

	int ans = graph.getflow(0, 1);

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int ttt; cin >> ttt;
	fer(ttc, 1, ttt+1) {
		cout << "Case #" << ttc << ": " << solve() << endl;
	}

	return 0;
}

