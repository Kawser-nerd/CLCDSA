#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  int d, n;
  long ans;

  if(scanf("%d %d", &d, &n) == 1);

  if(n == 100) {
    n++;
  }

  ans = (long)pow(100, d) * n;

  printf("%ld", ans);

  return 0;
}