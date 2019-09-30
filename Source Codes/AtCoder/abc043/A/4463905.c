#include<stdio.h>
int main(void)
{
  int n, ans=0, i=0;
  scanf("%d", &n);
  for(i=0;i<=n;i++){
    ans+=i;
  }
  printf("%d", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^