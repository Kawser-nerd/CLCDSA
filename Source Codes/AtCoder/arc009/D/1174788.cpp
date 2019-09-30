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
template<class T> using vv=vector<vector< T > >;

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
    g.push_back({u, v, edge[2]});
  }

  dfs(city, 0, 0, 0, uf);
}

ll INF = 1e13;

int main() {
  scanf("%d%d%d", &a, &t, &k);
  n.resize(a);
  cities_including.resize(t);
  towns_included_by.resize(a);
  rep (i, a) { // city number
    scanf("%d", &n[i]);
    rep (j, n[i]) {
      int town;
      scanf("%d", &town);
      town -= 1;
      cities_including[town].insert(i);
      towns_included_by[i].insert(town);
    }
  }

  edges_included_by.resize(a);
  scanf("%d", &m);
  rep (i, m) {
    int town1, town2, cost;
    scanf("%d%d%d", &town1, &town2, &cost);
    town1 -= 1;
    town2 -= 1;
    int city = common_city(town1, town2);
    if (town1 > town2) { swap(town1, town2); }
    edges_included_by[city].push_back((vi){town1, town2, cost});
  }

  vvi costs_of_city(a, vi(77*15+1, 0)); // Max(cost_i) * (7C2 - 6)
  ll judge = 1;
  rep (i, a) {
    int sum_costs = 0;
    for (auto e : edges_included_by[i]) {
      sum_costs += e[2];
    }

    dfs_main(i);
//    assert((int)costs.size() > 0);
    judge *= (int)costs.size();
    judge = min(judge, INF);
    rep (j, (int)costs.size()) {
      int cost = sum_costs - costs[j];
      costs_of_city[i][cost] += 1;
    }
  }
  if (judge < k) {
    printf("-1\n");
    return 0;
  }

  unordered_map<int, ll> dp;
//  vll dp(77*15*77+1, 0); // Max(cost_i) * (7C2 - 6) * A
  dp[0] = 1;
  rep (i, a) {
    unordered_map<int, ll> ndp;
//    vll ndp(77*15*77+1, 0);
    rep (j, 77*15+1) {
      if (costs_of_city[i][j] == 0) {
        continue;
      }
      for (auto p : dp) {
        ndp[j + p.first] += min(INF, p.second) * costs_of_city[i][j];
      }
    }
    swap(dp, ndp);
  }

  vector<pair<int, ll> > ans;
  ans.reserve((int)dp.size());

  for (auto p : dp) {
    ans.push_back(p);
  }
  sort(all(ans));
  /*
  for (auto p : ans) {
    debug2(p.first, p.second);
  }
  */

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