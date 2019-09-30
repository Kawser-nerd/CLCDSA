#include <stdio.h>
#include<stdlib.h>
int main()
{
	int x,y,z;
	scanf("%d%d", &x, &y);
	z = x + y;
	if (z>=10)
	{
		printf("error\n");
	}
	else
	{
		printf("%d\n",z);
	}
	system("pause");
}