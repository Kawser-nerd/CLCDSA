#include<stdio.h>
int main()
{
	int n, k, p;
	int i, j;
	scanf("%d%d", &k, &n);
	if (n%k == 0)
		printf("%d", n / k);
	else
	{
		for (i = n / k; i >= 2; i--)
		{
			if (n%i == 0)
				break;
		}
		printf("%d", i);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &k, &n);
  ^