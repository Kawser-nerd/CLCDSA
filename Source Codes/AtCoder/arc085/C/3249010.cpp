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

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
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

const int MAX_N = 100;
int N;
int a[MAX_N+1];

const int MAX_V = MAX_N+2, INF = 1e9;

struct edge { int to, cap, rev; };

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int from, int to, int cap) {
  G[from].push_back((edge){to, cap, (int)G[to].size()});
  G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}

ll dfs(int v, int t, int f) {
  if (v == t) return f;
  used[v] = true;
  for (int i = 0; i < G[v].size(); ++i) {
    edge &e = G[v][i];
    if (!used[e.to] && e.cap > 0) {
      ll d = dfs(e.to, t, min(f, e.cap));
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
    ll f = dfs(s, t, INF);
    if (f == 0) return flow;
    flow += f;
  }
}

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> a[i];

  ll ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (a[i] < 0) add_edge(0, i, -a[i]);
    else {
      add_edge(i, N+1, a[i]);
      ans += a[i];
    }
  }

  for (int i = 1; i <= N; ++i) {
    for (int k = 2; i*k <= N; ++k) {
      add_edge(i, i*k, INF);
    }
  }

  cout << ans - max_flow(0, N+1) << endl;

  return 0;
}