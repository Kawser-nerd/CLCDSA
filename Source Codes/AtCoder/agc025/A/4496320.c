#include <stdio.h>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

int dsum(int a);

int main()
{
	int n;
	int i, j;
	int ans = 1 << 27;

	scanf("%d", &n);

	for (i = 1; i < n; i++) {
		j = n - i;

		ans = min(ans, dsum(i) + dsum(j));
	}

	printf("%d\n", ans);

	return 0;
}

int dsum(int a)
{
	int res = 0;

	while (a) {
		res = res + (a % 10);

		a = a / 10;
	}

	return res;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^