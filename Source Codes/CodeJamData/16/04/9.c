#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void do_test(int t)
{
	int k, c, s;
	int i;
	int extra_needed;
	long long tile;
	
	scanf("%d %d %d", &k, &c, &s);

	printf("Case #%d:", t + 1);

	if ((k + c - 1) / c > s)
	{
		printf(" IMPOSSIBLE\n");
		return;
	}

	tile = 0;
	for (i = 0; i < k; i++)
	{
		extra_needed = 1;
		tile *= k;
		tile += i;

		if ((i + 1) % c == 0)
		{
			printf(" %lld", tile + 1);
			tile = 0;
			extra_needed = 0;
		}
	}

	if (extra_needed)
		printf(" %lld", tile + 1);

	printf("\n");
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
