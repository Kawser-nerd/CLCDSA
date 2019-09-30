#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int main(void){
  int a,b,sa;
  scanf("%d%d",&a,&b);
  sa=b-a;
  int t1,i,sum=0;
  for(i=1;i<sa;i++){
    sum+=i;
  }
  printf("%d",sum-a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^