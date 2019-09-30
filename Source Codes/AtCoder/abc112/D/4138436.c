#include <stdio.h>

int main(void){
  long N;
  long long M;
  scanf("%ld%lld",&N,&M);

  for(int i = M/N;i > 0;i--){
    if(M%i == 0){
      printf("%d",i);
      return 0;
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%lld",&N,&M);
   ^