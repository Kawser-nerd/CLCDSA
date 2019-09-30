#include <bits/stdc++.h>

using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

char s[777][777];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int h, w;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
      scanf("%s", s[i]);
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (s[i][j] == '.') {
          continue;
        }
        int dir = -1;
        if (s[i][j] == '<') dir = 1;
        if (s[i][j] == '^') dir = 0;
        if (s[i][j] == '>') dir = 3;
        if (s[i][j] == 'v') dir = 2;
        int x = i, y = j;
        x += dx[dir];
        y += dy[dir];
        bool ok = false;
        while (0 <= x && x < h && 0 <= y && y < w) {
          if (s[x][y] != '.') {
            ok = true;
            break;
          }
          x += dx[dir];
          y += dy[dir];
        }
        if (!ok) {
          for (int dir = 0; dir < 4; dir++) {
            int x = i, y = j;
            x += dx[dir];
            y += dy[dir];
            ok = false;
            while (0 <= x && x < h && 0 <= y && y < w) {
              if (s[x][y] != '.') {
                ok = true;
                break;
              }
              x += dx[dir];
              y += dy[dir];
            }
            if (ok) break;
          }
          if (ok) {
            ans++;
          } else {
            ans = -1;
            break;
          }
        }
      }
      if (ans == -1) break;
    }
    if (ans == -1) puts("IMPOSSIBLE");
    else printf("%d\n", ans);
  }
  return 0;
}
