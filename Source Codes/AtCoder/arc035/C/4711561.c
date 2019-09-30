#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

void run (void) {
  i32 n, m;
  scanf ("%" SCNi32 "%" SCNi32, &n, &m);
  i32 *d = (i32 *) calloc (n * n, sizeof (i32));
  for (i32 i = 0; i < n * n; ++i) {
    d[i] = i / n == i % n ? 0 : 1000 * n;
  }
  while (m--) {
    i32 a, b, c;
    scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &a, &b, &c);
    a--;
    b--;
    d[a * n + b] = d[b * n + a] = c;
  }
  for (i32 k = 0; k < n; ++k) {
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < n; ++j) {
	i32 x = d[i * n + k] + d[k * n + j];
	if (d[i * n + j] > x) {
	  d[i * n + j] = x;
	}
      }
    }
  }
  i32 k;
  scanf ("%" SCNi32, &k);
  while (k--) {
    i32 x, y, z;
    scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &x, &y, &z);
    x--;
    y--;
    if (d[x * n + y] > z) {
      for (i32 i = 0; i < n; ++i) {
	for (i32 j = 0; j < n; ++j) {
	  i32 w = d[i * n + x] + z + d[y * n + j];
	  if (d[i * n + j] > w) {
	    d[i * n + j] = w;
	  }
	  w = d[i * n + y] + z + d[x * n + j];
	  if (d[i * n + j] > w) {
	    d[i * n + j] = w;
	  }
	}
      }
    }
    i64 sum = 0;
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = i + 1; j < n; ++j) {
	sum += d[i * n + j];
      }
    }
    printf ("%" PRIi64 "\n", sum);
  }
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &n, &m);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &a, &b, &c);
     ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &k);
   ^
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32, &x, &y, &z);
     ^