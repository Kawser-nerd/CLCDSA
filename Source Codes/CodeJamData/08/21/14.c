#include <stdio.h>

#define	NMAX	100001


long long x[NMAX], y[NMAX];
int n;
long long a, b, c, d, x0, y00, m, sol;

void reset()
{
    sol = 0;
}

void generate()
{
    int i;
    long long xt, yt;

    xt = x0;
    yt = y00;
    x[0] = xt;
    y[0] = yt;
    for (i = 1; i < n; i++) {
	xt = (a * xt + b) % m;
	yt = (c * yt + d) % m;
	x[i] = xt;
	y[i] = yt;
    }
    /*
    for (i = 0; i < n; i++)
	printf("%lld ", x[i]);
    printf("\n");
    for (i = 0; i < n; i++)
	printf("%lld ", y[i]);
    printf("\n");
    */
}


int main(int argc, char **argv)
{
    int tc, ti;
    int i, j, k;
    
    scanf("%d", &tc);
    for (ti = 0; ti < tc; ti++) {
	reset();
	scanf("%d%lld%lld%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d, &x0, &y00, &m);
	generate();
	
	for (i = 0; i < n; i++)
	    for (j = i + 1; j < n; j++)
		for (k = j + 1; k < n; k++)
		    if (!((x[i] + x[j] + x[k]) % 3) && !((y[i] + y[j] + y[k]) % 3))
			sol++;
	
	printf("Case #%d: %lld\n", ti + 1, sol);
    }

    return 0;
}
