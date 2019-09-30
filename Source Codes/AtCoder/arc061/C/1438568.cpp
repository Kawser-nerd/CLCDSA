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
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
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

template<class T>
vector<ll> Dijkstra(T g, int st) {
	priority_queue<pii, vector<pii>, greater<pii>> que;

	que.push({ 0, st });
	int kk = 0;
	vector<ll> res(g.vn, -1);
	while (kk < g.vn && que.size()) {
		pii cur = que.top();
		que.pop();
		if (res[cur.second] != -1)
			continue;
		res[cur.second] = cur.first;
		kk++;
		for (auto itr : g.g[cur.second]) {
			if (res[itr.first] == -1)
				que.push({ cur.first + itr.second,itr.first });
		}
	}
	return res;
}

signed main() {
	int n, m;
	scanf("%d %d", &n, &m);

	BiDGraph g(n);
	vector<int> cp(m);
	REP(i, m) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--, b--,c--;
		g.con(a,b,i);
		cp[i] = c;
	}
	BiDGraph ng(m + n);
	vector<pii> bb(1000001, { -1,-1 });
	REP(i, n) {
		for (auto itr : g.g[i]) {
			if (bb[cp[itr.second]].second == i) {
				ng.con(n + itr.second, bb[cp[itr.second]].first, 0);
			}
			else
				bb[cp[itr.second]] = {n + itr.second, i};
			ng.con(n + itr.second, i, 1);
		}
	}
	auto ans = Dijkstra(ng, 0)[n-1];
	printf("%d\n", ans <= 0 ? -1 : ans/2);

	return 0;
} ./Main.cpp:144:17: warning: format specifies type 'int' but the argument has type 'long long' [-Wformat]
        printf("%d\n", ans <= 0 ? -1 : ans/2);
                ~~     ^~~~~~~~~~~~~~~~~~~~~
                %lld
1 warning generated.