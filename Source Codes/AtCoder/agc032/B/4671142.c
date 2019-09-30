#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>
#include<math.h>

typedef int32_t i32;
typedef int64_t i64;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(a) ((a) > (0) ? (a) : -(a))

int can (i32 n, i32 k, i32 *a) {
  i32 p = n * (n + 1) / 2 / k;
  i32 i,j;
  for (i = 1; i <= n; ++i) a[i] = i;
  i32 d = 1;
  for (i = n; i >= 1; --i) {
    if (a[i] <= 0) continue;
    i32 sum = i;
    a[i] = -d;
    for (j = i - 1; j >= 1 && sum < p; --j) {
      if (a[j] <= 0) continue;
      if (j + sum <= p) {
	sum += j;
	a[j] = -d;
      }
    }
    if (sum < p) return 0;
    d++;
  }
  return 1;
}

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  i32 sum = n * (n + 1) / 2;
  i32 *a = (i32 *) calloc (n + 1, sizeof (i32));
  for (i32 k = 2; k <= sum; ++k) {
    if (sum % k != 0) continue;
    if (can (n, k, a)) {
      break;
    }
  }
  i32 i, j;
  i32 cnt = 0;
  for (i = 1; i <= n; ++i) {
    for (j = i + 1; j <= n; ++j) {
      if (a[i] != a[j]) {
	cnt++;
      }
    }
  }
  printf("%" PRIi32 "\n", cnt);
  for (i = 1; i <= n; ++i) {
    for (j = i + 1; j <= n; ++j) {
      if (a[i] != a[j]) {
	printf("%" PRIi32 " %" PRIi32 "\n", i, j);
      }
    }
  }
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &n);
   ^