#include <stdio.h>

int a, b;
double p[1048576];

int main()
{
	int ntest, itest;
	FILE *fin = fopen("A-large.in", "r");
	FILE *fout = fopen("A-large.out", "w");
	fscanf(fin, "%d", &ntest);
	for ( itest = 0; ++itest <= ntest; )
	{
		int i;
		double p_t, best;
		int k_t, k_w;
		fscanf(fin, "%d%d", &a, &b);
		for ( i = 0; i < a; ++i )
			fscanf(fin, "%lf", p+i);
		best = b + 2;
		for ( p_t = 1, i = 0, k_w = (k_t = b + a + 1) + b + 1; i <= a; ++i, k_t -= 2, k_w -= 2 )
		{
			double x = p_t * k_t + (1 - p_t) * k_w;
			if ( x < best )
				best = x;
			if ( i < a )
				p_t *= p[i];
		}
		fprintf(fout, "Case #%d: %.6f\n", itest, best);
	}
	return 0;
}
