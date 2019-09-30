#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a, tmp;
} s;

int compare(const void *x, const void *y)
{
	return ((s*)y)->a - ((s*)x)->a;
}

int main(void)
{
	int N, i;
	s student[100000];
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &student[i].a);
		student[i].tmp = i + 1;
	}
	qsort(student, N, sizeof(s), compare);
	for (i = 0; i < N; ++i) printf("%d\n", student[i].tmp);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &student[i].a);
   ^