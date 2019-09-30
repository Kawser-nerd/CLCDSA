#include<stdio.h>
int main() {
	int N, X;
	scanf("%d%d", &N, &X);
	int *A = (int *)malloc(sizeof(int)*N);
	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		if (i >= 1 && A[i] + A[i - 1] > X) {
			int tmp = A[i] + A[i - 1];
			if (A[i] + A[i - 1] - X <= A[i]) {
				A[i] = A[i] - (A[i] + A[i - 1] - X);
			}
			else {
				A[i] = 0;
				A[i - 1] = A[i - 1] - (A[i] + A[i - 1] - X);
			}
			ans += tmp - (A[i] + A[i - 1]);
			//printf("%d:%lld\n", i,ans);
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:18: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
  int *A = (int *)malloc(sizeof(int)*N);
                  ^
./Main.c:5:18: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:5:18: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &X);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^