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

int n, m;
vvi g;

bool bipartite_graph(int s) {
  vi color(n, 0);
  color[s] = 1;
  deque<int> stk;
  stk.push_back(s);
  while (!stk.empty()) {
    int u = stk.front();
    stk.pop_front();
    for (int v : g[u]) {
      if (color[v] > 0) {
        if (color[u] == color[v]) {
          return false;
        }
        continue;
      }
      color[v] = 3 - color[u];
      stk.push_back(v);
    }
  }
  return true;
}

set<int> roots;

int main() {
  scanf("%d %d", &n, &m);
  g.resize(n);
  UF uf(n);
  {
    int u, v;
    rep (i, m) {
      scanf("%d %d", &u, &v);
      u -= 1;
      v -= 1;
      g[u].push_back(v);
      g[v].push_back(u);
      uf.unite(u, v);
    }
  }
  rep (i, n) {
    roots.insert(uf.root(i));
  }
  ll bocchi = 0;
  ll bipartite = 0;
  ll other = 0;
  for (int u : roots) {
    if (uf.size(u) == 1) {
      bocchi += 1;
    } else if (bipartite_graph(u)) {
      bipartite += 1;
    } else {
      other += 1;
    }
  }

  ll ans = 0;
  ans += bocchi * (bocchi + 2 * (n - bocchi));
  ans += 2 * bipartite * bipartite;
  ans += other * (other + 2 * bipartite);
  printf("%lld\n", ans);

  return 0;
}