#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 300
int g[MAXN][MAXN];

const int oo = 100000;

int max_flow(int n, int source, int sink) {
  int tot = 0;
  
  while (true) {
    queue<int> Q;
    vector<int> parent(n+1, -1);
    vector<bool> seen(n+1, false);
    
    Q.push(source);
    seen[source] = true;
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (int v = 0; v <= n; v++) {
        if (g[u][v] && !seen[v]) {
          seen[v] = true;
          parent[v] = u;
          Q.push(v);
        }
      }
    }
    
    if (!seen[sink]) {
      break;
    }
    
    int cur = sink, cap = oo;
    while (parent[cur] != -1) {
      cap = min(cap, g[parent[cur]][cur]);
      cur = parent[cur];
    }
    
    cur = sink;
    while (parent[cur] != -1) {
      g[parent[cur]][cur] -= cap;
      g[cur][parent[cur]] += cap;
      cur = parent[cur];
    }
    
    tot += cap;
  }
  
  return tot;
}

int main(void) {
  int h, w;
  scanf("%i %i", &h, &w);
  
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      char c; scanf(" %c", &c);
      if (c == 'o') {
        g[i][j+h] = 1;
        g[j+h][i] = 1;
      } else if (c == 'S') {
        g[i][j+h] = oo;
        g[j+h][i] = oo;
        g[0][i] = oo;
      } else if (c == 'T') {
        g[i][j+h] = oo;
        g[j+h][i] = oo;
        g[i][h+w+1] = oo; 
      }
    }
  }
  
  int tot = max_flow(h+w+1, 0, h+w+1);
  printf("%i\n", tot < oo ? tot : -1);
  
  return 0;
}