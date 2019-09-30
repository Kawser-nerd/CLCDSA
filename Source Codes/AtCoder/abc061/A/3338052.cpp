#include <stdio.h>
#include<stdlib.h>
int main()
{
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	if (A <=C)
	{
		if (C <=B)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	else
	{
		printf("No\n");
	}
	system("pause");
}