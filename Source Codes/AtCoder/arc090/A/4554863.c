#include<stdio.h>
int main() {
	int N;
	scanf("%d", &N);
	int **A = (int **)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++)
	{
		A[i] = (int *)malloc(sizeof(int) * N);
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	//for (int i = 0; i < 2; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		printf("%d ", A[i][j]);
	//	}
	//	printf("\n");
	//}
	int k, l, m, sum = 0, tmp = 0;
	int ans = 0;
	for (m = 0; m < N; m++) {
		k = 0;
		while (k <= m) {
			sum += A[0][k];
			k++;
		}
		l = m;
		while (l < N) {
			sum += A[1][l];
			l++;
		}
		if (tmp < sum) {
			tmp = sum;
		}
		sum = 0;
	}

	ans = tmp;
	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:20: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
  int **A = (int **)malloc(sizeof(int*) * 2);
                    ^
./Main.c:5:20: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:5:20: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:14:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &A[i][j]);
    ^