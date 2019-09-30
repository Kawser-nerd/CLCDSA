#include <stdio.h>
#include <assert.h>
#include <string.h>

#define S (k >= i + 1 ? v[i][k - 1] : 1) * (k <= j - 1 ? v[k + 1][j] : 1) * (k - i + 1) * c[(k >= i + 1 ? u[i][k-1] : 0) + (k <= j - 1 ? u[k + 1][j] : 0)][(k >= i + 1 ? u[i][k - 1] : 0)]

int N;

long double f (int n) {
  return N - (n - 1) * 0.5;
}

#define MAXN 205

long double a[MAXN * 2];
long double v[MAXN * 2][MAXN * 2];
long double c[MAXN * 2][MAXN * 2];
int u[MAXN * 2][MAXN * 2];
long double r[MAXN * 2][MAXN * 2];

char s[MAXN];

void solve (void) {
  scanf ("%s\n", s);
  assert (strlen (s) <= 200);
  memset (a, 0, sizeof (a));
  memset (v, 0, sizeof (v));
  memset (c, 0, sizeof (c));
  memset (u, 0, sizeof (u));
  memset (r, 0, sizeof (r));

  int n = strlen (s);
  N = n;
  int i, j;
  int qq = 0;
  for (i = 0; i < n; i++) {
    a[i] = s[i] == 'X';
    a[i + n] = a[i];
    qq += (1 - a[i]);
  }
  for (i = 0; i <= 2 * n; i++) {
    v[i][i] = 1;
    u[i][i] = 1 - a[i];
  }
  for (i = 0; i < 2 * n; i++)
    for (j = i + 1; j < 2 * n; j++)
      u[i][j] = u[i][j - 1] + (1 - a[j]);
      
  c[0][0] = 1;
  for (i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (j = 1; j <= i; j++)
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  }
  int l;
  for (l = 2; l <= n; l++) {
    for (i = 0; i < 2 * n && i + l <= 2 * n; i++) {
      int k;
      long double w = 0;
      int ok = 0;
      j = i + l - 1;
      for (k = i; k < i + l; k++) if (!a[k]) {
        ok = 1;
        w += S;
        assert (S >= 0);
      }
      if (!ok) {
        w = 1;
      }
      assert (w > 0);
      v[i][j] = w;
    }
  }
  for (l = 1; l <= n; l ++) {
    for (i = 0; i < 2 * n && i + l <= 2 * n; i++) {
      int j = i + l - 1;
      int k;
      long double w = 0;
      for (k = i; k <= j; k++) if (!a[k]) {
        w += S / v[i][j] * ((k >= i + 1 ? r[i][k - 1] : 0) + (k <= j - 1 ? r[k + 1][j] : 0) + f (k - i + 1));
      }
      r[i][j] = w;
    }
  }
  long double rr = 0;
  for (i = 0; i < n; i++) if (!a[i + n - 1]) {
    j = i + n - 1;
    int k = j;
    assert (S <= v[i][j]);
    int cc;
    long double eee = S * ((j >= i + 1? r[i][j - 1] : 0) + f (n));
    for (cc = 0; cc < qq; cc++) {
      eee /= n;
    }
    rr += eee;
  }
  printf ("%18.18lf\n", (double)rr);
}

int main () {
  int _;
  assert (scanf ("%d\n", &_) > 0);
  int __;
  for (__ = 0; __ < _; __++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
  return 0;
}
