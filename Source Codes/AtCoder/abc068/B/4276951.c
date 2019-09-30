#include<stdio.h>
int main(){
  int n,i=1;
  scanf("%d",&n);
  while(i<=n)i*=2;
  printf("%d",i/2);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^