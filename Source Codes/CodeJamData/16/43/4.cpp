#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

char maze[N][N];
int p[N];
int pairs[N], a[N];
int hor[N][N], ver[N][N];

int find_set(int x) {
  if (x != p[x]) {
    p[x] = find_set(p[x]);
  }
  return p[x];
}

void unite(int x, int y) {
  x = find_set(x);
  y = find_set(y);
  p[x] = y;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d:\n", qq);
    int r, c;
    scanf("%d %d", &r, &c);
    int n = 2 * (r + c);
    for (int i = 0; i < n; i++) {
      scanf("%d", pairs + i);
    }
    int cnt = 0;
    for (int i = 0; i <= r; i++) {
      for (int j = 0; j < c; j++) {
        hor[i][j] = cnt++;
      }
    }
    for (int j = 0; j <= c; j++) {
      for (int i = 0; i < r; i++) {
        ver[i][j] = cnt++;
      }
    }
    int id = 0;
    for (int j = 0; j < c; j++) {
      id++;
      a[id] = hor[0][j];
    }
    for (int i = 0; i < r; i++) {
      id++;
      a[id] = ver[i][c];
    }
    for (int j = c - 1; j >= 0; j--) {
      id++;
      a[id] = hor[r][j];
    }
    for (int i = r - 1; i >= 0; i--) {
      id++;
      a[id] = ver[i][0];
    }
    bool found = false;
    for (int t = 0; t < (1 << (r * c)); t++) {
      for (int i = 0; i < cnt; i++) {
        p[i] = i;
      }
      int tmp = t;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (tmp & 1) {
            unite(hor[i][j], ver[i][j]);
            unite(hor[i + 1][j], ver[i][j + 1]);
          } else {
            unite(hor[i][j], ver[i][j + 1]);
            unite(hor[i + 1][j], ver[i][j]);
          }
          maze[i][j] = (tmp & 1 ? '/' : '\\');
          tmp >>= 1;
        }
      }
      bool ok = true;
      for (int i = 0; i < n; i += 2) {
        int x = find_set(a[pairs[i]]);
        int y = find_set(a[pairs[i + 1]]);
        if (x != y) {
          ok = false;
          break;
        }
      }
      if (ok) {
        for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
            putchar(maze[i][j]);
          }
          putchar('\n');
        }
        found = true;
        break;
      }
    }
    if (!found) {
      puts("IMPOSSIBLE");
    }
  }
  return 0;
}
