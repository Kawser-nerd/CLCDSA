#include<stdio.h>

int main(void)
{
  int n=0;
  scanf("%d",&n);
  if(n<12){
    printf("%d\n",n+1);
  }else if (n==12){
    printf("1\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^