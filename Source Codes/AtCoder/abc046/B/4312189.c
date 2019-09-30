#include<stdio.h>
int main(){
  int n,k,a;
  scanf("%d%d",&n,&k);
  a=k;
  while(--n) a*=k-1;
  printf("%d",a);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^