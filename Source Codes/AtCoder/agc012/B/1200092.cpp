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

vvi g;
int n, m;
vvi dp;

void dp_run(int va, int da, int ca) {
  if (dp[va][da] > 0) return;
  dp[va][da] = ca;
  if (da == 0) return;
  dp_run(va, da-1, ca);
  for (int u : g[va]) {
    dp_run(u, da-1, ca);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  g.resize(n);
  rep (i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    a -= 1; b -= 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dp.assign(n, vi(11, 0));
  int q;
  scanf("%d", &q);
  vi v(q), d(q), c(q);
  rep (i, q) {
    scanf("%d%d%d", &v[i], &d[i], &c[i]);
    v[i] -= 1;
  }

  reverse(all(v));
  reverse(all(d));
  reverse(all(c));

  rep (i, q) {
    dp_run(v[i], d[i], c[i]);
  }
  rep (i, n) {
    printf("%d\n", dp[i][0]);
  }

  return 0;
}