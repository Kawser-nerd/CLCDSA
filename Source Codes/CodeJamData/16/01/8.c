#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void do_test(int t)
{
	long long n, ni, m;
	unsigned seen = 0;	

	scanf("%lld", &n);

	if (n == 0)
	{
		printf("Case #%d: INSOMNIA\n", t + 1);
		return;
	}

	ni = 0;
	while (seen != 0x3ff)
	{
		ni += n;
		for (m = ni; m; m /= 10)
			seen |= 1U << (m % 10);
	}	

	printf("Case #%d: %lld\n", t + 1, ni);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
