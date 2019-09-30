#include<stdio.h>

int flag[1000];
int a[1000], b[1000];

void sort(int l, int r, int *a, int *b)
{
	int i = l, j = r;
	int x = a[(l + r) / 2];
	int t;
	while (i <= j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			t = b[i];
			b[i] = b[j];
			b[j] = t;
			i++;
			j--;
		}
	}
	if (l < j)
		sort(l, j, a, b);
	if (i < r)
		sort(i, r, a, b);
}

int findCircle(int i)
{
	if (flag[i])
		return 0;
	flag[i] = 1;
	return findCircle(b[i])+1;
}

int main()
{
	freopen("gcj4.in", "r", stdin);
	freopen("gcj4.out", "w", stdout);
	int ca, count;
	scanf("%d", &ca);
	for (count = 1; count <= ca; count++)
	{
		int n, i;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", a + i);
			b[i] = i;
		}
		sort(0, n - 1, a, b);
		for (i = 0; i < n; i++)
			flag[i] = 0;
		double ans = 0;
		for (i = 0; i < n; i++)
			if (!flag[i])
			{
				int size=findCircle(i);
				if (size>1)
					ans+=size;
			}
		printf("Case #%d: %f\n", count, ans);
	}
	return 0;
}
