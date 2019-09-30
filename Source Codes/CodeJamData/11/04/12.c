#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
	if(*((int *)a) > *((int *)b))
		return 1;
	else if(*((int *)a) < *((int *)b))
		return -1;
	else
		return 0;
}

int testcase(int Ti) {
	int orig[2000], incr[2000];
	int N, i, count = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++)
		scanf("%d", &orig[i]);
	memcpy(incr, orig, sizeof(int)*N);
	qsort(incr, N, sizeof(int), &cmp);
	for(i = 0; i < N; i++)
		if(incr[i] != orig[i]) count++;
	printf("Case #%d: %.6f\n", Ti, (float)count);
	return 0;
}

int main() {
	int T, i;
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
		testcase(i);
	return 0;
}
