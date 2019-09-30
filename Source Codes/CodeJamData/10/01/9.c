#include <stdio.h>

int main(int argc, const char *argv[])
{
	int t;
	scanf("%d", &t);
	int i;
	long n, k;
	for(i = 0; i < t; ++i)
	{
		scanf("%ld%ld", &n, &k);
		/* now let's find it out */
		long mask = 1 << n;
		mask--;
		if(((k + 1) & mask) == 0)
		{
			printf("Case #%d: ON\n", i + 1);
		}
		else
		{
			printf("Case #%d: OFF\n", i + 1);
		}
	}
	return 0;
}
