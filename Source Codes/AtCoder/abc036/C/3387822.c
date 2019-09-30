#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int b, tmp1, tmp2;
} s;

int compare1(const void *x, const void *y)
{
	return ((s*)x)->tmp1 - ((s*)y)->tmp1;
}

int compare2(const void *x, const void *y)
{
	return ((s*)x)->tmp2 - ((s*)y)->tmp2;
}

int main(void)
{
	int N, i;
	s people[100000];
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &people[i].tmp1);
		people[i].tmp2 = i;
	}
	qsort(people, N, sizeof(s), compare1);
	people[0].b = 0;
	for (i = 1; i < N; ++i) {
		if (people[i - 1].tmp1 < people[i].tmp1) people[i].b = people[i - 1].b + 1;
		else people[i].b = people[i - 1].b;
	}
	qsort(people, N, sizeof(s), compare2);
	for (i = 0; i < N; ++i) printf("%d\n", people[i].b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &people[i].tmp1);
   ^