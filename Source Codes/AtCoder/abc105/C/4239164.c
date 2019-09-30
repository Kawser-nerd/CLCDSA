#include <stdio.h>

int main(void){
  long long N;
  long counter = 0;
  scanf("%lld",&N);
  int ans[1000];

  if(N == 0){
    printf("0\n");
    return 0;
  }
  while(N != 0){
    if(N%(-2) == 0){
      ans[counter] = 0;
    }else{
      ans[counter] = 1;
      N--;
    }
    N /= -2;
    counter++;
  }

  while(counter > 0){
    printf("%d",ans[counter-1]);
    counter--;
  }
  printf("\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&N);
   ^