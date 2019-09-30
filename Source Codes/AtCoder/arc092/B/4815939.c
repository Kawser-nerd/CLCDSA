#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

int cmp (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

i32 calc (const i32 v, const i32 *a, const i32 *b, const i32 n) {
  i32 cnt = 0;
  i32 j = n - 1;
  for (i32 i = 0; i < n; ++i) {
    while (j >= 0 && a[i] + b[j] >= v) j--;
    cnt += (n - 1 - j) & 1;
  }
  return cnt & 1;
}

void sub_and_sort (const i32 sub, i32 *a, const i32 n, i32 *tmp) {
  i32 j = 0;
  for (; j < n && a[j] < sub; ++j);
  const i32 m = j;
  i32 i = 0;
  i32 k = 0;
  while (i < m && j < n) {
    if (a[i] <= a[j] - sub) {
      tmp[k++] = a[i++];
    } else {
      tmp[k++] = a[j++] - sub;
    }
  }
  while (i < m) tmp[k++] = a[i++];
  while (j < n) a[j++] -= sub;
  for (i = 0; i < k; ++i) {
    a[i] = tmp[i];
  }
}

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  i32 *a = (i32 *) calloc (2 * n, sizeof (i32));
  i32 *b = a + n;
  for (i32 i = 0; i < 2 * n; ++i) {
    scanf ("%" SCNi32, a + i);
  }
  qsort (a, n, sizeof (i32), cmp);
  qsort (b, n, sizeof (i32), cmp);
  i32 *tmp = (i32 *) calloc (n, sizeof (i32));
  i32 ans = 0;
  for (i32 bit = 28; bit >= 0; bit--) {
    ans |= (calc (1 << bit, a, b, n) ^ calc (2 << bit, a, b, n) ^ calc (3 << bit, a, b, n)) << bit;
    sub_and_sort (1 << bit, a, n, tmp);
    sub_and_sort (1 << bit, b, n, tmp);
  }
  printf ("%" PRIi32 "\n", ans);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:45:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &n);
   ^
./Main.c:49:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, a + i);
     ^