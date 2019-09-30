#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

double calc (i32 *t, i32 *v, i32 n) {
  if (n == 1) {
    double m = t[0] * 0.5;
    if (m <= v[0]) {
      return m * m;
    } else {
      return v[0] * v[0] + v[0] * (t[0] - 2 * v[0]);
    }
  }
  if (t[0] == 0 || v[0] == 0) return calc (t + 1, v + 1, n - 1);
  if (t[n - 1] == 0 || v[n - 1] == 0) return calc (t, v, n - 1);
  for (i32 i = 0; i < n; ++i) {
    if (v[i] == 0) {
      return calc (t, v, i) + calc (t + i + 1, v + i + 1, n - i - 1);
    }
  }
  double sum = 0;
  for (i32 i = 0; i < n; ++i) {
    sum += t[i];
    v[i]--;
  }
  t[0]--;
  t[n - 1]--;
  return sum - 1 + calc (t, v, n);
}

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  i32 *t = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, t + i);
  }
  i32 *v = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, v + i);
  }
  double ans = calc (t, v, n);
  printf ("%.7f\n", ans);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &n);
   ^
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, t + i);
     ^
./Main.c:43:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32, v + i);
     ^