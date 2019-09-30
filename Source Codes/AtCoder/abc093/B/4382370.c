#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  int a,b,k,i;
  scanf("%d%d%d",&a,&b,&k);
  for(i=a;i<=fmin(b,a+k-1);i++){
    printf("%d\n",i);
  }
  for(i=fmax(b-k+1,a+k);i<=b;i++){
    printf("%d\n",i);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&k);
   ^