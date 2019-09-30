#include <stdio.h>
#include <stdlib.h>
long gcd(long a, long b);

int main(void)
{
	long N, X, x[100000], d;
	scanf("%ld%ld", &N, &X);
	for (int i = 0; i < N; ++i)
	{
		scanf("%ld", &x[i]);
		x[i] = labs(x[i]-X);
	}
	d = x[0];
	if (N > 1)
	{
		for (int i = 1; i < N; ++i)
		{
			if (x[i] >= d)
			{
				d = gcd(x[i], d);
			}
			else
			{
				d = gcd(d, x[i]);
			}
		}
	}
	printf("%ld\n", d);
	return 0;
}

long gcd(long a, long b)
{
	long l;
	if (a == b)
	{
		return a;
	}
	else
	{
		l=(a-b)/b;
		a-=l*b;
		if (a>b) a-=b;
		b = gcd(b, a);
	}
	return b;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld", &N, &X);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &x[i]);
   ^