#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <unordered_map>
#include <array>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <random>
#include <numeric>

#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
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

const int MAX_N = 300;
int N;
int A[MAX_N+1][MAX_N+1];
                            
struct edge { int to, cost; };
const int MAX_V = MAX_N;
const ll INF = INFLL;

// V??????????
int V;
vector<edge> G[MAX_V];
ll d[MAX_V];

void add_edge(int u, int v, int c) {
  G[u].push_back((edge){v, c}); G[v].push_back((edge){u, c});
}

void dijkstra(int s) {
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

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }
  V = N;

  priority_queue<Pii, vector<Pii>, greater<Pii> > pque;
  for (int i = 0; i < N; ++i) {
    for (int j = i+1; j < N; ++j) {
      pque.push(Pii(A[i][j], i*N+j));
    }
  }

  ll ans = 0;
  while (!pque.empty()) {
    Pii pii = pque.top(); pque.pop();
    int cost = pii.fi, i = pii.sc/N, j = pii.sc%N;
    
    dijkstra(i);
    if (d[j] < cost) {
      cout << -1 << endl;
      return 0;
    } else if (d[j] > cost) {
      add_edge(i, j, cost);
      ans += cost;
    }
  }


  cout << ans << endl;

  return 0;
}