#include <stdio.h>
#include <stdbool.h>

int others[100];

int main()
{
	int t;
	scanf("%i", &t);
	for (int test = 1; test <= t; test++)
	{
		int n, l, h;
		bool possible = false;
		scanf("%i %i %i", &n, &l, &h);
		for (int i = 0; i < n; i++)
			scanf("%i", &others[i]);
		for (int i = l; i <= h; i++)
		{
			int count = 0;
			for (int j = 0; j < n; j++)
				if (others[j] % i == 0 || i % others[j] == 0)
					count++;
			if (count == n)
			{
				printf("Case #%i: %i\n", test, i);
				possible = true;
				break;
			}
		}
		if (!possible)
			printf("Case #%i: NO\n", test);
	}
	return 0;
}
