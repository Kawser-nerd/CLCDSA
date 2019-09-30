#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
	scanf("%d", &a);
	if (a<=15)
	{
		int b;
		b = a * 800;
		printf("%d", b);
	}
	if (a > 15)
	{
		int c;
		c = a * 800 - 200 * (a / 15);
		printf("%d", c);
	}
	system("pause");
	return 0;
}