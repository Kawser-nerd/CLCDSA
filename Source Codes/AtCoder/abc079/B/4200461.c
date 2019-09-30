#include<stdio.h>

int main(){
  long long L[87], N;
  
  scanf("%lld", &N);
  
  L[0] = 2;
  L[1] = 1;
  for (int i = 2; i <= N; i++){
    L[i] = L[i - 1] + L[i - 2];
  }
  
  printf("%lld\n", L[N]);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &N);
   ^