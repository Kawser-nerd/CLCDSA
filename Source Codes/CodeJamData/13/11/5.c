#include <stdio.h>

unsigned __int64 GetMax(void);
int InRange(unsigned __int64 n);
unsigned __int64 r, t;

int main()
{
	int cn, cc;
	freopen("l.in", "r", stdin);
	freopen("l.out", "w", stdout);

	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		scanf("%I64u %I64u", &r, &t);
		printf("Case #%d: %I64u\n", cc, GetMax());
	}

	return 0;
}

unsigned __int64 GetMax()
{
	unsigned __int64 n = 0, tmp = 1;
	int i;

	for (i=0; i<60; i++)
		tmp *= 2;

	for (; tmp; tmp /= 2)
	{
		if (InRange( n + tmp))
			n += tmp;
	}

	return n;
}

int InRange(unsigned __int64 n)
{
	unsigned __int64 a, b, c;
	a = n * n;
	if (a / n != n)
		return 0;
	b = n * (2 * r - 1);
	if (b / n != (2 * r - 1))
		return 0;
	a *= 2;
	if (a / 2 != n * n)
		return 0;
	c = a + b;
	if (c - a != b)
		return 0;

	if (c <= t)
		return 1;
	else
		return 0;	
}