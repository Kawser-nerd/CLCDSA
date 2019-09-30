#include <stdio.h>

int main()
{
  int n, t;
  
  scanf("%d%d", &n, &t);
  
  printf("%d\n", t - n + 1);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &t);
   ^