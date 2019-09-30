#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int cmp (const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

static int x1[1000];
static int x2[1000];
static int y1[1000];
static int y2[1000];

int z[2000];

int a[1000][2000];

int w, h, n;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dzi[] = {0x1, 0x2, 0x4, 0x8};
int dzo[] = {0x10, 0x20, 0x40, 0x80};
int dpzi[] = {0x2, 0x1, 0x8, 0x4};
int dpzo[] = {0x20, 0x10, 0x80, 0x40};
int pr[] = {1, 0, 3, 2};

char f[1000][2000][2][5];
short b[1000][2000][2];

int poisk (int x, int y, int c, int g) {
  if (y == h - 1 && c == 1) {
    return 1;
  }
  b[x][y][c] = g;
  int i;
  if (c == 0) {
    for (i = 0; i < 4; i++) {
      int x1 = x + dx[i];
      int y1 = y + dy[i];
      if (x1 >= 0 && y1 >= 0 && x1 < w && y1 < h && !(a[x1][y1] & 0x100) && f[x][y][0][i] < 0 && b[x1][y1][1] < g) {
        if (poisk (x1, y1, 1, g)) {
          f[x][y][0][i] ++;
          f[x1][y1][1][pr[i]] --;
          return 1;
        }
      }
    }
    if (f[x][y][0][4] <= 0 && b[x][y][1] < g && poisk (x, y, 1, g)) {
      f[x][y][0][4] ++;
      f[x][y][1][4] --;
      return 1;
    }
    return 0;
  } else {
    for (i = 0; i < 4; i++) {
      int x1 = x + dx[i];
      int y1 = y + dy[i];
      if (x1 >= 0 && y1 >= 0 && x1 < w && y1 < h && !(a[x1][y1] & 0x100) && f[x][y][1][i] <= 0 && b[x1][y1][0] < g) {
        if (poisk (x1, y1, 0, g)) {
          f[x][y][1][i] ++;
          f[x1][y1][0][pr[i]] --;
          return 1;
        }
      }
    }
    if (f[x][y][1][4] < 0 && b[x][y][0] < g && poisk (x, y, 0, g)) {
      f[x][y][1][4] ++;
      f[x][y][0][4] --;
      return 1;
    }
    return 0;
  }
}

void solve (void) {
  assert (scanf ("%d %d %d", &w, &h, &n) == 3);
  
  int i;
  for (i = 0; i < n; i++) {
    assert (scanf ("%d %d %d %d\n", &x1[i], &y1[i], &x2[i], &y2[i]) == 4);
    y2[i] ++;
    x2[i] ++;
    z[2 * i] = y1[i];
    z[2 * i + 1] = y2[i];
  }
  int j;
  for (i = 0; i < 2 * n; i++)
    for (j = i + 1; j < 2 * n; j++)
      if (z[i] > z[j]) {
        int t = z[i]; z[i] = z[j]; z[j] = t;
      }

  int sh = 0;
  for (i = 0; i < 2 * n; i++) {
    if (i == 0 || z[i] != z[i - 1]) {
      assert (i == 0 || z[i] > z[i - 1]);
      z[i - sh] = z[i];
    } else {
      sh ++; 
    }
    
  }
/*  h = 2 * n - sh;

  for (i = 0; i < n; i++) {
    for (j = 0; j < h; j++) {
      if (y1[i] == z[j]) {
        y1[i] = j;
        break;
      }
    }
    for (j = 0; j < h; j++) {
      if (y2[i] == z[j]) {
        y2[i] = j;
        break;
      }
    }
  }*/

  
  for (i = 0; i < w; i++)
    for (j = 0; j < h; j++)
      a[i][j] = 0;

  for (i = 0; i < n; i++) {
    int x, y;
    for (x = x1[i]; x < x2[i]; x++)
      for (y = y1[i]; y < y2[i]; y++) {
        a[x][y] |= 0x100;
      }
  }

  for (i = 0; i < w; i++)
    for (j = 0; j < h; j++) {
      memset (f[i][j][0], 0, 5);
      memset (f[i][j][1], 0, 5);
      b[i][j][0] = b[i][j][1] = 0;
    }
 
  int res = 0;
  for (i = 0; i < w; i++) {
    if (!(a[i][0] & 0x100) && poisk (i, 0, 0, i + 1)) {
      res ++;
    }
  }



  printf (" %d\n", res);
}

int main () {
  int _;
  assert (scanf ("%d", &_) == 1);
  int __;
  for (__ = 0; __ < _; __ ++) {
    printf ("Case #%d:", __ + 1);
    solve ();
  }
  return 0;
}
