#include<stdio.h>
#include<stdlib.h>
#define TYPE long long
int cmp(const void *a, const void *b) { return *(TYPE *)a - *(TYPE *)b; }
int cmp_r(const void *a, const void *b) { return *(TYPE *)b - *(TYPE *)a; }
long long A[100002], B[100002], C[100002];
int main() {
	long long N;
	scanf("%lld", &N);
	//int *A = (int *)malloc(sizeof(int)*N);
	//int *B = (int *)malloc(sizeof(int)*N);
	//int *C = (int *)malloc(sizeof(int)*N);

	//int tmp;
	long long tmp;

	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &B[i]);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &C[i]);
	}
	qsort(A, N, sizeof(TYPE), cmp);
	qsort(B, N, sizeof(TYPE), cmp);
	qsort(C, N, sizeof(TYPE), cmp);
	//printf("\n");
	//for (int i = 0; i < N; i++)
	//{
	//	printf("%lld ", A[i]);
	//}
	//printf("\n");
	//for (int i = 0; i < N; i++)
	//{
	//	printf("%lld ", B[i]);
	//}
	//printf("\n");
	//for (int i = 0; i < N; i++)
	//{
	//	printf("%lld ", C[i]);
	//}
	//printf("\n");
	int j = 0, k = 0;
	for (int i = 0; i < N; i++)
	{
		//j = 0, k = 0;
			while (A[j] < B[i] && j < N)
		{
			j++;
		}
			while (B[i] >= C[k] && k < N)
		{
			k++;
		}
		tmp = j*(N-k);
		ans += tmp;

		//printf("ab[%d]:%lld bc[%d]:%lld ", i, ab[i],i,bc[i]);
		//printf("tmp[%d]:%lld\n", i, tmp[i]);
		//printf("ans:%lld\n", ans);
	}

	printf("%lld\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &B[i]);
   ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &C[i]);
   ^