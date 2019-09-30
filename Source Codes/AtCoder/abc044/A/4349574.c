#include<stdio.h>
int main(void){
  int n,k,x,y;
  scanf("%d",&n);
  scanf("%d",&k);
  scanf("%d",&x);
  scanf("%d",&y);
  if(n>k) printf("%d\n",(n-k)*y+k*x);
  else printf("%d\n",n*x);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&y);
   ^