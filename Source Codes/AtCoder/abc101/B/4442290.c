#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  long n, sn = 0, nc;

  if(scanf("%ld", &n) == 1);

  nc = n;

  while(n) {
    sn += n % 10;
    n /= 10;
  }

  if(nc % sn == 0) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}