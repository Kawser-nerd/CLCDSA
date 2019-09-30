#include <gmp.h>
#include <stdio.h>

int main(void)
{
	int tn, ti;
	mpz_t t, t0, g, r;
	mpz_init(g);
	mpz_init(t);
	mpz_init(t0);
	mpz_init(r);
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ti++) {
		int n, i;
		scanf("%d", &n);
		if (n < 2) {
			mpz_set_ui(r, 0);
		} else {
			gmp_scanf("%Zd %Zd", t0, r);
			mpz_sub(g, r, t0);
			for (i = 2; i < n; i++) {
				gmp_scanf("%Zd", r);
				mpz_sub(t, r, t0);
				mpz_gcd(r, g, t);
				mpz_set(g, r);
			}
			if (mpz_sgn(g) < 0) {
				mpz_neg(r, g);
				mpz_set(g, r);
			}
			while (mpz_sgn(t0) < 0) {
				mpz_add(r, t0, g);
				mpz_set(t0, r);
			}
			mpz_mod(t, t0, g);
			if (mpz_sgn(t) == 0) mpz_set_ui(r, 0);
			else mpz_sub(r, g, t);
		}
		gmp_printf("Case #%d: %Zd\n", ti, r);
	}
	mpz_clear(g);
	mpz_clear(t);
	mpz_clear(t0);
	mpz_clear(r);
	return 0;
}
