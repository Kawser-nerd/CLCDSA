#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 100000, MAX_M = 200000;
int N, M;
int p[MAX_M], q[MAX_M], c[MAX_M];
vector<int> station[MAX_N+1];
                            
struct edge { 
  int to, cost; 
  edge(int t, int c) : to(t), cost(c) {};
};
const int MAX_V = 2*MAX_M+MAX_N, INF = 10000000;
                            
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
  fill(d, d+V, INF);
  priority_queue<pii, vector<pii>, greater<pii> > pque;
  d[s] = 0;
  pque.push(pii(0, s));


  while (!pque.empty()) {
    pii p = pque.top(); pque.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < (int)G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost; 
        pque.push(pii(d[v]+ e.cost, e.to));
      }
    }
  }
}

int main() {
  cin >> N >> M;
  rep(i,M) cin >> p[i] >> q[i] >> c[i];

  for (int i = 0; i < M; ++i) {
    station[p[i]].pb(c[i]); station[q[i]].pb(c[i]);
  }

  map<pii, int> node;
  V = 0;
  for (int i = 1; i <= N; ++i) {
    sort(all(station[i]));
    station[i].erase(unique(all(station[i])), station[i].end());
    int out = node[pii(i, 0)] = V++;
    for (int k = 0; k < station[i].size(); ++k) {
      int sta = node[pii(i, station[i][k])] = V++;
      G[out].push_back(edge(sta, 1));
      G[sta].push_back(edge(out, 0));
    }
  }

  for (int i = 0; i < M; ++i) {
    int sta1 = node[pii(p[i], c[i])], sta2 = node[pii(q[i], c[i])];
    G[sta1].push_back(edge(sta2, 0));
    G[sta2].push_back(edge(sta1, 0));
  }

  int s = node[pii(1, 0)], g = node[pii(N, 0)];

  
  dijkstra(s);

  if (d[g] >= INF) cout << -1 << endl;
  else cout << d[g] << endl;


  return 0;
}