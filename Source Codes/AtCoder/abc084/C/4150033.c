#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d", &n);
	int(*a)[3] = (int(*)[3])malloc(sizeof(int)*(n+1) * 3);
	int *b = (int *)malloc(sizeof(int)*(n+1));
	int i, j;
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
			b[i] = a[i][1];
		}
	}
	for (i = 0; i < n-1; i++)
	{
		for (j = i; j < n-1; j++)
		{
			while (!(b[i] % a[j][2] == 0) || b[i] < a[j][1])
			{
				b[i]++;
			}
			b[i] += a[j][0];
		}
	}
	for (i = 0; i < n-1; i++)
		printf("%d\n", b[i]);
	printf("0\n");
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:14:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &a[i][j]);
    ^