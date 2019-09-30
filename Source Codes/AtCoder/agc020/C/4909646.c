#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef uint64_t u64;
typedef uint32_t u32;

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  i32 sum = 0;
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, a + i);
    sum += a[i];
  }
  const u32 b = sizeof (u64) * 8;
  const i32 len = (sum + b - 1) / b;
  u64 *dp = (u64 *) calloc (len + 1, sizeof (u64));
  dp[0] = 1;
  for (i32 i = 0; i < n; ++i) {
    const u32 v = a[i];
    u32 p = v / b;
    u32 q = v % b;
    if (q == 0) {
      for (i32 j = len - 1 - p; j >= 0; --j) {
        dp[j + p] |= dp[j];
      }
    } else {
      for (i32 j = len - 1 - p; j >= 0; --j) {
        u64 y = dp[j];
        dp[j + p] |= y << q;
        dp[j + p + 1] |= y >> (b - q);
      }
    }
  }
  i32 m = (sum + 1)/ 2;
  while (((dp[m / b] >> (m % b)) & 1) == 0) m++;
  printf ("%" PRIi32 "\n", m);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &n);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, a + i);
     ^