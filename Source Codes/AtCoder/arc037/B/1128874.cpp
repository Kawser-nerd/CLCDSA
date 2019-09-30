#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define debug(x) cerr<< #x <<": "<<x<<endl
#define debug2(x,y) cerr<< #x <<": "<< x <<", "<< #y <<": "<< y <<endl

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef vector<vector<ll> > vvll;
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

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vvi g(m, vi(2));
  UF uf(n);
  rep (i, m) {
    scanf("%d %d", &g[i][0], &g[i][1]);
    g[i][0] -= 1;
    g[i][1] -= 1;
    uf.unite(g[i][0], g[i][1]);
  }
  map<int, int> mp;
  rep (i, m) {
    mp[uf.root(g[i][0])] += 1; // number of edges
  }
  int ans = 0;
  int sum_size = 0;
  for (auto p : mp) {
    int sz = uf.size(p.first);
    if (sz - 1 == p.second) {
      ans += 1;
    }
    sum_size += sz;
  }
  printf("%d\n", ans + n - sum_size);

  return 0;
}