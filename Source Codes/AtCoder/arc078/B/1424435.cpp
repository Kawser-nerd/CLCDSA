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

int n;
vvi g;
vi par;

void set_par(int u, int prev) {
  for (int v : g[u]) {
    if (v == prev) { continue; }
    par[v] = u;
    set_par(v, u);
  }
}

int main() {
  scanf("%d", &n);
  g.resize(n);
  vvi edges(n-1, vi(2));
  rep (i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    a -= 1; b -= 1;
    g[a].push_back(b);
    g[b].push_back(a);
    edges[i][0] = min(a, b);
    edges[i][1] = max(a, b);
  }
  par.assign(n, -1);
  set_par(n-1, -1);

  vi path;
  for (int u = 0; ; u = par[u]) {
    path.push_back(u);
    if (u == n-1) {
      break;
    }
  }

  int m = path.size();
  int a, b;
  a = path[(m-1)/2];
  b = path[(m+1)/2];
  if (a > b) {
    swap(a, b);
  }
  UF uf(n);
  for (vi p : edges) {
    if (p[0] == a && p[1] == b) { continue; }
    uf.unite(p[0], p[1]);
  }

  if (uf.size(0) > uf.size(n-1)) {
    printf("Fennec\n");
  } else {
    printf("Snuke\n");
  }

  return 0;
}