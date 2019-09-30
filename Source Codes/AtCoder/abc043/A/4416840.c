#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  int n,i,sum=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    sum+=i;
  }
  printf("%d",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^