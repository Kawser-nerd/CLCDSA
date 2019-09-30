#include <stdio.h>
#include <math.h>

int main(void){
  int N,K;
  scanf("%d%d",&N,&K);

  long ans = K;

  ans *= (long)pow((K-1),N-1);
  printf("%ld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&K);
   ^