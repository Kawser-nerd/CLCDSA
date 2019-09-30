#include <stdio.h>

int n;
long long int memo[87] = {0};

long long int func(int m){
  if (m == 0) {
    return 2;
  }
  if (m == 1) {
    return 1;
  }
  if (memo[m] > 0) {
    return memo[m];
  }
  memo[m-1] = func(m-1);
  memo[m-2] = func(m-2);
  return memo[m-1] + memo[m-2];
}

int main(void){

  scanf("%d", &n);

  printf("%lld\n", func(n));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^