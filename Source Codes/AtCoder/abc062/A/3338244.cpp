#include <stdio.h>
#include<stdlib.h>
int main()
{
	int x,y;
	scanf("%d%d", &x, &y);
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (days[x - 1] == days[y - 1])
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	system("pause");
}