//Author: 23forever
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <bitset>
const int MAXN = 1000;
const int INF = 0x3f3f3f3f;
using namespace std;

inline int read() {
  int x = 0, w = 1;
  char c = ' ';

  while (c < '0' || c > '9') {
    c = getchar();
    if (c == '-') w = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }

  return x * w;
}

int n, m, ga[MAXN + 5][MAXN + 5], belong[MAXN + 5], vis[MAXN + 5], sum[2];
bool f;

void dfs(int u, int col) {
  if (f) return;

  belong[u] = col;
  vis[u] = true;
  ++sum[col];

  for (int i = 1; i <= n; ++i) {
    if (i != u && !ga[u][i]) {
      int v = i;

      if (!vis[v]) {
        dfs(v, col ^ 1);
      } else if (col == belong[v]) {
        f = true;
        return;
      }
    }
  }
}

void init() {
  n = read();
  m = read();

  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    ga[u][v] = true;
    ga[v][u] = true;
  }
}

bitset<705>S;

int main() {
  init();
  
  S[0] = 1;

  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      memset(sum, 0, sizeof(sum));
      dfs(i, 0);

      S = (S << sum[0]) | (S << sum[1]);
    }
  }

  if (f) {
    puts("-1");
    return 0;
  }
  
  int ans = INF;

  for (int i = 0; i < n; ++i) if (S[i]) ans = min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
  
  printf("%d\n", ans);

  return 0;
}