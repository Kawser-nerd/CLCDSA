#include <stdio.h>
#include <stdlib.h>
int bw(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}
int main() {
	int a[100010] = {}, b[100010] = {}, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	qsort(a, n, sizeof(int), bw);
	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; a[i] != b[j]; j++) {}
		printf("%d\n", j + 1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^