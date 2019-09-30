#include <stdio.h>
#include <math.h>
int main(void){
  int x,costmin=1E9,i,j;
  scanf("%d",&x);
  for(i=1;i<=1E9;i++){
    int sum=(i*(i+1))/2;
    if(sum>=x) {printf("%d",i);return 0;}
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^