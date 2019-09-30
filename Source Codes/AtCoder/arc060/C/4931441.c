#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

#define POS(i, j) ((i) * bit + (j))

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  i32 *x = (i32 *) calloc (n + 1, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, x + i);
  }
  i32 l;
  scanf ("%" SCNi32, &l);
  x[n] = x[n - 1] + l;
  i32 bit = 0;
  while ((1 << bit) < n + 1) bit++;
  i32 *dp = (i32 *) calloc ((n + 1) * bit, sizeof (i32));
  for (i32 i = 0, j = 0; i <= n; ++i) {
    while (j <= n && x[j] - x[i] <= l) j++;
    dp[POS(i, 0)] = j - 1;
  }
  for (i32 k = 1; k < bit; ++k) {
    for (i32 i = 0; i <= n; ++i) {
      i32 a = dp[POS(i, k - 1)];
      dp[POS(i, k)] = dp[POS(a, k - 1)];
    }
  }
  i32 q;
  scanf ("%" SCNi32, &q);
  while (q--) {
    i32 a, b;
    scanf ("%" SCNi32 "%" SCNi32, &a, &b);
    a--;
    b--;
    if (a > b) {
      i32 s = b;
      b = a;
      a = s;
    }
    i32 ans = 0;
    i32 j = bit - 1;
    while (a < b) {
      while (j > 0 && dp[POS(a, j)] > b) --j;
      ans += 1 << j;
      a = dp[POS(a, j)];
    }
    printf ("%" PRIi32 "\n", ans);
  }
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &n);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, x + i);
     ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &l);
   ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &q);
   ^
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32, &a, &b);
     ^