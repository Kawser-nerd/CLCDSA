#include<stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	if (N % 2 == 0)
	{
		for (int i = N - 1; i > 0; i -= 2)
		{
			printf("%d ", A[i]);
		}
		for (int i = 0; i < N; i += 2)
		{
			printf("%d ", A[i]);
		}
	}
	if (N % 2 == 1)
	{
		for (int i = N - 1; i >= 0; i -= 2)
		{
			printf("%d ", A[i]);
		}
		for (int i = 1; i < N; i += 2)
		{
			printf("%d ", A[i]);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:18: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
  int *A = (int *)malloc(sizeof(int)*N);
                  ^
./Main.c:5:18: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:5:18: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^