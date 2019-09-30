#include <stdio.h>
#include <string.h>

#define MAX 40

int a[MAX];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++)
	{
		int n;
		scanf("%d ", &n);
		for (int i=0; i<n; i++)
		{
			char buf[MAX+1];
			scanf("%s", buf);
			a[i] = 0;
			for (int j=0; j<n; j++) if (buf[j] == '1') a[i] = j;
		}
		int s = 0;
		for (int i=0; i<n; i++)
		{
			int j;
			for (j=i; j<n; j++)
				if (a[j] <= i)
					break;
			for (; j>i; j--)
			{
				a[j] = a[j-1];
				s++;
			}
		}
		printf("Case #%d: %d\n", t, s);
	}
	return 0;
}
