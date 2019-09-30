#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	long b;
} s;

int compare(const void *x, const void *y)
{
	return ((s*)x)->a - ((s*)y)->a;
}

int main(void)
{
	int N, i;
	long K, sum = 0;
	s array[100000];
	scanf("%d%ld", &N, &K);
	for (i = 0; i < N; ++i) scanf("%d%ld", &array[i].a, &array[i].b);
	qsort(array, N, sizeof(s), compare);
	for (i = 0; sum < K; ++i) sum += array[i].b;
	printf("%d", array[i - 1].a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%ld", &N, &K);
  ^
./Main.c:20:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 0; i < N; ++i) scanf("%d%ld", &array[i].a, &array[i].b);
                          ^