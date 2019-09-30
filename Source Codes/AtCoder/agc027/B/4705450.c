#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

void run (void) {
  i32 n, x;
  scanf ("%" SCNi32 "%" SCNi32, &n, &x);
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, a + i);
  }
  i64 *sum = (i64 *) calloc (n + 1, sizeof (i64));
  for (i32 i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + a[i - 1];
  }
  i64 ans = (i64) 5 * n * 1000000000 + (i64) 2 * n * x;
  for (i32 i = 1; i <= n; ++i) {
    i64 local = (i64) x * (n + i);
    for (i32 j = n, k = 1; j > 0 && local < ans; j -= i, ++k) {
      i32 b = j >= i ? j - i : 0;
      local += (sum[j] - sum[b]) * (k == 1 ? 5 : 2 * k + 1);
    }
    if (local < ans) {
      ans = local;
    }
  }
  printf ("%" PRIi64 "\n", ans);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &n, &x);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, a + i);
     ^