#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  i32 ans[101];
  if (n & 1) {
    ans[n] = 0;
    for (i32 i = 1; i < n - i; ++i) {
      ans[i] = ans[n - i] = i;
    }
  } else {
    for (i32 i = 1; i < n + 1 - i; ++i) {
      ans[i] = ans[n + 1 - i] = i;
    }
  }
  i32 cnt = 0;
  for (i32 i = 1; i <= n; ++i) {
    for (i32 j = i + 1; j <= n; ++j) {
      if (ans[i] != ans[j]) {
	cnt++;
      }
    }
  }
  printf("%" PRIi32 "\n", cnt);
  for (i32 i = 1; i <= n; ++i) {
    for (i32 j = i + 1; j <= n; ++j) {
      if (ans[i] != ans[j]) {
	printf("%" PRIi32 " %" PRIi32 "\n", i, j);
      }
    }
  }
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &n);
   ^