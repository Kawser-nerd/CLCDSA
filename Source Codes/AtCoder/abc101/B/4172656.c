#include <stdio.h>

int main(void){
  long long N,sample;
  scanf("%lld",&N);

  sample = N;
  int sum = 0;
  while(sample > 0){
    sum += sample%10;
    sample /= 10;
  }

  if(N%sum == 0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&N);
   ^