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
  i32 n, x;
  scanf ("%" SCNi32 "%" SCNi32, &n, &x);
  i32 a[100];
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, a + i);
  }
  qsort (a, n, sizeof (i32), cmp);
  i32 i = 0;
  while (i < n && a[i] <= x) {
    x -= a[i];
    i++;
  }
  if (i >= n && x > 0) i--;
  printf("%" PRIi32 "\n", i);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &n, &x);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, a + i);
     ^