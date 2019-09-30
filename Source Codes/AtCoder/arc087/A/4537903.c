#include<stdio.h>
#include<stdlib.h>
#define TYPE int
int cmp(const void *a, const void *b) { return *(TYPE *)a - *(TYPE *)b; }
int A[100000];
int main() {
	int N;
	int num = 1;
	int i;
	int ans = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(int), cmp);
	for (i = 0; i < N; i++)
	{
		while (A[i] == A[i + 1])
		{
			num++;
			i++;
		}
		if (num < A[i])
		{
			ans += num;
		}
		else if (num > A[i])
		{
			ans += num - A[i];
		}
		num = 1;
	}
	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^