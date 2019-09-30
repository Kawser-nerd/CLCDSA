#include <stdio.h>

int main(int argc, char **argv)
{
	unsigned int nc, cn;
	scanf("%u", &nc);
	
	for (cn = 0; cn != nc; cn++)
	{
		unsigned int n, k, i, j, a, b, u, nwp[10001] = {}, nl = 0;
		unsigned long long int success = 1000000000ULL, equalise;
		scanf("%u%u%u%*c%u", &n, &k, &a, &b);
		u = a * 10000 + b;
#ifdef TESTING
		printf("It's %u\n", a * 10000 + b);
#endif
		if (k != n)
		{
			fputs("This program was not designed for this", stderr);
		}
		for (i = 0; i != n; i++)
		{
			scanf("%u%*c%u", &a, &b);
#ifdef TESTING
			printf("It's %u\n", a * 10000 + b);
			fflush(stdout);
#endif
			nwp[a * 10000 + b]++;
		}
		
		for (i = 0; i != 10000; i++)
		{
			if (u <= nl)
			{
				break; /* ** */
			}
			u -= nl;
			nl += nwp[i];
		}
		if (nl == 0)
		{
			goto ne;
		}
		equalise = (i - 1) * 100000ULL + u * 100000ULL / nl;
		for (j = nl; j--; )
		{
			success *= equalise;
			success /= 1000000000ULL;
		}
		ne:
		for (; i <= 10000; i++)
		{
			while (nwp[i]--)
			{
				success *= i;
				success /= 10000ULL;
			}
		}
		
		printf("Case #%u: ", cn + 1);
		if (success == 1000000000ULL)
		{
			puts("1.000000000");
		}
		else
		{
			printf("0.%09llu\n", success);
		}
		fflush(stdout);
	}
	
	return 0;
}
