#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;

void run (void) {
  i32 n, m;
  scanf ("%" SCNi32 "%" SCNi32, &n, &m);
  i32 *c = (i32 *) calloc (m, sizeof (i32));
  i32 *cost = (i32 *) calloc (m, sizeof (i32));
  i32 **idol = (i32 **) calloc (m, sizeof (i32 *));
  i32 **p = (i32 **) calloc (m, sizeof (i32 *));
  for (i32 i = 0; i < m; ++i) {
    scanf ("%" SCNi32 "%" SCNi32, c + i, cost + i);
    idol[i] = (i32 *) calloc (c[i], sizeof (i32));
    p[i] = (i32 *) calloc (c[i], sizeof (i32));
    for (i32 j = 0; j < c[i]; ++j) {
      scanf ("%" SCNi32 "%" SCNi32, idol[i] + j, p[i] + j);
      idol[i][j]--;
    }
  }
  double *dp = (double *) calloc (1 << n, sizeof (double));
  const double f = (double) 1 / 100;
  for (i32 bit = 1; bit < (1 << n); ++bit) {
    double min = 3000 * 100 + 1;
    for (i32 i = 0; i < m; ++i) {
      i32 no = 0;
      double local = cost[i];
      for (i32 j = 0; j < c[i]; ++j) {
	i32 k = idol[i][j];
	if ((bit >> k) & 1) {
	  local += p[i][j] * f * dp[bit ^ (1 << k)];
	} else {
	  no += p[i][j];
	}
      }
      if (no == 100) continue;
      local /= f * (100 - no);
      if (min > local) {
	min = local;
      }
    }
    dp[bit] = min;
  }
  printf ("%.7f\n", dp[(1 << n) - 1]);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32, &n, &m);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi32 "%" SCNi32, c + i, cost + i);
     ^
./Main.c:20:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf ("%" SCNi32 "%" SCNi32, idol[i] + j, p[i] + j);
       ^