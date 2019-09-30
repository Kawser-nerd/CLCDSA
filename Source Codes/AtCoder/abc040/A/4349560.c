#include<stdio.h>
int main(void){
  int n,x;
  scanf("%d%d",&n,&x);
  if((n-x)>x-1) printf("%d\n",x-1);
  else printf("%d\n",n-x);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^