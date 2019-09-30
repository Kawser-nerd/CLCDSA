/* 11:52, 12:12 - */
#include <stdio.h>
#include <string.h>

/*
double 
fact (int n) {
  double ret = 1.0;
  int i;
  for (i = 2; i <= n; i++) {
    ret *= i;
  }
  return ret;
}
*/

int
main () {
  int ntest, testno;
  int arrsize;
  int i;
  int arr[1001];
  int mark[1001];
  double res;
  
  scanf ("%d", &ntest);
  for (testno = 1; testno <= ntest; testno++) {
    scanf ("%d", &arrsize);
    for (i = 1; i <= arrsize; i++) {
      scanf ("%d", &arr[i]);
    }

    memset (mark, 0, sizeof (mark));
    res = 0.0;
    for (i = 1; i <= arrsize; i++) {
      int num = arr[i];
      if (mark[num]) {
        continue;
      }
      int len = 0;
      int pos = i;
      while (!mark[num = arr[pos]]) {
        mark[num] = 1;
	pos = num;
	len++;
      }

      // accumulate
      if (len > 1) {
        res += len;
      }
    }

    printf ("Case #%d: %.6lf\n", testno, res);
  }

  return 0;
}
