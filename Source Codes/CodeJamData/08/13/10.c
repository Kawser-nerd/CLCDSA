#include <stdio.h>
#include "gmp.h"

int power(int i, int n)
{
  mpf_t x;
  mpf_init2(x, 524288);
  mpf_set_str(x, "5", 10);
  mpf_sqrt(x, x);
  mpf_add_ui(x, x, 3);

  int res = 0;
  mpf_pow_ui(x, x, (unsigned long int)n);

  mpf_floor(x, x);

  mpz_t y;
  mpz_init2(y, 524288);

  mpz_set_f(y, x);
  mpz_mod_ui(y, y, 1000);

  //gmp_printf("%.4Ff\n", x);
  gmp_printf("Case #%d: %03Zd\n", i, y);
}

int main()
{
  int T;
  scanf(" %d", &T);
  int i;
  for(i = 1; i <= T; ++i)
  {
    int n;
    scanf(" %d", &n);
    power(i, n);
  }
  return 0;
}
