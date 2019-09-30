#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <random>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int (X) = (A);(X) <= (Y);++(X))
#define _rep2(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define _size(X) (int)((X).size())
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 100;
int N;
int a[MAX_N+1];
const int MAX_V = MAX_N+2, INF = 1e9;
struct edge { ll to, cap, rev; };

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, ll cap) {
  G[from].push_back((edge){to, cap, (ll)G[to].size()});
  G[to].push_back((edge){from, 0, (ll)G[from].size() - 1});
}

int dfs(int v, int t, ll f) {
  if (v == t) return f;
  used[v] = true;
  for (int i = 0; i < G[v].size(); ++i) {
    edge &e = G[v][i];
    if (!used[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

ll max_flow(int s, int t) {
  ll flow = 0;
  for (;;) {
    memset(used, 0, sizeof(used));
    ll f = dfs(s, t, INFLL);
    if (f == 0) return flow;
    flow += f;
  }
}

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);
  
  cin >> N;
  rep(i, 1, N) cin >> a[i];

  ll ans = 0;
  int s = 0, t = N+1;
  rep(i, 1, N) {
      if (a[i] >= 0) {
          add_edge(s, i, a[i]);
          ans += a[i];
      } else {
          add_edge(i, t, -a[i]);
      }
  }

  for (int i = 1; i <= N; ++i) {
      for (int j = 2; j*i <= N; ++j) {
          add_edge(j*i, i, INFLL);
      }
  }

  
  ans -= max_flow(s, t);

  cout << ans << endl;

  return 0;
}