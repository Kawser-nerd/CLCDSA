#include <stdio.h>

int main(void){
  long long A,B;
  int K;

  scanf("%lld%lld%d",&A,&B,&K);

  for(int i = A;i < A+K && i <= B;i++){
    printf("%d\n",i);
  }
  for(int i = B-K+1;i <= B;i++){
    if(i >= A+K)
      printf("%d\n",i);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%d",&A,&B,&K);
   ^