#include <stdio.h>

int main(void){
  int N;
  long a;
  long long ans = 0;

  scanf("%d",&N);
  for(int i = 0;i < N;i++){
    scanf("%ld",&a);
    ans += a;
  }

  printf("%lld\n",ans-N);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&a);
     ^