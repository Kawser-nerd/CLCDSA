#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

int cmp (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  i32 n, k;
  scanf ("%" SCNi32 "%" SCNi32, &n, &k);
  i32 *a = (i32 *) calloc (2 * n, sizeof (i32));
  i32 *b = a + n;
  for (i32 i = 0; i < 2 * n; ++i) {
    scanf ("%" SCNi32, a + i);
  }
  qsort (a, n, sizeof (i32), cmp);
  qsort (b, n, sizeof (i32), cmp);
  i64 l = 0;
  i64 r = 1000000000000000000;
  while (r - l > 1) {
    i64 m = (l + r) / 2;
    i32 cnt = 0;
    i32 j = n - 1;
    for (i32 i = 0; i < n; ++i) {
      while (j >= 0 && (i64) a[i] * b[j] > m) --j;
      cnt += j + 1;
    }
    if (cnt >= k) {
      r = m;
    } else {
      l = m;
    }
  }
  printf ("%" PRIi64 "\n", r);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &n, &k);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, a + i);
     ^