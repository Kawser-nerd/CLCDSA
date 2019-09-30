/* 09:17 - */

#include <stdio.h>

int 
gcd (int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd (b, a % b);
  }
}

int
main () {
  int ntest, testno;

  scanf ("%d", &ntest);
  for (testno = 1; testno <= ntest; testno++) {
    long long N;
    int PD, PG;

    int res = 0;
    scanf ("%lld%d%d", &N, &PD, &PG);
    if (PG == 0 || PG == 100) {
      if (PD == PG) {
        res = 1;
      } else {
        res = 0; 
      }
    } else {
      long long d = (long long) gcd (PD, 100);
      if (N >= (long long) 100 / d) {
        res = 1;
      } else {
        res = 0;
      }
    }

    printf ("Case #%d: %s\n", testno, res ? "Possible" : "Broken");
  }

  return 0;
}
