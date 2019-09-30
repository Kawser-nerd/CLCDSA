#include <stdio.h>

int main(void){
  long long A,K;
  scanf("%lld%lld",&A,&K);

  if(K == 0) printf("%lld\n",2000000000000-A);
  else{
    for(int i = 0;;i++){
      A += 1+A*K;
      if(A >= 2000000000000){
        printf("%d\n",i+1);
        break;
      }
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&A,&K);
   ^