#include<stdio.h>

int main()
{
	int N,M,C,A[20],B[20];
	int ans = 0;
	int count = 0;
	scanf("%d %d %d", &N,&M,&C);
	for (int i = 0; i < M; i++) scanf("%d", &B[i]);
	for (int i = 0; i < N; i++) {
		for (int j=0; j < M; j++) {
			scanf("%d", &A[j]);
			ans += A[j] * B[j];
		}
		if (ans+C > 0)count++;
		ans = 0;
	}
	printf("%d\n", count);

}