#include<stdio.h> 
#include<math.h>

float calc(int, int *, int *);

int main()
{
	int n, a, b;
	int x[101], y[101];
	scanf("%d" ,&n);
	if (n < 2 || n > 100)
	{
		printf("invalid input");
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}	
	printf("%f", calc(n, x, y));
	return 0;
}

float calc(int m, int *px, int *py)
{
	float a = 0;
	int r[2];
	int j, k;;
	for (j = 0; j < m - 1; j++)
	{
		for(k = j + 1; k < m; k++)
		{
			if(sqrt(pow((px[j] - px[k]), 2) + pow((py[j] - py[k]), 2)) > a)
				a = sqrt(pow(px[j] - px[k], 2) + pow(py[j] - py[k], 2));
		}
	}
	return a;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d" ,&n);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &x[i], &y[i]);
   ^