#include<stdio.h>
#include<stdlib.h>
int a[101][101];
int main()
{
	int n,h,w;
	scanf("%d%d%d", &h, &w, &n);
	int *b = NULL;
	b = (int *)malloc(sizeof(int)*n);
	int i,j;
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);
	int k = 1,m=1;
	for (i = 0; i < h; i++)
	{
		if (i%2==0)
		{
			for (j = 0; j < w; j++)
			{
				if (m <= b[k-1])
				{
					a[i][j] = k;
					m++;
					 
				}
				else
				{
					m = 1;
					k++;
					j--;
				}
			}
	   }
		else
		{
			for (j = 0; j <w; j++)
			{
				if (m <= b[k - 1])
				{
					a[i][w-j-1] = k;
					m++;
					 
				}
				else
				{
					m = 1;
					k++;
					j--;
				}
			}
		}
		 
	}
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		printf("%d ", a[i][j]);
			printf("\n");
	 }
	free(b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &h, &w, &n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &b[i]);
   ^