#include <cassert>
#include <cstdio>

const int maxr = 100;
char a[maxr][maxr];

void solve ( int sx, int tx, int sy, int ty ) {
  int x1 = -1, y1 = -1;
  int x2 = -1, y2 = -1;
  for (int x = sx; x < tx && x2 == -1 && y2 == -1; x++)
    for (int y = sy; y < ty; y++) {
      if (a[x][y] == '?')
        continue;
      if (x1 == -1 && y1 == -1) {
        x1 = x, y1 = y;
        continue;
      }
      x2 = x, y2 = y;
      break;
    }
  assert (x1 != -1 && y1 != -1);
  if (x2 == -1 && y2 == -1) {
    for (int x = sx; x < tx; x++)
      for (int y = sy; y < ty; y++)
        a[x][y] = a[x1][y1];
    return;
  }
  assert (x2 != -1 && y2 != -1);
  if (x1 != x2) {
    if (x1 > x2)
      x2 = x1;
    solve (sx, x2, sy, ty);
    solve (x2, tx, sy, ty);
  } else {
    if (y1 > y2)
      y2 = y1;
    solve (sx, tx, sy, y2);
    solve (sx, tx, y2, ty);
  }
}

int main () {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int r, c;
    assert (scanf ("%d%d", &r, &c) == 2);
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        assert (scanf (" %c", &a[i][j]) == 1);
    solve (0, r, 0, c);
    printf ("Case #%d:\n", tt);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++)
        putc (a[i][j], stdout);
      puts ("");
    }
  }
}

