#include<stdio.h>

int main(void)
{
  int n;
  int second;
  int minute;
  int hour;

  scanf("%d",&n);
  printf("%02d:%02d:%02d\n",n/3600,(n%3600)/60,((n%3600)%60));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^