#include <stdio.h>
#include <assert.h>
#include <memory.h>


#define MAXN 4000
#define MAXM 20000

int a[2 * MAXN][2 * MAXN];

int c[MAXM + 1], f[MAXM + 1];
int x[MAXM], y[MAXM];
int cc;
int n;

void clear () {
  memset (a, 0, sizeof (a));
  memset (c, 0, sizeof (c));
  cc = 1;
}

int valid (int x, int y) {
  return (x >= 1 && y >= 1 && x<= 2 * n - 1 && y <= 2 * n - 1 && x - y <= n - 1 && y - x <= n - 1);
}

void unionc (int x, int y) { 
  int i;
  for (i = 0; i < cc; i++) if (c[i] == y) {
    f[x] |= f[i];
    c[i] = x;
  }
}


int is_bridge (int x) {
  int k = 0;
  int i;
  for (i = 0; i < 6; i++) {
    if (x & 1) {
      k ++;
    }
    x >>= 1;
  }
  return k >= 2;
}

int is_fork (int x) {
  x >>= 6;
  int i;
  int k = 0;
  for (i = 0; i < 6; i++) {
    if (x & 1) {
      k ++;
    }
    x >>= 1;
  }
  return k >= 3;
}

int dx[6] = {-1, 0, 1, 1, 0, -1};
int dy[6] = {-1, -1, 0, 1, 1, 0};
int add (int x, int y) {
  assert (valid (x, y));
  assert (!a[x][y]);
  int d[6];
  int i, j, k;
  for (i = 0; i < 6; i++) {
    if (valid (x + dx[i], y + dy[i])) {
      d[i] = c[a[x + dx[i]][y + dy[i]]];
      //fprintf (stderr, "+ %d %d ", x + dx[i], y + dy[i]);
    } else {
      d[i] = 0;
      //fprintf (stderr, "- %d %d ", x + dx[i], y + dy[i]);
    }
    //fprintf (stderr, "%d\n", d[i]);
  }
  int color = -1;
  int kk = 0;
  for (i = 0; i < 6; i++) {
    if (d[i] != 0) {
      k = 0;
      for (j = 0; j < 6; j ++) if (d[j] == d[i]) {
        int t = j + 1;
        if (t == 6) t = 0;
        assert (d[t] == 0 || d[t] == d[i]);
        if (d[t] == 0) {
           k++;
        }
      }
      if (k > kk) {
        kk = k;
      }
    }
  }
  for (i = 0; i < 6; i++) {
    if (d[i] != 0) {
      color = d[i];
    }
    for (j = i + 1; j < 6; j++) {
      if (d[i] != d[j] && d[i] != 0 && d[j] != 0) {
        unionc (d[i], d[j]);        
        int t = d[j];
        for (k = 0; k < 6; k++)
          if (d[k] == t) {
            d[k] = d[i];
          }
      }
    }
    if (d[i]) {
      break;
    }
  }
  if (color == -1) {
    color = cc ++;
    c[color] = color;
    f[color] = 0;
  }
  //fprintf (stderr, "color = %d\n", color);
  a[x][y] = color;
  int flag = 0;
  if (x == 1 && y == 1) flag |= 1;
  if (x == 1 && y == n) flag |= 2;
  if (x == n && y == 2 * n - 1) flag |= 4;
  if (x == n && y == 1) flag |= 8;
  if (x == 2 * n - 1 && y == n) flag |= 16;
  if (x == 2 * n - 1 && y == 2 * n - 1) flag |= 32;
  if (x == 1 && y > 1 && y < n) flag |= 64;
  if (y == 1 && x > 1 && x < n) flag |= 128;
  if (x == 2 * n - 1 && y > n && y < 2 * n - 1) flag |= 256;
  if (y == 2 * n - 1 && x > n && x < 2 * n - 1) flag |= 512;
  if (x - y == n - 1 && y != 1 && y != n) flag |= 1024;
  if (y - x == n - 1 && x != 1 && x != n) flag |= 2048;
  f[color] |= flag;
  int ok = 0;
  if (is_bridge (f[color])) {
    if (ok) printf ("-");
    ok = 1;
    printf ("bridge");
  }
  if (is_fork (f[color])) {
    if (ok) printf ("-");
    ok = 1;
    printf ("fork");
  }
  if (kk >= 2) {
    if (ok) printf ("-");
    ok = 1;
    printf ("ring");
  }
  return ok;
}

int main () {
  int __;
  scanf ("%d", &__);
  int _;
  for (_ = 0; _ < __; _ ++) {
    printf ("Case #%d: ", _ + 1);
    int m;
    scanf ("%d%d", &n, &m);
    clear ();
    int i;
    for (i = 0; i < m; i++) {
      scanf ("%d%d", &x[i], &y[i]);
    }
    int ok = 0;
    for (i = 0; i < m; i++) {
      if (add (x[i], y[i])) {
        printf (" in move %d\n", i + 1);
        ok = 1;
        break;
      }
    }
    if (!ok) {
      printf ("none\n");
    }
    //fprintf (stderr, "----\n");
    //printf ("\n");
  }
  return 0;
}
