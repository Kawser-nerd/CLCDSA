#include <stdio.h>

int main()
{
  int N;
  scanf("%d", &N);
  printf("%d", N*(N+1)/2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^