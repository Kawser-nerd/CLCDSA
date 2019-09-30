#include<stdio.h>
int main() {
	int N, K;
	int tmp = 0, ans = 0;
	scanf("%d%d", &N, &K);
	int *A = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	while (tmp < N)
	{
		if (tmp == 0)
		{
			tmp += K;
		}
		else if (tmp > 0)
		{
			tmp += (K - 1);
		}
		ans++;
	}
	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:17: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
  int *A = (int*)malloc(sizeof(int)*N);
                 ^
./Main.c:6:17: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:6:17: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^