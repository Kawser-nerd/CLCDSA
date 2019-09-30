#include <stdio.h>

int main(void){
  long long N;
  int X = 0;
  scanf("%lld",&N);

  long long m = N;
  while(m > 0){
    X += m%10;
    m /= 10;
  }

  if(N%X == 0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&N);
   ^