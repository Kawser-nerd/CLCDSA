#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

#define all(c) ((c).begin()), ((c).end()) 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;

int readint() { 
  int i, j, s;
  while (!isdigit(i = getchar()) && i != '-');
  if (i == '-') { s = -1; j = 0; }
  else { s = 1; j = i - '0'; }
  while (isdigit(i = getchar())) j = ((j << 1) + (j << 3) + (i - '0'));
  return j * s;
}



const int MAX_V = 1010;
 
int V;
 
vector<int> adj[MAX_V], lef;
int mat[MAX_V];
bool vis[MAX_V];
 
void init(int v) {
  V = v;
  for (int i = 0; i < V; i++) adj[i].clear();
  lef.clear();
}
 
void add_edge(int a, int b) { 
  adj[a].push_back(b); 
  adj[b].push_back(a); 
}
 
void add_left(int v) {
  lef.push_back(v); 
}
 
int augment(int a) {
  for (int t, i = 0; i < (int)adj[a].size(); i++)
    if (!vis[t = adj[a][i]]) { 
      vis[t] = true;
      if (mat[t] < 0 || augment(mat[t])) {
    mat[a] = t;
    mat[t] = a;
    return 1;
      }
    }
  return 0;
}
 
int bipartite_matching() {
  int res = 0;
  memset(mat, -1, sizeof(mat));
  for (int i = 0; i < (int)lef.size(); i++) {
    memset(vis, 0, sizeof(vis));
    res += augment(lef[i]);
  }
  return res;
}



int N, K, P[110][30];

int main() {
  int cases = readint();
  rep (ca, cases) {
    N = readint();
    K = readint();
    rep (i, N) rep (k, K) P[i][k] = readint();

    init(N * 2);
    rep (i, N) add_left(i);
    rep (i, N) {
      rep (j, N) {
        if (i == j) continue;
        rep (k, K) if (P[j][k] >= P[i][k]) goto ng;
        add_edge(i, N + j);
      ng:;
      }
    }
    int ans = N - bipartite_matching();
    printf("Case #%d: %d\n", ca + 1, ans);
  }
  return 0;
}
