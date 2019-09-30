#include<stdio.h>
int f[100002];
int main() {
	int N;
	int max = -1;
	int crt = 0;
	int ans = 0;
	scanf("%d", &N);
	int A;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A);
		f[A]++;
	}

	for (int i = 0; i <= 100010; i++)
	{
		crt = f[i] + f[i + 1] + f[i + 2];
		if (ans < crt)
		{
			ans = crt;
		}
	}
	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A);
   ^
./Main.c:18:10: warning: iteration 100002u invokes undefined behavior [-Waggressive-loop-optimizations]
   crt = f[i] + f[i + 1] + f[i + 2];
          ^
./Main.c:16:2: note: containing loop
  for (int i = 0; i <= 100010; i++)
  ^