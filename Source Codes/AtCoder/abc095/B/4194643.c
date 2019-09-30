#include <stdio.h>
int main(void){
  int cheapest, m, n, x, i;
  scanf("%d%d",&n,&x);
  for(i=0;i<n;i++){
    scanf("%d",&m);
    if(cheapest==0||m<cheapest)cheapest=m;
    x-=m;
  }
  printf("%d",n+x/cheapest);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m);
     ^