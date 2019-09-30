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
  int maxy = 200001;
  int n, m;
  scanf("%d %d", &n, &m);
  vvi ab(m, vi(2));
  vector<set<int> > y_p(maxy);
  rep (i, m) {
    int y;
    scanf("%d %d %d", &ab[i][0], &ab[i][1], &y);
    ab[i][0] -= 1; ab[i][1] -= 1;
    y_p[y].insert(i);
  }

  int q;
  scanf("%d", &q);
  vi v(q);
  vector<set<int> > y_r(maxy);
  rep (i, q) {
    int y;
    scanf("%d %d", &v[i], &y);
    v[i] -= 1;
    y_r[y].insert(i);
  }

  UF uf(n);
  vi ans(q);
  for (int y = 200000; y >= 0; --y) {
    for (int j : y_r[y]) {
      ans[j] = uf.size(v[j]);
    }
    for (int j : y_p[y]) {
      uf.unite(ab[j][0], ab[j][1]);
    }
  }
  rep (i, q) {
    printf("%d\n", ans[i]);
  }

  return 0;
}