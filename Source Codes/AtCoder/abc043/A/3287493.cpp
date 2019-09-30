#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
   scanf("%d",& n);
    int i, N = 0;
	i = 1;
	while (i <= n)
	{
		N = N + i;
		i = i + 1;
	}
	printf("%d\n", N);
	system("pause");
}