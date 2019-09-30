#include <stdio.h>
#include <gmp.h>

#define MAXN 1000
#define MAXL 52

mpz_t time[MAXN];
mpz_t sub[MAXN];
mpz_t gcd;
char s[MAXN][MAXL];
int n;

int main() {
  int i, j, t;

  scanf("%d", &t);
  for (i = 1; i <= t; ++i) {
    scanf("%d", &n);
    for (j = 0; j < n; ++j) {
      scanf("%s", s[j]);
      mpz_init_set_str(time[j], s[j], 10);
    }

    mpz_init_set_si(sub[0], 0);
    for (j = n - 1; j > 0; --j) {
      mpz_sub(sub[j], time[j], time[j - 1]);
      mpz_gcd(gcd, sub[0], sub[j]);
      mpz_set(sub[0], gcd);
    }
    mpz_cdiv_r(sub[0], time[0], gcd);
    mpz_neg(gcd, sub[0]);
    printf("Case #%d: %s\n", i, mpz_get_str(s[0], 10, gcd));
  }
}
