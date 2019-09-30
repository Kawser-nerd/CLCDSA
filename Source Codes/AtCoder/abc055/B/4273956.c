#include <stdio.h>
#define mod 1000000007

int main(void){
  int N;
  scanf("%d",&N);

  long long ans = 1;
  for(int i = 1;i <= N;i++){
    ans *= i;
    ans %= mod;
  }

  printf("%lld\n",ans);   

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^