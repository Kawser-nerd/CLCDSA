#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

void run (void) {
  i32 n;
  scanf("%" SCNi32, &n);
  i32 *a = (i32 *) calloc (n + 1, sizeof (i32));
  i32 i,j;
  for (i = 1; i <= n; ++i) {
    scanf("%" SCNi32, a + i);
  }
  i32 ans[100];
  for(i = 0; i < n; ++i) {
    for (j = n - i; j >= 1; --j) {
      if (a[j] == j) {
	ans[i] = j;
	break;
      }
    }
    if (j < 1) {
      puts ("-1");
      return;
    }
    for (; j + 1 <= n - i; ++j) {
      a[j] = a[j + 1];
    }
  }
  for (i = n - 1; i >= 0; --i) {
    printf("%" PRIi32 "\n", ans[i]);
  }
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%" SCNi32, &n);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%" SCNi32, a + i);
     ^