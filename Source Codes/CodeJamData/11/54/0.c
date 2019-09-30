#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 65

int main ()
{
	int T, iT;
	scanf("%d\n",&T);
	static char a[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		scanf("%s\n",a);
		int N = strlen(a);
		while (a[N-1] < 32) N--;
		int i;
		int q = 0;
		for (i = 0; i < N; i++)
		{
			if (a[i] == '?') q++;
		}
		int total = 1 << q;
		int j, k;
		long long int num;
		long long int l, r, c;
		for (j = 0; j < total; j++)
		{
			num = 0LL;
			k = j;
			for (i = 0; i < N; i++)
			{
				num = num * 2LL;
				if (a[i] == '1') num++;
				else if (a[i] == '?')
				{
					if (k % 2) num++;
					k /= 2;
				}
			}
			l = 0LL;
			r = 2000000000LL;
			while (r > l)
			{
				c = (l + r) / 2LL;
				if ((c * c) >= num) r = c;
				else l = c+1;
			}
			if ((l * l) == num)
			{
				printf("Case #%d: ",iT+1);
				k = j;
				for (i = 0; i < N; i++)
				{
					if (a[i] == '0') printf("0");
					else if (a[i] == '1') printf("1");
					else
					{
						printf("%d",k % 2);
						k /= 2;
					}
				}
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
