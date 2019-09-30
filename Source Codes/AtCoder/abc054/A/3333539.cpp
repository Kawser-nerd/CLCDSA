# include<stdio.h>
#include <stdlib.h>
int main()
{
	int A, B;
	scanf("%d%d", &A,&B);
	if (A>1&&B>1)
	{
		if (A == B)
		{
			printf("Draw\n");
		}
		if (A > B)
		{
			printf("Alice\n");
		}
		if (A < B)
		{
			printf("Bob\n");
		}
	}
	else
	{
		if (A == B)
		{
			printf("Draw\n");
		}
		if (A > B)
		{
			printf("Bob\n");
		}
		if (A < B)
		{
			printf("Alice\n");
		}
	}
	system("pause");
}