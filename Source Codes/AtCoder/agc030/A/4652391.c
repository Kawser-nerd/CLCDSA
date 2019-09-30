#include <stdio.h>

int main(void) {
  long long A, B, C;
  scanf("%lld%lld%lld\n", &A, &B, &C);
  if (A+B<C) printf("%lld\n", A+1+2*B);
  else printf("%lld\n", C+B);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld\n", &A, &B, &C);
   ^