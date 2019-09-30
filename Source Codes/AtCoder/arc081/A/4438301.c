#include<stdio.h>
#include<stdlib.h>

int compare_int(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main() {
	int	N;
	int a = -1, b = -1;
	long long ans = 0;
	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(int), compare_int);
	//for (int i = 0; i < N; i++)
	//{
	//	printf("%d ", A[i]);
	//}
	for (int i = 1; i < N; i++)
	{
		if (a == -1 && A[i] == A[i - 1])
		{
			a = A[i];
			if (i < N - 1)
			{
				i++;
			}else
			{
				break;
			}
			continue;
		}
		if (a != -1 && b == -1 && A[i] == A[i - 1])
		{
			b = A[i];
			break;
		}
	}
	if (a != -1 && b != -1)
	{
		ans = (long long)a * (long long)b;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^