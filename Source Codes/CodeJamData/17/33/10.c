#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>
#define NMAX 50

int cmp(const void *a, const void *b)
{
	double *da = (double*)a;
	double *db = (double*)b;
	
	if(*da == *db) return 0;
	return *da > *db ? -1 : 1;
}

double solve(double *core, size_t N, size_t K, double U)
{
	double sum;
	double new;
	double ret;
	size_t i;
	
	qsort(core, N, sizeof(double), cmp);
	
	sum = U;
	for(i = 0; i < K; i++)
		sum += core[i];
	
	for(i = 0; i < K; i++) {
		new = sum / (K - i);
		if(core[i] > new)
			new = core[i];
		
		core[i] = new;
		sum    -= new;
	}
	
	ret = core[0];
	for(i = 1; i < K; i++)
		ret *= core[i];

	return ret;
}

int main(int argc, char *argv[])
{
	size_t T, i;
	size_t N, K, j;
	double U;
	double core[NMAX];
	double answer;
	
	scanf("%llu", &T);
	for(i = 0; i < T; i++) {
		scanf("%llu %llu", &N, &K);
		
		scanf("%lf", &U);
		for(j = 0; j < N; j++)
			scanf("%lf", &core[j]);

		answer = solve(core, N, K, U);
		printf("Case #%u: %.6f\n", i + 1, answer);
	}
}