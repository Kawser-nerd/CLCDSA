#include <stdio.h>

int main(void)
{
  long long int s,t;
  scanf("%lld%lld",&s,&t);
  printf("%lld\n",t-s+1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&s,&t);
   ^