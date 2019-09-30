#include<stdio.h>
#include<gmp.h>

/*
 * u gotta edit output by hand to pad with zeroes
 */

typedef unsigned nat;

#define PREC 120000

int main() {
	nat tc, cs;
	nat n;
	nat i;
	mpf_t base, x;
	mpz_t result;

	mpf_init2(base, PREC);
	mpf_init2(x, PREC);
	mpz_init(result);

	mpf_set_ui(base, 5);
	mpf_sqrt(base, base);
	mpf_add_ui(base, base, 3);

	scanf("%u", &tc);
	for (cs = 0; cs != tc; ++cs) {
		scanf("%u", &n);

		mpf_set_ui(x, 1);
		for (i = 0; i != n; ++i)
			mpf_mul(x, x, base);
		mpz_set_f(result, x);
		mpz_mod_ui(result, result, 1000);
		
		printf("Case #%u: ", cs+1);
		mpz_out_str(stdout, 10, result);
		putchar('\n');
	}

	return 0;
}




