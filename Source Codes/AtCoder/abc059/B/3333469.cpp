# include<stdio.h>
#include <stdlib.h>
int main()
{
	long double A, B;
	int r;
	r=scanf("%Lf%Lf", &A,&B);
	if (r == 2)
	{
		if (A == B)
		{
			printf("EQUAL\n");
		}
		if (A > B)
		{
			printf("GREATER\n");
		}
		if (A < B)
		{
			printf("LESS\n");
		}
	}
	system("pause");
}