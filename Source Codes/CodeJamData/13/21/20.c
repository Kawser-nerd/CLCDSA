#include <stdio.h>
#include <stdlib.h>

int arr[100];
int curst;

int cmp(int *a, int *b)
{
	return (*a > *b) ? 1 : -1;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int main()
{
	int t;
	int i, j, n;
	scanf("%d\n", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d %d", &curst, &n);
		for(j = 0; j < n; j++) scanf("%d", &arr[j]);
		if(curst == 1)
		{
			printf("Case #%d: %d\n", i + 1, n);
			continue;
		}
		qsort(arr, n, sizeof(int), cmp);
		int ans = n;
		int adds = 0;
		for(j = 0; j < n; j++)
		{
			while(curst <= arr[j])
			{
				adds++;
				curst *= 2;
				curst--;
			}
			curst += arr[j];
			ans = min(ans, adds + (n - j - 1));
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
}
