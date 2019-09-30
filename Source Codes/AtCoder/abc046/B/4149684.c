#include <stdio.h>
#include <math.h>

int main(void){
  int n, k;
  scanf("%d %d", &n, &k);
  double c = pow(k - 1, n - 1);
  k *= c;
  n = (int) k;
  printf("%d\n", n);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &k);
   ^