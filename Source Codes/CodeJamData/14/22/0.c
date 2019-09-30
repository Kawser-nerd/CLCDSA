#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

long long x[8][33];

void solve (void) {
  int a, b, k;
  assert (scanf ("%d %d %d", &a, &b, &k) == 3);

  int i, j;
  for (i = 0; i <= 32; i++) {
    for (j = 0; j < 8; j++) {
      x[j][i] = (i == 0 && j == 0);
    }
  }
  for (i = 1; i <= 32; i++) {
    int ra = (a & (1ll << (i - 1))) != 0;
    int rb = (b & (1ll << (i - 1))) != 0;
    int rk = (k & (1ll << (i - 1))) != 0;
    for (j = 0; j < 8; j++) {
      int ca;
      int cb; 
      for (ca = 0; ca < 2; ca ++)
        for (cb = 0; cb < 2; cb ++) {
	  if (ca && !ra && (j & 1)) { 
	    continue;
	  }
	  if (cb && !rb && (j & 2)) { 
	    continue;
	  }
	  int ck = ca & cb;
	  if (ck && !rk && (j & 4)) {
	    continue;
	  }
	  int jj = 0;
	  if ((j & 1) && ca == ra) {
	    jj |= 1;
	  }
	  if ((j & 2) && cb == rb) {
	    jj |= 2;
	  }
	  if ((j & 4) && ck == rk) {
	    jj |= 4;
	  }
	  x[j][i] += x[jj][i - 1];
	}
    }
  }
  printf ("%lld\n", x[7][32]);
}

int main () {
  int _;
  assert (scanf ("%d", &_) == 1);
  int __;
  for (__ = 0; __ < _; __ ++) {
    printf ("Case #%d: ", __ + 1);
    solve ();
  }
  return 0;
}
