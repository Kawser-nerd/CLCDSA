#include <stdio.h>

/* From the GNU Multiple Precision Arithmetic Library */
/* http://gmplib.org/ */
#include <gmp.h>

void doit (unsigned i) {
	unsigned n, j;
	mpz_t times[1000];
	mpz_t gcd, min, diff, y;

	/* Initialize stuff */
	mpz_init (gcd);
	mpz_init (min);
	mpz_init (diff);
	mpz_init (y);

	/* initialize and input stuff */
	scanf("%u ", &n);
	for (j = 0; j < n; j++) {
		mpz_init (times[j]);
		gmp_scanf ("%Zu ", times[j]);
	}

	/* Compute minimum (time since last event) */
	mpz_set (min, times[0]);
	for (j = 1; j < n; j++) {
		if (mpz_cmp (min, times[j]) > 0) {
			mpz_set (min, times[j]);
		}
	}
	
	/* Shift times (set now to last event) */
	for (j = 0; j < n; j++) {
		mpz_sub (times[j], times[j], min);
	}

	/* Compute time unit so that all are integer multiples */
	mpz_set (gcd, times[0]);
	for (j = 1; j < n; j++) {
		mpz_gcd (gcd, gcd, times[j]);
	}

	/* Compute y such that we are an integer multiple of unit after last event */
	mpz_mod (y, min, gcd);
	if (mpz_cmp_ui (y, 0)) {
		mpz_sub (y, gcd, y);
	}

	/* Output */
	gmp_printf ("Case #%u: %Zu\n", i, y);

	/* Clear */
	mpz_clear (gcd);
	mpz_clear (min);
	mpz_clear (diff);
	mpz_clear (y);	
	for (j = 0; j < n; j++) {
		mpz_clear (times[j]);
	}
}

int main () {
	unsigned c, i;

	scanf ("%u ", &c);
	for (i = 1; i <= c; i++) {
		doit (i);
	}

	return 0;
}
