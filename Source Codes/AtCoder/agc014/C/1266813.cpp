#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>

using namespace std;

#define MAXN 1000
int seen[MAXN][MAXN];
char g[MAXN][MAXN];

int dist(int a, int b, int x, int y) {
  return abs(a-x) + abs(b-y);
}

int main(void) {
  int n, m, k;
  scanf("%i %i %i", &n, &m, &k);
  
  int sx = 0, sy = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf(" %c", &g[i][j]);
      if (g[i][j] == 'S') {
        sx = i, sy = j;
      }
    }
  }
  
  vector<pair<int, int>> a, b;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1 || i == n || j == 1 || j == m) {
        b.push_back(make_pair(i,j));
      }
    }
  }
  
  queue<int> Q; 
  Q.push(sx), Q.push(sy);
  while (!Q.empty()) {
    int x = Q.front(); Q.pop();
    int y = Q.front(); Q.pop();
    
    a.push_back(make_pair(x, y));
                
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    for (int j = 0; j < 4; j++) {
      int nx = x + dx[j], ny = y + dy[j];
      if (nx >= 1 && nx <= n &&
          ny >= 1 && ny <= m &&
          !seen[nx][ny] && g[nx][ny] != '#' &&
          dist(nx, ny, sx, sy) <= k) {
        seen[nx][ny] = 1;
        Q.push(nx); Q.push(ny);
      }
    }
  }
  
  int ans = 10000000;
  for (auto s : a) {
    int rows[] = {1, n};
    for (int j = 0; j < 2; j++) {
      int d = dist(s.first, s.second, rows[j], s.second);
      ans = min(ans, (d + k - 1) / k + 1);  
    }
    
    int cols[] = {1, m};
    for (int j = 0; j < 2; j++) {
      int d = dist(s.first, s.second, s.first, cols[j]);
      ans = min(ans, (d + k - 1) / k + 1);  
    }
  }
  
  printf("%i\n", ans);
  
  return 0;
}