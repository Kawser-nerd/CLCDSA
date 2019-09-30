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

const int MAX_N = 100000, MAX_M = 200000;
int N, M, S, T;
int UA[MAX_M], VA[MAX_M], DA[MAX_M];

struct edge { int to, cost; };
const int MAX_V = MAX_N;
const ll INF = INFLL;


// V??????????
int V;
vector<edge> G[MAX_V];
ll d1[MAX_V];
ll d2[MAX_V];
ll p1[MAX_V];
ll p2[MAX_V];

void add_edge(int v, int u, int cost) {
  G[v].push_back((edge){u, cost});
  G[u].push_back((edge){v, cost});
}

void dijkstra(int s, ll* d) {
  fill(d, d+V, INF);
  priority_queue<Pll, vector<Pll>, greater<Pll> > pque;
  d[s] = 0;
  pque.push(Pll(0, s));


  while (!pque.empty()) {
    Pll p = pque.top(); pque.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < (int)G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost; 
        pque.push(Pll(d[v]+ e.cost, e.to));
      }
    }
  }
}


void path_calc(int s, ll* d, ll* p) {
  vector<Pll> vp;
  for (int i = 0; i < N; ++i) {
    vp.push_back(Pll(d[i], i));
  }
  sort(all(vp));

  p[s] = 1;
  for (int i = 1; i < vp.size(); ++i) {
    int v = vp[i].sc;
    for (int j = 0; j < G[v].size(); ++j) {
      int u = G[v][j].to, cost = G[v][j].cost;
      if (d[v] != d[u] + cost) continue;
      p[v] += p[u];
      p[v] %= MOD;
    }
  }
}


int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N >> M >> S >> T;
  --S; --T;
  rep(i, M) {
    cin >> UA[i] >> VA[i] >> DA[i];
    --UA[i]; --VA[i];
  }
  V = N;

  rep(i, M) {
    add_edge(UA[i], VA[i], DA[i]);
  }

  dijkstra(S, d1);
  dijkstra(T, d2);
  ll mi_cost = d1[T];

  path_calc(S, d1, p1);
  path_calc(T, d2, p2);

  ll ans = 0;
  ans = mod(p1[T]*(p1[T]-1), MOD);
  vector<int> half_point;
  for (int i = 0; i < N; ++i) {
    if (d1[i]*2 == mi_cost && d2[i]*2 == mi_cost) half_point.push_back(i); 
  }
  for (int i = 0; i < half_point.size(); ++i) {
    int v = half_point[i];
    ll tmp = p1[v]*(p1[v]-1)%MOD*p2[v]%MOD*(p2[v]-1)%MOD;
    tmp = mod(tmp + p1[v]*p2[v]%MOD*(p2[v]-1), MOD);
    tmp = mod(tmp + p2[v]*p1[v]%MOD*(p1[v]-1), MOD);
    ans = mod(ans-tmp, MOD);
  }
  for (int v = 0; v < N; ++v) {
    for (int i = 0; i < G[v].size(); ++i) {
      int u = G[v][i].to, cost = G[v][i].cost;
      if (d1[v]+d2[u]+cost != mi_cost || d1[v]*2 >= mi_cost || d2[u]*2 >= mi_cost) continue;
      ll tmp = p1[v]*(p1[v]-1)%MOD*p2[u]%MOD*(p2[u]-1)%MOD; 
      tmp = mod(tmp + p1[v]*p2[u]%MOD*(p2[u]-1), MOD);
      tmp = mod(tmp + p2[u]*p1[v]%MOD*(p1[v]-1), MOD);
      ans = mod(ans-tmp, MOD);
    }
  }

  cout << ans << endl;
  return 0;
}