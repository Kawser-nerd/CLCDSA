#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

void run (void) {
  i32 k, n;
  scanf ("%" SCNi32 "%" SCNi32, &k, &n);
  i32 *a = (i32 *) calloc (2 * n, sizeof (i32));
  i32 *d = a + n;
  for (i32 i = 0; i < n; ++i){
    scanf ("%" SCNi32 "%" SCNi32, a + i, d + i);
  }
  i64 l = 0;
  i64 r = (i64) 1000 * k + 1000;
  while (r - l > 1) {
    i64 m = (l + r) / 2;
    i64 cnt = 0;
    for (i32 i = 0; i < n && cnt < k; ++i) {
      if (a[i] > m) continue;
      cnt += (m - a[i]) / d[i] + 1;
    }
    if (cnt >= k) {
      r = m;
    } else {
      l = m;
    }
  }
  i64 cnt = 0;
  i64 sum = 0;
  for (i32 i = 0; i < n; ++i) {
    if (a[i] > r) continue;
    i64 m = (r - a[i]) / d[i] + 1;
    cnt += m;
    sum += m * a[i] + (m - 1) * m / 2 * d[i];
  }
  i64 ans = sum - (cnt - k) * r;
  printf ("%" PRIi64 "\n", ans);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &k, &n);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32, a + i, d + i);
     ^