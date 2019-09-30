#include <stdio.h>
int arr[105];

int check(int a, int n)
{
	int i;
	int f;
	for(i = 0;i < n;i++)
	{
		f = 0;
		if (a < arr[i] && arr[i] % a == 0)
			f = 1;
		if (a >= arr[i] && a % arr[i] == 0)
			f = 1;
		if (!f)
			return 0;
	}
	return 1;
}

int main()
{
	int ncase;
	int icase;
	int l, h, n;
	int i;

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d %d %d", &n, &l, &h);

		for(i = 0;i < n;i++)
			scanf("%d", &arr[i]);

		for(i = l;i <= h;i++)
			if (check(i, n))
				break;
		if (i <= h)
			printf("Case #%d: %d\n", icase, i);
		else
			printf("Case #%d: NO\n", icase);
	}
	return 0;
}
