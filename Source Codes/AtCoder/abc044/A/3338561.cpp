#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, k, x, y,z;
	    scanf("%d", &n);
		scanf("%d", &k);
		scanf("%d", &x);
		scanf("%d", &y);
			if (n > k)
		{
			z = x * k + y * (n - k);
			printf("%d\n", z);
		}
		else
		{
			z = n * x;
			printf("%d\n", z);
		}
	system("pause");
}