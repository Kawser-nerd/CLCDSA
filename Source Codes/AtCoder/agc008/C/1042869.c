#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SHAPE 7

int main() {
  long int a[7];
  int i;
  for (i = 0; i < 7; i++) {
    scanf(" %ld", &a[i]);
  }
  long int sum = 0;
  int sum1;

  sum1 = a[0] % 2 + a[3] % 2 + a[4] % 2;
  if (sum1<=1||a[0]*a[3]*a[4]==0) {
    sum += (a[0] / 2) * 4;
    sum += (a[3]/2)*4;
    sum += (a[4] / 2) * 4;
  }
  else if (sum1 == 2){
    sum += (a[0] + a[3] + a[4] - 4) * 2 + 6;
  }
  else {
    sum += (a[0] + a[3] + a[4] - 3) * 2 + 6;
  }

  sum += a[1] * 2;

  printf("%ld\n", sum/2);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf(" %ld", &a[i]);
     ^