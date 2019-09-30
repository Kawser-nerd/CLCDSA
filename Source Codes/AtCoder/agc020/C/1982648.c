#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long u64;

#define N (62500)

u64 dp[N + 1000];

int main(void) {
  int n;
  scanf("%d", &n);
  
  dp[0] = 1;

  int s = 0;
  while (n--) {
    int a;
    scanf("%d", &a);

    s += a;

    int H = a / 64;
    int L = a % 64;

    if (L == 0) {
      for (int i = N; i >= 0; i--) {
        dp[i + H] |= dp[i];
      }
    } else {
      for (int i = N; i >= 0; i--) {
        dp[i + H + 1] |= dp[i] >> (64 - L);
        dp[i + H] |= dp[i] << L;
      }
    }
  }

  s = (s + 1) / 2;
  while (~dp[s / 64] >> s % 64 & 1) s++;

  printf("%d\n", s);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^