#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, i, j;
	long long int sum = 0, max = -1000000000;
	scanf("%d", &n);
	int(*f)[10] = (int(*)[10])malloc(sizeof(int)*n * 10);
	int(*p)[11] = (int(*)[11])malloc(sizeof(int)*n * 11);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 10; j++)
		{
			scanf("%d", &f[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 11; j++)
		{
			scanf("%d", &p[i][j]);
		}
	}
	int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
	int time;
	for (c1 = 0; c1 < 2; c1++)
	for (c2 = 0; c2 < 2; c2++)
	for (c3 = 0; c3 < 2; c3++)
	for (c4 = 0; c4 < 2; c4++)
	for (c5 = 0; c5 < 2; c5++)
	for (c6 = 0; c6 < 2; c6++)
	for (c7 = 0; c7 < 2; c7++)
	for (c8 = 0; c8 < 2; c8++)
	for (c9 = 0; c9 < 2; c9++)
	for (c10 = 0; c10 < 2; c10++)
	{
		sum = 0;
		time = c1 + c2 + c3 + c4 + c5 + c6 + c7 + c8 + c9 + c10;
		if (time == 0) continue;
		else
		{
			for (i = 0; i < n; i++)
				{
					sum += p[i][c1*f[i][0] + c2 * f[i][1] + c3 * f[i][2] + c4 * f[i][3] + c5 * f[i][4] + c6 * f[i][5] + c7 * f[i][6] + c8 * f[i][7] + c9 * f[i][8] + c10 * f[i][9]];
				}
			if (sum > max) max = sum;
		}

	}
	printf("%lld", max);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:14:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &f[i][j]);
    ^
./Main.c:21:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &p[i][j]);
    ^