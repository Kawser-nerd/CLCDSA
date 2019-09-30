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
  vvi yab(m, vi(3));
  vi a(m), b(m), y(m);
  rep (i, m) {
    scanf("%d %d %d", &yab[i][1], &yab[i][2], &yab[i][0]);
    yab[i][1] -= 1; yab[i][2] -= 1;
  }
  sort(all(yab));
  map<int, set<int> > y_p;
  rep (i, m) {
    y_p[yab[i][0]].insert(i);
  }

  int q;
  scanf("%d", &q);
  vvi wv(q, vi(3));
  rep (i, q) {
    scanf("%d %d", &wv[i][1], &wv[i][0]);
    wv[i][1] -= 1;
    wv[i][2] = i;
  }
  sort(all(wv));
  map<int, set<int> > y_r;
  rep (i, q) {
    y_r[wv[i][0]].insert(i);
  }

  UF uf(n);
  vi ans(q);
  for (int year = 200000; year >= 0; --year) {
    for (int j : y_r[year]) {
      ans[wv[j][2]] = uf.size(wv[j][1]);
    }
    for (int j : y_p[year]) {
      uf.unite(yab[j][1], yab[j][2]);
    }
  }
  rep (i, q) {
    printf("%d\n", ans[i]);
  }

  return 0;
}