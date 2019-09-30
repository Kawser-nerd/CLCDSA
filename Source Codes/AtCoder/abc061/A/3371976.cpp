#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
if (a <=c)
	{
		if (c <=b)
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