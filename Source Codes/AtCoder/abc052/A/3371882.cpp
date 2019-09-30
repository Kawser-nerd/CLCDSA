#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b,c,d, q, w;
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%d",&d);
	q = a * b, w = c * d;
	if (q > w)
	{
		printf("%d", q);
	}
	else printf("%d", w);
	system("pause");
	return 0;
}