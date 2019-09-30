#include <stdio.h>

int main() {
  float T, X;
  scanf("%f %f", &T, &X);
  float ans = T / X;
  printf("%f\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%f %f", &T, &X);
   ^