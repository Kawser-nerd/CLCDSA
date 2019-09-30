#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(void){
  int n,i,price[11],max=0,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&price[i]);
    if(price[i]>max) max=price[i];
    sum+=price[i];
  }
  sum-=max;
  printf("%d",sum+(max/2));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&price[i]);
     ^