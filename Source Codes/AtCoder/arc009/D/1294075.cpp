#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
 
 
 
 
#ifdef NO_UNLOCK_IO
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
struct FastIO {
	static void scan(double &x) {
		scanf("%lf", &x);
	}
	template <class Integral>
	static void scan(Integral &x) {
		int k, m = 1;
		x = 0;
		for (;;) {
			k = getchar_unlocked();
			//if (k == '-') {
			//	m = -1;
			//	break;
			//}
			//else
			if ('0' <= k && k <= '9') {
				x = k - '0';
				break;
			}
		}
		for (;;) {
			k = getchar_unlocked();
			if (k < '0' || k > '9')
				break;
 
			x = x * 10 + k - '0';
		}
		//x *= m;//mul is faster than branch-misprediction penalty (maybe)
	}
	template <class Arithmetic, class... Rest>
	static void scan(Arithmetic &x, Rest&... y) {
		scan(x);
		scan(y...);
	}
	static void print(double x, char c) {
		printf("%.12f%c", x, c);
	}
	static void print(const char *x, char c) {
		printf("%s%c", x, c);
	}
	template <class Integral>
	static void print(Integral x, char c) {
		int s = 0, m = 0;
		char f[20];//Is this faster than "static char" ?
		if (x < 0) {
			m = 1;
			x = -x;
		}
		while (x) {
			f[s++] = x % 10;
			x /= 10;
		}
 
		if (!s)
			f[s++] = 0;
 
		if (m) putchar_unlocked('-');
		while (s--)
			putchar_unlocked(f[s] + '0');
 
		putchar_unlocked(c);
	}
	template <class Arithmetic>
	static void println(Arithmetic x) {
		print(x, '\n');
	}
};
 
 
 
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
typedef deque<bool> db;
template<class T> using vv = vector<vector< T > >;
 
// cout vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
	int len = v.size(); s << "\n";
	for (int i = 0; i < len; ++i) {
		s << v[i]; if (i < len - 1) s << "\t";
	}
	s << "\n"; return s;
}
 
// cout 2-dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
	int len = vv.size();
	for (int i = 0; i < len; ++i) { s << vv[i]; }
	return s;
}
 
 
class UF {
private:
	vector<int> par; // parent
	vector<int> sizes;
	void init(int n) {
		par.resize(n);
		for (int i = 0; i < n; ++i) {
			par[i] = i;
		}
		sizes.assign(n, 1);
	}
 
	void clear() {
		par.clear();
		sizes.clear();
	}
 
public:
	UF() {}
	UF(int n) {
		init(n);
	}
 
	void assign(int n) {
		clear();
		init(n);
	}
 
	int root(int x) {
		if (x == par[x]) {
			return x;
		}
		return par[x] = root(par[x]);
	}
 
	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return;
		}
		if (sizes[x] < sizes[y]) {
			swap(x, y);
		}
		par[y] = x;
		sizes[x] += sizes[y];
		sizes[y] = 0;
	}
 
	bool same(int x, int y) {
		return root(x) == root(y);
	}
 
	int size(int x) {
		return sizes[root(x)];
	}
};
 
int a, t, k;
vi n;
vector<set<int> > cities_including;
vector<set<int> > towns_included_by;
 
vector<vvi> edges_included_by;
int m;
 
int common_city(int town1, int town2) {
	if (cities_including[town1].size() > cities_including[town2].size()) {
		swap(town1, town2);
	}
	for (int city : cities_including[town1]) {
		if (cities_including[town2].find(city) != cities_including[town2].end()) {
			return city;
		}
	}
	assert(false);
	return -1;
}
 
int num_edges;
int num_towns;
vi costs;
map<int, int> town_id;
vvi g;
 
