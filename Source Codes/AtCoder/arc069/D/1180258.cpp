#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589


#define izryt bool

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}
pii Dir[8] = { //??
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};
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

void SCC(DGraph& g, vector<int>& scc) {
	vector<int>  orb(g.vn, -1);
	scc.resize(g.vn, -1);
	int cc = 0;
	int k = 0;
	vector<bool> used(g.vn);
	stack<int> st;
	function<int(int)> dfs = [&](int cur) {
		int low = orb[cur] = ++k;
		st.push(cur);
		used[cur] = 1;
		for (auto itr : g.g[cur]) {
			if (orb[itr.first] == -1)
				low = min(low, dfs(itr.first));
			else if (used[itr.first])
				low = min(low, orb[itr.first]);
		}
		if (low == orb[cur]) {
			while (1) {
				int cp = st.top(); st.pop();
				used[cp] = 0;
				scc[cp] = cc;
				if (cp == cur)
					break;
			}
			cc++;
		}
		return low;
	};
	REP(i, g.vn)
		if (orb[i] < 0)
			dfs(i);
}

bool TWO_SAT(int n, vector<pii> clause) {//???-, 1-indexed
	DGraph g(n * 2);
	for (auto itr : clause) {
		int a = (itr.first < 0 ? -itr.first+n : itr.first)-1, b = (itr.second < 0 ? -itr.second+ n : itr.second)-1;
		g.con(a + (a>=n?-n:n),b);
		g.con(b + (b >= n ? -n : n),a);
	}
	vector<int> scc;
	SCC(g, scc);

	REP(i, n) {
		if (scc[i] == scc[i + n]) {
			return 0;
		}
	}

	return 1;
}

signed main() {
	int n;
	scanf("%d", &n);
	vector<pii> flag(n, {-1,-1});
	vector<pii> ff(n*2);
	REP(i, n) {
		int a, b;
		scanf("%d %d", &a, &b);
		ff[i*2] = { a,i }; ff[i*2+1] = { b,i };
	}
	sort(ALL(ff));
	REP(i, 2 * n) {
		if(flag[ff[i].second].first!= -1)
			flag[ff[i].second].second = i;
		else
			flag[ff[i].second].first = i;
	}
	int l = 0, r = ff[n*2-1].first-ff[0].second+1; 

	int segs = 2,kk = 1;
	while (kk < n * 2) {
		kk *= 2; segs += kk;
	}
	while (1) {
		int mid = (l + r) / 2;

		vector<pii> clause;

		REP(i, n) {
			clause.push_back({ segs / 2 + flag[i].first,segs / 2 + flag[i].second });
			clause.push_back({ -(segs / 2 + flag[i].first),-(segs / 2 + flag[i].second) });
		}

		function<void(int, int, int, int, int)> cl = [&](int st, int a, int b, int num, int base) {
			if (b - a < 1) return;
			int left = (num-base) * (kk/base), right = (num - base + 1) * (kk / base);
			if (left == a && right == b) {
				clause.push_back({-st, -num});
			}
			else {	
				int nr = (left+right) / 2;
				if(nr > a) cl(st, a, min(b,nr), num*2, base*2);
				if(nr < b) cl(st, max(a,nr) , b, num * 2+1, base * 2);
			}
		};

		REP(i, n*2) {
			int ind = lower_bound(ALL(ff), MP(ff[i].first+mid, 0)) - ff.begin();
			cl(segs / 2 + i, i + 1, ind, 1, 1);
		}
		rep(i, 2, segs){
			clause.push_back({ -i, i / 2 });
		}

		if (TWO_SAT(segs, clause)) {
			l = mid;
		}
		else
			r = mid;

		if (r - l <= 1) {
			printf("%d\n", l);
			break;
		}
	}

	return 0;
}