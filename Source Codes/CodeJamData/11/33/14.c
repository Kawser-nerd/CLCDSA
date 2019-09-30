#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

int main()
{
	int t, t_case;
	scanf("%d", &t_case);
	for (t = 1; t <= t_case; t++)
	{
		int n, l, h;
		scanf("%d %d %d\n", &n, &l, &h);
		int i;
		int a[MAX_N];
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		int check;
		for (i = l; i <= h; i++)
		{
			int j;
			check = 1;
			for (j = 0; j < n; j++)
				if (a[j] % i != 0 && i % a[j] != 0)
				{
					check = 0;
					break;
				}
			if (check)
				break;
		}
		
		if (check)
			printf("Case #%d: %d\n", t, i);
		else
			printf("Case #%d: NO\n", t);	
	}
	return 0;
}
