#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int idx;
	int a;
	int b;
} num_t;

static int cmp_a(const void *a, const void *b);
static int cmp_idx(const void *a, const void *b);

int main(int argc, char *argv[])
{
	int i, N, n = 0, prev;
	num_t list[100000];
	scanf("%d", &N);
	for ( i = 0; i < N; i++ ){
		scanf("%d", &list[i].a);
		list[i].idx = i + 1;
	}
	qsort(list, N, sizeof(num_t), cmp_a);

	for ( i = 0, prev = list[0].a; i < N; i++ ){
		if ( prev == list[i].a ){
			list[i].b = n;
		} else {
			list[i].b = ++n;
		}
		prev = list[i].a;
	}
	qsort(list, N, sizeof(num_t), cmp_idx);
	for ( i = 0; i < N; i++ ){
		printf("%d\n", list[i].b);
	}
	return 0;
}

static int cmp_a(const void *a, const void *b)
{
	return ((num_t *)a)->a - ((num_t *)b)->a;
}

static int cmp_idx(const void *a, const void *b)
{
	return ((num_t *)a)->idx - ((num_t *)b)->idx;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &list[i].a);
   ^