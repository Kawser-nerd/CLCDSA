#include <stdio.h>

int main(void)
{
	int t, ti, n, k, m;
	scanf("%d", &t);
	for (ti = 1; ti <= t; ti++) {
		scanf("%d %d", &n, &k);
		m = (1 << n) - 1;
		printf("Case #%d: %s\n", ti, ((k&m) == m) ? "ON" : "OFF");
	}
	return 0;
}
