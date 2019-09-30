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
vi pre_cost;
vector<bool> pre_calculated;

void calculate_pre_cost (int s) {
  if (pre_calculated[s]) { return; }
  rep (i, n) {
    if ((s >> i) % 2 == 1) {
      continue;
    }
    int add_cost = 0;
    rep (j, n) {
      if ((s >> j) % 2 == 1) {
        add_cost += g[i][j];
      }
    }
    if (s != 0 && add_cost == 0) {
      continue;
    }
    int next_s = s + (1 << i);
    pre_cost[next_s] = pre_cost[s] + add_cost;
    calculate_pre_cost(next_s);
  }
  pre_calculated[s] = true;
  return;
}

int main() {
  scanf("%d %d", &n, &m);
  g.assign(n, vi(n, 0));
  int cost_all = 0;
  rep (i, m) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a -= 1; b -= 1;
    g[a][b] = c;
    g[b][a] = c;
    cost_all += c;
  }

  pre_cost.assign((1 << n), -1);
  pre_cost[0] = 0;
  pre_calculated.assign((1 << n), false);
  calculate_pre_cost(0);

  vvi dp;
  dp.assign((1 << n), vi(n, -1));
  dp[1][0] = 0;

  rep (s, (1 << n)) {
    rep (u, n) {
      if (dp[s][u] == -1) {
        continue;
      }
      int _s = (1 << n) - 1 - s;
      rep (v, n) {
        if ((_s >> v) % 2 == 1 && g[u][v] > 0) {
          dp[s + (1 << v)][v] = max(dp[s + (1 << v)][v], dp[s][u] + g[u][v]);
        }
      }
      for (int t = _s; t > 0; t = (t - 1) & _s) {
        dp[s + t][u] = max(dp[s + t][u], dp[s][u] + pre_cost[t + (1 << u)]);
      }
    }
  }

  printf("%d\n", cost_all - dp[(1 << n) - 1][n-1]);

  return 0;
}