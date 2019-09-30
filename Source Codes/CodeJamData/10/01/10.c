#include <stdio.h>

int get_light(int n, int k)
{
	return (k & ((1 << n) - 1)) + 1 == (1 << n);
}

int main(void)
{
	int T, N, K;
	int i;

	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d%d", &N, &K);
		printf("Case #%d: %s\n", i + 1, get_light(N, K) ? "ON" : "OFF");
	}

	return 0;
}
