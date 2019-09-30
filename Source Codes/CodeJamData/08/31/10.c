#include <stdio.h>
#include <stdlib.h>

#define	LMAX	10001


long long p, k, l, n;
long long freq[LMAX];
long long fact, sol;


int lcmp(const void *a, const void *b)
{
    long long t = *(long long *)a - *(long long *)b;
    
    if (t < 0) return 1;
    if (t > 0) return -1;
    return 0;
}

void reset()
{
    fact = 0;
    sol = 0;
}


int main(int argc, char **argv)
{
    long long tc, ti;
    long long i;
    
    scanf("%lld", &tc);
    for (ti = 0; ti < tc; ti++) {
	reset();
	
	scanf("%lld%lld%lld", &p, &k, &l);
	
	for (i = 0; i < l; i++)
	    scanf("%lld", &freq[i]);
	
	if (p * k < l) {
	    printf("Case #%lld: Impossible\n", ti + 1);
	    continue;
	}
	    
	qsort(freq, l, sizeof(long long), lcmp);
	
	
	for (i = 0; i < l; i++) {
	    if (!(i % k)) fact++;
	    
	    sol += freq[i] * fact;
	}
	
	printf("Case #%lld: %lld\n", ti + 1, sol);
    }

    return 0;
}
