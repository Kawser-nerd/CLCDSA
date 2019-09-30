#include<stdio.h>
long long int X;
int A, B, C;
int mod = 1000000007;
int main(){
  scanf("%d%d%d", &A, &B, &C);
  X=A;
  X*=B;
  X%=mod;
  X*=C;
  X%=mod;
  printf("%lld\n", X);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &A, &B, &C);
   ^