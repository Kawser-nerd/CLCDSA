#include <stdio.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

#define MOD 1000000007
#define LC 12

long long inv;

void solve (void) {
  int r, c;
  assert (scanf ("%d %d", &r, &c) == 2);

  static long long res[200][LC + 1];
  memset (res, 0, sizeof (res));
  res[0][1] = 1;

  int i, j;
  for (i = 0; i < r + 2; i++) {
    for (j = 1; j <= LC; j++) {
      if (!res[i][j]) { continue; }
      
      res[i + 3][j] += res[i][j]; // line of 2
      res[i + 3][j] %= MOD;

      if (c % 3 == 0) {
        //221221 
        //221221
        if (j % 3 == 0) {
          res[i + 4][j] += 3 * res[i][j]; 
          res[i + 4][j] %= MOD;
        } else {
          res[i + 4][j * 3] += 3 * res[i][j];
          res[i + 4][j] %= MOD;
        }
      }

      if (c % 4 == 0) {
        //2112222
        //2222112
        if (j % 4 == 0) {
          res[i + 5][j] += 4 * res[i][j]; 
          res[i + 5][j] %= MOD;
        } else if (j % 2 == 0) {
          res[i + 5][j * 2] += 4 * res[i][j];
          res[i + 5][j] %= MOD;
        } else {
          res[i + 5][j * 4] += 4 * res[i][j];
          res[i + 5][j] %= MOD;
        }
      }

      if (c % 6 == 0) {
        //2112222
        //2222112
        if (j % 6 == 0) {
          res[i + 4][j] += 6 * res[i][j]; 
          res[i + 4][j] %= MOD;
        } else if (j % 3 == 0) {
          res[i + 4][j * 2] += 6 * res[i][j];
          res[i + 4][j] %= MOD;
        } else if (j % 2 == 0) {
          res[i + 4][j * 3] += 6 * res[i][j];
          res[i + 4][j] %= MOD;
        } else {
          res[i + 4][j * 6] += 6 * res[i][j];
          res[i + 4][j] %= MOD;
        }
      }

    }
  }

  long long R = 0;
  for (i = -1; i <= 1; i++) {
    for (j = 1; j <= LC; j++) if (LC % j == 0) {
      long long x = (res[2 * i + r][j] * (((LC / j) * inv) % MOD)) % MOD;
      if (i == 0) { R += 2 * x; }
      else { R += x; }
      R %= MOD;
    }
  }
  printf ("%lld\n", R);
}

void prep (void) {
  inv = 1;
  while (inv * LC % MOD != 1) {
    inv ++;
    assert (inv < MOD);
  }
}

int main () {
  int _;
  assert (scanf ("%d\n", &_) == 1);
  int __;

  prep ();
  for (__ = 0; __ < _; __ ++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
  return 0;
}
