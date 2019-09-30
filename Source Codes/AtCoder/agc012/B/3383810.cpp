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
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define repa(X,A,Y) for (int (X) = A;(X) <= (Y);++(X))
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

const int MAX_N = 100000, MAX_M = 100000, MAX_Q = 100000;
int N, M, Q;
int a[MAX_M], b[MAX_M];
int v[MAX_Q], d[MAX_Q], c[MAX_Q];
                            
struct edge { int to, cost; };
const int MAX_V = 100000, INF = INFINT;

// V??????????
int V;
vector<edge> G[MAX_V];
int dist[MAX_V];
int dp[MAX_V][11];

void add_edge(int v, int u, int cost) {
  G[v].push_back((edge){u, cost});
  G[u].push_back((edge){v, cost});
}

void dfs(int v, int di, int c) {
  if (dp[v][di] != 0) return;
  if (di == 0) {
    dp[v][di] = c; return;
  }
  dp[v][di] = c;

  dfs(v, di-1, c);
  for (int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i].to;
    dfs(u, di-1, c);
  }
}


int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> M;
  rep(i, M) cin >> a[i] >> b[i];
  rep(i, M) {--a[i]; --b[i];}
  cin >> Q;
  rep(i, Q) cin >> v[i] >> d[i] >> c[i];
  rep(i, Q) {--v[i];}
  V = N;

  rep(i, M) {
    add_edge(a[i], b[i], 1);
  }

  rrep(i, Q) {
    dfs(v[i], d[i], c[i]);
  }

  rep(i, N) {
    cout << dp[i][0] << endl;
  }

  return 0;
}