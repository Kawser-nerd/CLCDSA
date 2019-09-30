#include<stdio.h>
#include<stdlib.h>
int main() {
	int N;
	int  sum = 0, ans = 0;
	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int)*(N + 2));
	A[0] = 0;
	A[N + 1] = 0;
	for (int i = 1; i < N + 1; i++)
	{
		scanf("%d", &A[i]);
	}
	for (int i = 1; i < N + 2; i++)
	{
		sum += abs(A[i] - A[i - 1]);
	}

	for (int i = 1; i < N + 1; i++)
	{
		ans = sum - abs(A[i] - A[i - 1]) - abs(A[i + 1] - A[i]) + abs(A[i + 1] - A[i - 1]);
		printf("%d\n", ans);
		ans = 0;
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^