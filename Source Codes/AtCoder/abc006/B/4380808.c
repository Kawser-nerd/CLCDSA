#include <stdio.h>

#define n_MAX   1e+06
#define DIVISOR 10007

unsigned calc_mod_tribonacci( unsigned term )
{
	unsigned buffer[(unsigned)n_MAX];
	unsigned itr;

	// set the initial values of the tribonacci sequence
	buffer[0] = (unsigned)0;
	buffer[1] = (unsigned)0;
	buffer[2] = (unsigned)1;

	// STEP.01
	// if the target term is one of the initial values
	if( term >= 3 ){
		for(itr=3; itr<term; itr++)
		{
			buffer[itr] = buffer[itr-1]%DIVISOR + buffer[itr-2]%DIVISOR + buffer[itr-3]%DIVISOR;
		}
	}

	// STEP.END
	return buffer[term-1]%DIVISOR;
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
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf( "%d", &n );
  ^