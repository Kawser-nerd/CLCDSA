#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

const i32 mod = 1000000007;

i32 *fact = NULL;
i32 *iFact = NULL;
void init (const i32 n) {
  fact = (i32 *) calloc (n + 1, sizeof (i32));
  fact[0] = 1;
  for (i32 i = 1; i <= n; ++i) {
    fact[i] = (i64) i * fact[i - 1] % mod;
  }
  i32 t = 1;
  i32 a = fact[n];
  while (a > 1) {
    t = (i64) t * (mod - mod / a) % mod;
    a = mod % a;
  }
  iFact = (i32 *) calloc (n + 1, sizeof (i32));
  iFact[n] = t;
  for (i32 i = n - 1; i >= 0; --i) {
    iFact[i] = (i64) (i + 1) * iFact[i + 1] % mod;
  }
}

i32 comb (i32 n, i32 k) {
  if (!(0 <= k && k <= n)) return 0;
  return (i64) fact[n] * iFact[k] % mod * iFact[n - k] % mod;
}

void run (void) {
  i32 n, a, b, c, d;
  scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32 "%" SCNi32 "%" SCNi32, &n, &a, &b, &c, &d);
  init (n);
  i32 *dp = (i32 *) calloc (n + 1, sizeof (i32));
  i32 *pow = (i32 *) calloc (n + 1, sizeof (i32));
  dp[0] = 1;
  for (i32 i = a; i <= b; ++i) {
    pow[0] = 1;
    for (i32 j = 1; j <= n; ++j) {
      pow[j] = (i64) iFact[i] * pow[j - 1] % mod;
    }
    for (i32 j = n; j >= 1; --j) {
      i32 local = dp[j];
      for (i32 k = c; k <= d && k * i <= j; ++k) {
	i32 way = (i64) comb (j, k * i) * fact[k * i] % mod * pow[k] % mod * iFact[k] % mod;
	local = (local + (i64) way * dp[j - k * i]) % mod;
      }
      dp[j] = local;
    }
  }
  printf ("%" PRIi32 "\n", dp[n]);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32 "%" SCNi32 "%" SCNi32 "%" SCNi32 "%" SCNi32, &n, &a, &b, &c, &d);
   ^