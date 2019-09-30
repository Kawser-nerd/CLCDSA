#include<stdio.h>
int a[200010], b[200010];
int main() {
	int N, M;
	int A, B;
	int ok = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &A, &B);
		if (A == 1) { a[B] = 1; }
		if (B == 1) { a[A] = 1; }
		if (A == N) { b[B] = 1; }
		if (B == N) { b[A] = 1; }
	}

	for (int i = 0; i < N; i++)
	{
		if (a[i] == 1 && b[i] == 1)
		{
			ok = 1;
			break;
		}
	}
	if (ok)
	{
		puts("POSSIBLE");
	}
	else
	{
		puts("IMPOSSIBLE");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &A, &B);
   ^