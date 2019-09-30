#include <iostream>
#include <cstdio>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <stdlib.h>
#include <functional>
#include <string>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#include <nmmintrin.h>
#include <chrono>
const double EPS = 1e-8;
#define Scan(a) int a;scanf("%d", &a);
#define ScanS(a) char a[500];scanf("%s", a);
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1LL)
#define bitset(a,b)      ( a |= (1LL << b))
#define bitunset(a,b)    (a &= ~(1LL << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#ifdef _MSC_VER
#define __builtin_popcount _mm_popcnt_u32
#define __builtin_popcountll _mm_popcnt_u64
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}

pii Dir[8] = {
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};


pii operator+(pii obj, pii obj2) {
	return MP(obj.first + obj2.first, obj.second + obj2.second);
}
pii operator-(pii obj, pii obj2) {
	return MP(obj.first - obj2.first, obj.second - obj2.second);
}
class Graph {
public:
	int vn;
	int sumcost = 0;
	vector<vector<pii>> g;

	Graph(int n) {
		vn = n;
		g.resize(n);
	}
	virtual void con(int a, int b, int w) = 0;
	int getWeight(int f, int t) {
		auto itr = lower_bound(ALL(g[f]), make_pair(t, INT_MIN));
		if (itr != g[f].end())
			return itr->second;
		return INT_MIN;
	}
	int Costsum() {
		return sumcost;
	}
	void scan(int edcount, bool oindexed, bool w) {
		REP(i, edcount) {
			int a, b, c = 1;
			scanf("%d %d", &a, &b);
			if (w)scanf("%d", &c);
			con(a - oindexed, b - oindexed, c);
		}
	}
};
class BiDGraph : public Graph {//??
public:
	BiDGraph(int n) : Graph(n) {}

	void con(int a, int b, int w = 1) {
		g[a].push_back({ b,w });
		g[b].push_back({ a, w });
		sumcost++;
	}
};
class DGraph : public Graph {//??
public:
	DGraph(int n) : Graph(n) {}
	void con(int a, int b, int w = 1) {
		g[a].push_back({ b,w });
		sumcost++;
	}
};

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) { //????????? y??????????
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { //x?y??????????????????
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	bool isroot(int x) {
		return data[x] < 0;
	}
	int size(int x) {
		return -data[root(x)];
	}
};

#define int ll
// dinic
struct max_flow {
	struct edge { int to, cap, rev; };
	int V;
	vector<vector<edge>> G;
	vector<int> itr, level;

	max_flow(int V) : V(V) { G.assign(V, vector<edge>()); }

	void add_edge(int from, int to, int cap) {
		G[from].push_back({ to, cap, (int)G[to].size() });
		G[to].push_back({ from, 0, (int)G[from].size() - 1 });
	}

	void bfs(int s) {
		level.assign(V, -1);
		queue<int> q;
		level[s] = 0; q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto &e : G[v]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}

	int dfs(int v, int t, int f) {
		if (v == t) return f;
		for (int& i = itr[v]; i < (int)G[v].size(); ++i) {
			edge& e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int run(int s, int t) {
		int ret = 0, f;
		while (bfs(s), level[t] >= 0) {
			itr.assign(V, 0);
			while ((f = dfs(s, t, LLONG_MAX)) > 0) ret += f;
		}
		return ret;
	}
};
signed main() {
	int n;
	cin >> n;
	ll sum = 0;
	vector<int> num(n);
	max_flow flow(n + 2);
	REP(i, n) {
		scanf("%lld", &num[i]);
		if(num[i] < 0)
			flow.add_edge(i + 1, n + 1, 0), flow.add_edge(0, i + 1, -num[i]);
		else 
			flow.add_edge(i + 1, n + 1, num[i]), flow.add_edge(0, i + 1, 0), sum = sum + num[i];
	}

	rep(i,1, n + 1) {
		for (int j = i * 2; n >= j; j += i) {
			flow.add_edge(i, j, LLONG_MAX/2000);
		}
	}

	cout << sum - flow.run(0, n + 1) << endl;


	return 0;
}