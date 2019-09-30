#include <stdio.h>
int ti, tn;
long long n, pd, pg;
long long gcd(long long x, long long y)
{
	long long t;
	while (t = x % y) {
		x = y;
		y = t;
	}
	return y;
}
int main()
{
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		printf("Case #%d: ", ti);
		scanf("%lld%lld%lld", &n, &pd, &pg);
		if (n >= 100 / gcd(pd, 100) && !(pd != 100 && pg == 100) && !(pd && !pg))
			printf("Possible\n");
		else
			printf("Broken\n");
	}
	return 0;
}
