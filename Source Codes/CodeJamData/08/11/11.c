#include <stdio.h>
#include <stdlib.h>

int comp1(const void *a, const void *b)
{
	return *((int *)a) - *((int *)b);
}
int comp2(const void *a, const void *b)
{
	return *((int *)b) - *((int *)a);
}

int main(int argc, char **argv)
{
	int t, i, n, j, ret;
	int v1[1000], v2[1000];

	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%d", &v1[j]);
		}
		for (j = 0; j < n; j++) {
			scanf("%d", &v2[j]);
		}
		qsort(v1, n, sizeof(int), comp1);
		qsort(v2, n, sizeof(int), comp2);
		ret = 0;
		for (j = 0; j < n; j++) {
			ret += v1[j] * v2[j];
		}
		printf("Case #%d: %d\n", i + 1, ret);
	}
	return 0;
}
