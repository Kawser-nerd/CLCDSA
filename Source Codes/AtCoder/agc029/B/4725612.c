#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

int cmp (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, a + i);
  }
  qsort (a, n, sizeof (i32), cmp);
  i32 ans = 0;
  for (i32 bit = 30; bit >= 1; --bit) {
    i32 i = 0;
    i32 j = n - 1;
    i32 sum = 1 << bit;
    while (i < j) {
      if (a[i] + a[j] == sum) {
	ans++;
	a[i] = a[j] = 0;
	i++;
	j--;
      } else if (a[i] + a[j] < sum) {
	i++;
      } else {
	j--;
      }
    }
    j = 0;
    for (i = 0; i < n; ++i) {
      if (a[i] > 0) {
	a[j++] = a[i];
      }
    }
    n = j;
  }
  printf ("%" PRIi32 "\n", ans);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &n);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, a + i);
     ^