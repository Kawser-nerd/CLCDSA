#include <stdio.h>
int tn, ti, n, k;
int main()
{
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		printf("Case #%d: ", ti);
		scanf("%d%d", &n, &k);
		if ((k&((1 << n) - 1)) == (1 << n) - 1)
			printf("ON\n");
		else
			printf("OFF\n");
	}
	return 0;
}
