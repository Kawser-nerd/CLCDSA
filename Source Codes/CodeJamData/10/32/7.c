#include <stdio.h>
#include <math.h>

int main(void)
{
	int t, ti;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		int l, p, c, r;
		scanf("%d %d %d", &l, &p, &c);
		r = (int)(ceil(log(log((double)p/(double)l)/log(c))/log(2))+0.5);
		if (r < 0) r = 0;
		printf("Case #%d: %d\n", ti, r);
	}
	return 0;
}