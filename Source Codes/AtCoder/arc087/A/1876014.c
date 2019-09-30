#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int compar(const void* pa, const void* pb)
{
	const int *a = pa;
	const int *b = pb;

	return *a - *b;
}
int main(void)
{
	int n;
	int a[100001];
	int i;
	int before = 0;
	int sum = 0, count = 0;

	scanf("%d", &n);

	for (i = 0; i < n; ++i){
		scanf("%d", a + i);
	}
	a[n] = INT_MAX;
	qsort(a, n, sizeof(int), compar);
	for (i = 0; i <= n; ++i){
		if (before < a[i]){
			sum += count < before ? count : (count - before);
			count = 0;
		}
		++count;
		before = a[i];
	}
	printf("%d\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", a + i);
   ^