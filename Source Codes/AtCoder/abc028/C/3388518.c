#include <stdio.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
	return *(int*)y - *(int*)x;
}

int main(void)
{
	int ans[10], tmp[5], i, j, k, l = 0;
	for (i = 0; i < 5; ++i) scanf("%d", &tmp[i]);
	for (i = 0; i < 3; ++i) {
		for (j = i + 1; j < 4; ++j) {
			for (k = j + 1; k < 5; ++k) {
				ans[l] = tmp[i] + tmp[j] + tmp[k];
				++l;
			}
		}
	}
	qsort(ans, 10, sizeof(int), compare);
	printf("%d\n", ans[2]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 0; i < 5; ++i) scanf("%d", &tmp[i]);
                          ^