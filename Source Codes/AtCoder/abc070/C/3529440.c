#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long long gcd(long long a, long long b) {
  long long v0 = a, v1 = b, v2 = a % b;
  while (v2 != 0) {
    v0 = v1;
    v1 = v2;
    v2 = v0 % v1;
  };
  return v1;
}

long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}
 
int main(void){
  
  long long N;
  long long i;

  scanf("%lld", &N);

  long long T[N];
  long long a = 1;

  for(i = 0; i < N; i++){
    scanf("%lld", &T[i]);
    a = lcm(T[i], a);
  }

  printf("%lld\n", a);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &N);
   ^
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &T[i]);
     ^