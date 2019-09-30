#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  int n;
  long a[1000], max = - 1, min = 999999999999999;

  if(scanf("%d", &n) == 1);

  for(int i = 0; i < n; i++) {
    if(scanf("%ld", &a[i]) == 1);
    if(a[i] < min) {
      min = a[i];
    }
    if(a[i] > max) {
      max = a[i];
    }
  }



  printf("%ld", max - min);

  return 0;
}