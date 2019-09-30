#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long fac[100];

int match(long long n)
{
	for (int i = 0; i < 60; i++)
	{
		if (n == fac[i]) return 1;
	}
	return 0;
}


long long t(long long a, long long b) 
{
	if (a == 0 || b == 0) 
	{
		return -1;
	}
	while (a > 0 && b > 0) {

		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	if (a == 0)
		return b;
	else
		return a;
}

int main()
{
	fac[0] = 1;
	for (int i = 1; i < 60; i++)
		fac[i] = fac[i - 1] * 2;
	int n,count;
	long long p, q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		count = 0;
		scanf("%lld/%lld", &p, &q);
		long long f = t(p, q);
		p /= f; q /= f;
		if (!match(q)) printf("Case #%d: impossible\n", i + 1);
		else
		{
			while (1)
			{
				if (q <= p) break;
				count++;
				q /= 2;
			}
			printf("Case #%d: %d\n", i + 1, count);
		}
	}
}