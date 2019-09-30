#include <stdio.h>
#include <stdlib.h>

int comp(const void *left, const void *right){
	int l = *(int*)left;
	int r = *(int*)right;

	if (l < r) return -1;
	if (l > r) return +1;
	return 0;
}

int main(void){
	int n, i;
	int ans[3] = {0}, x[3];
	int res = 0;
	scanf("%d", &n);
	while (n--) {
		for (i = 0; i < 3; i++) scanf("%d", &x[i]);
		qsort(x, 3, sizeof(int), comp);
		for (i = 0; i < 3; i++) if (x[i] > ans[i]) ans[i] = x[i];
	}

	res = 1;
	for (i = 0; i < 3; i++) res *= ans[i];

	printf("%d\n", res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:19:27: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for (i = 0; i < 3; i++) scanf("%d", &x[i]);
                           ^