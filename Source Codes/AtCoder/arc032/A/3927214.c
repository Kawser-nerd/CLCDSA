#include<stdio.h>
int n;
int main()
{
  scanf("%d",&n);
  if(n!=2)
  printf("BOWWOW\n");
  else 
  printf("WANWAN\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^