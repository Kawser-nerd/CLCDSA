#include <stdio.h>

int abs(int a)
{
	return (a < 0) ? -a : a;
}

int main()
{
	int t;
	int i, j;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", i + 1);
		for(j = 0; j < abs(x); j++) printf("%s", (x < 0) ? "EW" : "WE");
		for(j = 0; j < abs(y); j++) printf("%s", (y < 0) ? "NS" : "SN");
		printf("\n");
	}
	return 0;
}
