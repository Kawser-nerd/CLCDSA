#include<stdio.h>
int main(void)
{
  int n, i=0;
  int a, b, ans, x;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d %d", &a, &b);
    x=b-a+1;
    ans+=x;
    x=0;
  }
  printf("%d", ans);
  return 0;
  } ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^