void dfs(int city, int edge_index, int used_edges, int cost_sum, UF uf) {
	if (edge_index < num_edges - 1) {
		dfs(city, edge_index + 1, used_edges, cost_sum, uf);
	}
	if (!(uf.same(g[edge_index][0], g[edge_index][1]))) {
		uf.unite(g[edge_index][0], g[edge_index][1]);
		cost_sum += g[edge_index][2];
		edge_index += 1;
		used_edges += 1;
		if (used_edges == num_towns - 1) {
			costs.push_back(cost_sum);
			return;
		}
		if (edge_index == num_edges) {
			return;
		}
		dfs(city, edge_index, used_edges, cost_sum, uf);
	}
}
 
void dfs_main(int city) {
	num_edges = (int)edges_included_by[city].size();
	num_towns = (int)towns_included_by[city].size();
	costs.clear();
	//  costs.reserve(HOGE);
	UF uf;
	uf.assign(num_towns);
	town_id.clear();
	for (int town : towns_included_by[city]) {
		town_id[town] = (int)town_id.size();
	}
	g.clear();
	for (vi edge : edges_included_by[city]) {
		int u = town_id[edge[0]];
		int v = town_id[edge[1]];
		g.push_back({ u, v, edge[2] });
	}
 
	dfs(city, 0, 0, 0, uf);
}
 
ll INF = 1e13;
 
int main() {
	FastIO::scan(a);
  FastIO::scan(t);
  FastIO::scan(k);
	n.resize(a);
	cities_including.resize(t);
	towns_included_by.resize(a);
	rep(i, a) { // city number
		FastIO::scan(n[i]);
		rep(j, n[i]) {
			int town;
			FastIO::scan(town);
			town -= 1;
			cities_including[town].insert(i);
			towns_included_by[i].insert(town);
		}
	}
 
	int sum_all_edges = 0;
	edges_included_by.resize(a);
	FastIO::scan(m);
	rep(i, m) {
		int town1, town2, cost;
		FastIO::scan(town1);
    FastIO::scan(town2);
    FastIO::scan(cost);
		town1 -= 1;
		town2 -= 1;
		int city = common_city(town1, town2);
		if (town1 > town2) { swap(town1, town2); }
		edges_included_by[city].push_back({ town1, town2, cost });
		sum_all_edges += cost;
	}
 
	vvi costs_of_city(a, vi(77 * 6 + 1, 0)); // Max(cost_i) * (7C2 - 6)
	ll judge = 1;
	rep(i, a) {
		int sum_costs = 0;
		for (auto e : edges_included_by[i]) {
			sum_costs += e[2];
		}
 
		dfs_main(i);
		//    assert((int)costs.size() > 0);
		judge *= (int)costs.size(); // costs is the list of spanning trees
		judge = min(judge, INF);
		rep(j, (int)costs.size()) {
			//      int cost = sum_costs - costs[j];
			//      costs_of_city[i][cost] += 1;
			costs_of_city[i][costs[j]] += 1;
		}
	}
	if (judge < k) {
		printf("-1\n");
		return 0;
	}
 
	vll dp(77 * 6 * 77 + 1, 0); // Max(cost_i) * (7 - 1) * A
	dp[0] = 1;
	rep(i, a) {
		vll ndp(77 * 6 * 77 + 1, 0);
		rep(j, 77 * 6 + 1) {
			if (costs_of_city[i][j] == 0) {
				continue;
			}
			rep(ii, 77 * 6 * 77 + 1) {
				if (dp[ii] == 0) {
					continue;
				}
				ndp[j + ii] += min(INF, dp[ii]) * costs_of_city[i][j];
			}
		}
		swap(dp, ndp);
	}
 
	vector<pair<int, ll> > ans;
	ans.reserve((int)dp.size());
 
	rep(i, 77 * 6 * 77 + 1) {
		if (dp[i] == 0) {
			continue;
		}
		ans.push_back(make_pair(sum_all_edges - i, dp[i]));
	}
	sort(all(ans));
 
	ll k_ = k;
	for (auto p : ans) {
		k_ -= p.second;
		if (k_ <= 0) {
			printf("%d\n", p.first);
			return 0;
		}
	}
 
	return 0;
}