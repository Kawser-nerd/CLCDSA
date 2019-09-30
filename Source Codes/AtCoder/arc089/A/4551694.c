#include<stdio.h>
#include<stdlib.h>
int main() {
	int N;
	int man = 0, dis = 0;
	scanf("%d", &N);
	int *T = (int *)malloc(sizeof(int)*N);
	int *X = (int *)malloc(sizeof(int)*N);
	int *Y = (int *)malloc(sizeof(int)*N);
	T[0] = 0, X[0] = 0, Y[0] = 0;
	for (int i = 1; i < N+1; i++)
	{
		scanf("%d%d%d", &T[i], &X[i], &Y[i]);
	}
	for (int i = 1; i < N+1; i++)
	{
		man = abs(X[i] - X[i - 1]) + abs(Y[i] - Y[i - 1]);
		dis = T[i] - T[i - 1];
		//man = 4;
		//dis = 5;
		if (man > dis || (dis - man >= 0 && (dis - man) % 2 == 1))
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &T[i], &X[i], &Y[i]);
   ^