#include <stdio.h>

void ms(unsigned long long int *a, unsigned int n) /*descending*/
{
	if (n <= 1)
	{
		return;
	}
	ms(a, n >> 1);
	ms(a + (n >> 1), n + 1 >> 1);
	unsigned int b = 0, c = n >> 1;
	unsigned long long int t[1024 /**/], *te = t;
	while (1)
	{
		if (b == n >> 1)
		{
			while (c != n)
			{
				*te++ = a[c++];
			}
			break;
		}
		if (c == n)
		{
			while (b != n >> 1)
			{
				*te++ = a[b++];
			}
			break;
		}
		if (a[b] > a[c])
		{
			*te++ = a[b++];
		}
		else
		{
			*te++ = a[c++];
		}
	}
	for (b = 0; b != n; b++)
	{
		a[b] = t[b];
	}
}

int main(int argc, char **argv)
{
	unsigned int nc, cn;
	scanf("%u", &nc);
	
	for (cn = 0; cn != nc; cn++)
	{
		unsigned int n, k, i;
		unsigned long long int rad[1024], hei[1024], \
		 rim[1024] = {}, rs, bmr = 0, best, x, rem;
		scanf("%u%u", &n, &k);
		
		for (i = 0; i != n; i++)
		{
			scanf("%llu%llu", rad + i, hei + i);
			rim[i] = rad[i] * hei[i] << 21 | rad[i];
		}
		
#ifdef TESTING
		for (i = 0; i != n; i++)
		{
			printf("%llu,%llu ", rim[i] >> 20, rim[i] & 0xFFFFFULL);
		}
		putchar('\n');
		putchar('\n');
#endif
		ms(rim, n);
#ifdef TESTING
		for (i = 0; i != n; i++)
		{
			printf("%llu,%llu ", rim[i] >> 20, rim[i] & 0xFFFFFULL);
		}
		putchar('\n');
#endif
		rs = 0;
		for (i = 0; i != k; i++)
		{
			rs += rim[i] >> 20;
			if (bmr < (rim[i] & 0xFFFFFULL))
			{
				bmr = rim[i] & 0xFFFFFULL;
			}
		}
		best = rs + bmr * bmr;
		rs -= rim[i - 1] >> 20;
		for (; i != n; i++)
		{
			x = rim[i] & 0xFFFFFULL;
			x = (rim[i] >> 20) + rs + x * x;
			if (best < x)
			{
#ifdef TESTING
				printf("#%u beats it with %llu\n", i, x);
#endif
				best = x;
			}
		}
		
#ifdef TESTING
		printf("%llu\n", best);
#endif
		unsigned int f = 0;
		while (best > 10000000000ULL)
		{
			best /= 10;
			f++; 
		}
		best *= 314159265;
		rem = best % 100000000;
		best /= 100000000;
		while (f--)
		{
			best *= 10;
		}
		
		printf("Case #%u: %llu.%08llu\n", cn + 1, best, rem);
/*
		long double fr = (long double)best;
		fr *= 3.141592653589793238462643;
		printf("Case #%u: %.9Lf\n", cn + 1, fr);
*/
	}
	
	return 0;
}
