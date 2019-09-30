#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a, b,c;
	a=getchar();
	b=getchar();
	c=getchar();
	if (a == c)
	{
		printf("H\n");
	}
	else
	{
		printf("D\n");
	}
	system("pause");
}