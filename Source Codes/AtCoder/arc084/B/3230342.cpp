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
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
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

int K;
                            
struct edge { int to, cost; };
const int MAX_V = 100000, INF = 10000000;

// V??????????
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void add_edge(int v, int u, int cost) {
  G[v].push_back((edge){u, cost});
  G[u].push_back((edge){v, cost});
}

void dijkstra(int s) {
  fill(d, d+V, INF);
  priority_queue<Pii, vector<Pii>, greater<Pii> > pque;
  d[s] = 0;
  pque.push(Pii(0, s));


  while (!pque.empty()) {
    Pii p = pque.top(); pque.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < (int)G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost; 
        pque.push(Pii(d[v]+ e.cost, e.to));
      }
    }
  }
}

int main() {
  cin >> K;
  V = K;

  for (int i = 1; i < K; ++i) {
    int u = mod(i*10, K), v = mod(i+1, K);
    G[i].push_back((edge){u, 0});
    G[i].push_back((edge){v, 1});
  }

  dijkstra(1);

  cout << d[0]+1 << endl;

  return 0;
}