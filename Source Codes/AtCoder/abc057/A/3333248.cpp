#include <stdio.h>
#include <stdlib.h>
int main()
{
	int A, B,c,d,e;
	scanf("%d%d", &A, &B);
	c = A + B;
	d = c - 24;
	e = 0;
	if (c <24)
	{
		printf("%d\n", c);
	}
	else
	{
		if (c == 48)
		{
			printf("%d\n",e);
		}
		else printf("%d\n", d);
	}
	system("pause");
}