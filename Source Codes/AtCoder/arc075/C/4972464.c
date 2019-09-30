#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int32_t i32;
typedef int64_t i64;

i64 calc_inversion (i64 *a, i32 n) {
  static i64 *tmp = NULL;
  if (tmp == NULL) {
    tmp = (i64 *) calloc (n, sizeof (i64));
  }
  if (n <= 1) return 0;
  i32 m = n / 2;
  i64 ans = calc_inversion (a, m) + calc_inversion (a + m, n - m);
  i32 i = 0;
  i32 j = m;
  i32 k = 0;
  while (i < m && j < n) {
    if (a[i] <= a[j]) {
      tmp[k++] = a[i++];
    } else {
      ans += m - i;
      tmp[k++] = a[j++];
    }
  }
  while (i < m) tmp[k++] = a[i++];
  memcpy (a, tmp, sizeof (i64) * k);
  return ans;
}

void run (void) {
  i32 n, k;
  scanf ("%" SCNi32 "%" SCNi32, &n, &k);
  i64 *sum = (i64 *) calloc (n + 1, sizeof (i64));
  for (i32 i = 1; i <= n; ++i) {
    i32 a;
    scanf ("%" SCNi32, &a);
    sum[i] = sum[i - 1] + a - k;
  }
  i64 ans = (i64) (n + 1) * n / 2 - calc_inversion (sum, n + 1);
  printf ("%" PRIi64 "\n", ans);
}

int main (void) {
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &n, &k);
   ^
./Main.c:40:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, &a);
     ^