#include <stdio.h>

#define DIVISOR 10007

unsigned calc_mod_tribonacci( unsigned term )
{
	unsigned tribonacci_1st, tribonacci_2nd, tribonacci_3rd, tribonacci_buf;
	unsigned itr;

	// set the initial values of the tribonacci sequence
	tribonacci_1st = (unsigned)0;
	tribonacci_2nd = (unsigned)0;
	tribonacci_3rd = (unsigned)1;

	// STEP.01
	// calculate the value of `term`-th term of the tribonacci sequence
	switch ( term )
	{
		// STEP.01.01
		// if the target term was the one of the initial value
		case (unsigned)1: tribonacci_buf = tribonacci_1st; break;
		case (unsigned)2: tribonacci_buf = tribonacci_2nd; break;
		case (unsigned)3: tribonacci_buf = tribonacci_3rd; break;
		// STEP.01.02
		// if the target term was NOT the one of the initial value
		default:

			// initialize the iterator
			itr = (unsigned)1;

			for(itr = 4; itr <= term; itr++)
			{
				tribonacci_buf = tribonacci_1st%DIVISOR + tribonacci_2nd%DIVISOR + tribonacci_3rd%DIVISOR;
				tribonacci_1st = tribonacci_2nd;
				tribonacci_2nd = tribonacci_3rd;
				tribonacci_3rd = tribonacci_buf;
			}
			break;
	}

	// STEP.END
	return tribonacci_buf%DIVISOR;
}

int main (void)
{
	/* variables for main process */
	unsigned n;

	// STEP.01
	// read the target number
	scanf( "%d", &n );

	// STEP.02
	// output the mod
	printf( "%d\n", calc_mod_tribonacci(n) );

	// STEP.TRUE_END
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:52:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf( "%d", &n );
  ^