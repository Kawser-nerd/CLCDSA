# include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	char z;
	z = getchar();
	char c;
	c = getchar();
	char x;
	x = getchar();
	scanf("%d", &b);
	int e, f;
	if (c==43)
	{
		e = a + b;
		printf("%d\n", e);
	}
	if (c==45)
	{
		f = a - b;
		printf("%d\n", f);
	}
	system("pause");
}