/* 11:30, 11:42 - */
#include <stdio.h>

int
main () {
  int ntest, testno;
  int candyarr[1000];
  int ncandy;
  int i;
  int sum, min, xor;

  scanf ("%d", &ntest);
  for (testno = 1; testno <= ntest; testno++) {
    scanf ("%d", &ncandy);
    for (i = 0; i < ncandy; i++) {
      scanf ("%d", &candyarr[i]);
    }

    sum = 0;
    xor = 0;
    min = 1000000;
    for (i = 0; i < ncandy; i++) {
      sum += candyarr[i];
      xor ^= candyarr[i];
      if (candyarr[i] < min) {
        min = candyarr[i];
      }
    }
    
    printf ("Case #%d: ", testno);
    if (xor) {
      printf ("NO\n");
    } else {
      printf ("%d\n", sum - min);
    }
  }

  return 0;
}
