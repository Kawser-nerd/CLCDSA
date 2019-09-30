#include <stdio.h>

int main(void) {
  int k, odd, even;
  scanf("%d", &k);
  even = k/2; odd = k - even;
  printf("%d\n", odd*even);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &k);
   ^