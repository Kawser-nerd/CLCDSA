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

int n, m; // number of nodes, edges

vvi edge;  // list of edges
vvi g;     // link-list of graph
vi prenum; // order of reached node
vi lowest; //
vi parent; // based on prenum(order)
int timer;

void lowlink_dfs(int u, int prev) {
  prenum[u] = timer;
  lowest[u] = timer;
  timer += 1;

  for (auto v : g[u]) {
    if (prenum[v] < 0) {
      parent[v] = u;
      lowlink_dfs(v, u);
      lowest[u] = min(lowest[u], lowest[v]);
    } else if (v != prev) {
      lowest[u] = min(lowest[u], prenum[v]);
    }
  }
}

void lowlink() {
  prenum.assign(n, -1);
  lowest.assign(n, 0);
  parent.assign(n, 0);
  timer = 0;
  lowlink_dfs(0, -1);
}

bool is_bridge(int x, int y) {
  return (prenum[x] < lowest[y] || prenum[y] < lowest[x]);
}

set<pii> bridge() {
  set<pii> ret;
  FOR(i, 1, n) {
    if (prenum[parent[i]] < lowest[i]) {
      int mi = min(parent[i], i);
      int ma = max(parent[i], i);
      ret.insert(make_pair(mi, ma));
    }
  }
  return ret;
}

struct UF {
  vector<int> par; // parent
  vector<int> sizes;
  UF(int n) : par(n), sizes(n, 1) {
    for (int i = 0; i < n; ++i) {
      par[i] = i;
    }
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

// query
int n_component;
vi roots;
vi group_id;
vi depth;
vvi par;
int MAX_LOG_V = 40;

void dfs(int u, int prev, int d) {
  depth[u] = d;
  par[0][u] = prev;
  for (int v : g[u]) {
    if (v == prev) {
      continue;
    }
    dfs(v, u, d+1);
  }
}

void lca_init() {
  dfs(0, -1, 0);
  rep (k, MAX_LOG_V - 1) {
    rep (i, n_component) {
      if (par[k][i] < 0) {
        continue;
      } else {
        par[k+1][i] = par[k][par[k][i]];
      }
    }
  }
}

int lca(int u, int v) {
  if (depth[u] > depth[v]) {
    swap(u, v);
  }
  rep (k, MAX_LOG_V) {
    if ((((depth[v] - depth[u]) >> k) & 1) == 1) {
      v = par[k][v];
    }
  }
  if (u == v) { return u; }
  for (int k = MAX_LOG_V - 1; k >= 0; --k) {
    if (par[k][u] != par[k][v]) {
      u = par[k][u];
      v = par[k][v];
    }
  }
  return par[0][u];
}

int main() {
  scanf("%d %d", &n, &m);
  edge.assign(m, vi(2, 0));
  g.resize(n);
  rep (i, m) {
    int x, y;
    scanf("%d %d", &x, &y);
    x -= 1; y -= 1;
    if (x > y) {
      swap(x, y);
    }
    edge[i][0] = x;
    edge[i][1] = y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  lowlink();
  auto bridges = bridge();
  UF uf(n);
  rep (i, m) {
    if (!is_bridge(edge[i][0], edge[i][1])) {
      uf.unite(edge[i][0], edge[i][1]);
    }
  }

  set<int> roots_set;
  rep (i, n) {
    roots_set.insert(uf.root(i));
  }
  n_component = (int)roots_set.size();
  roots.assign(n_component, 0);
  group_id.assign(n, -1);
  {
    auto itr = begin(roots_set);
    for (int i = 0; itr != end(roots_set); ++i, ++itr) {
      roots[i] = *itr;
      group_id[roots[i]] = i;
    }
  }
  rep (i, n) {
    group_id[i] = group_id[uf.root(i)];
  }

  g.clear();
  g.resize(n_component);
  for (auto b : bridges) {
    int u = group_id[b.first];
    int v = group_id[b.second];
    g[u].push_back(v);
    g[v].push_back(u);
  }
  depth.assign(n_component, 0);
  par.assign(MAX_LOG_V, vi(n_component, -1));
  lca_init();

  int q;
  scanf("%d", &q);
  int a, b, c;
  rep (query, q) {
    scanf("%d%d%d", &a, &b, &c);
    a = group_id[a-1];
    b = group_id[b-1];
    c = group_id[c-1];

    int r = lca(a, c);
    int ra = lca(a, b);
    int rc = lca(c, b);

    if ((ra == b && rc == r) || (ra == r && rc == b)) {
      printf("OK\n");
    } else {
      printf("NG\n");
    }
  }

  return 0;
}