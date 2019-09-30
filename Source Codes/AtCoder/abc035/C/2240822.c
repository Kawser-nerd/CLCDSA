#include <stdio.h>
int main() {
	int n, q, l, r;
	int a[200010] = {};
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &l, &r);
		a[--l]++; a[r]--;
	}
	printf("%d", a[0]%2);
	for (int i = 1; i < n; i++)
	{
		a[i] += a[i - 1];
		printf("%d", a[i]%2);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &q);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &l, &r);
   ^