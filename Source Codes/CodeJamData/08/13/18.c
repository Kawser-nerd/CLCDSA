#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <mpfr.h>

int
read_int(void)
{
	char s[1000];
	if (!fgets(s, 1000, stdin)) {
		perror("fgets");
		exit(-1);
	}
	return atoi(s);
}

int main(void)
{
	#if 0
	long double x;
	long double t = 3.0+sqrt(5.0);
#endif
	mpfr_t x;
	mpfr_t t3,t5,t1000,t0;
	mpfr_init2(x, 256);
	mpfr_set_ui(x, 5,0);
	mpfr_init(t3);
	mpfr_set_ui(t3, 3,0);
	mpfr_init(t0);
	mpfr_set_ui(t0, 0,0);
	mpfr_init(t5);
	mpfr_set_ui(t5, 5,0);
	mpfr_init(t1000);
	mpfr_set_ui(t1000, 1000,0);
	mpfr_sqrt(x, t5, 0);
	mpfr_add(x, x, t3, 0);
	mpfr_log(x, x, 0);
	int T,n;
	int i,j;
	T = read_int();
	for (i = 0; i < T; i++) {
		mpfr_t y;
		mpfr_t z;
		mpfr_t nn;
		n = read_int();
		mpfr_init2(y,1000);
		mpfr_init2(z,1000);
		mpfr_init(nn);
		mpfr_set_ui(nn, n,0);
		mpfr_mul(y, x, nn, 0);
		mpfr_exp(y,y,0);
		mpfr_trunc(y,y);
//		mpfr_out_str(stdout,10,0,t1000,0);
//		mpfr_out_str(stdout,10,0,y,0);
		mpfr_remainder(z, y, t1000, 0);
		if (mpfr_less_p(z, t0)) {
			mpfr_add(z, z, t1000, 0);
		}
//		mpfr_out_str(stdout,10,0,z,0);
		int xx = mpfr_get_ui(z, 0);
		printf("Case #%d: %03d\n",i+1, xx);
#if 0
		x = n*log(t);
		x = exp(x);
		x = fmod(x, 1000.0);
		printf("Case #%d: %f\n",
exp(n*ln(3+sqrt(5))
		x = 1.0;
		for (j = 0; j < n; j++) { 
			x *= t;
			x = fmod(x,1000.0);
		}
		x = fmod(x,1000.0);
		printf("%Lf\n",x);
#endif
	}
	return 0;
}
