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
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 200000, MAX_M = 200000;
int N, M;
int a[MAX_M], b[MAX_N];
                            
struct edge { 
  edge(int t, int c) {
    to = t; cost = c;
  }
  int to, cost; 
};
const int MAX_V = MAX_N, INF = 10000000;

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
  rep(i,M) cin >> a[i] >> b[i];
  V = N;

  for (int i = 0; i < M; ++i) {
    G[a[i]-1].push_back(edge(b[i]-1, 1));
    G[b[i]-1].push_back(edge(a[i]-1, 1));
  }

  dijkstra(0);

  if (d[N-1] == 2) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;

  return 0;
}