#include<stdio.h>
int main(){
  int n,a,b,c=5;
  scanf("%d %d %d",&n,&a,&b);
  if(n<5)c=n;
  printf("%d\n",c*b+(n-c)*a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&a,&b);
   ^