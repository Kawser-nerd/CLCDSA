#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int a[N], b[N];
	int i;
	for (i = 0; i < N; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	int sum = 0;
	for (i = 0; i < N; i++) {
		sum += a[i] * b[i];
	}
	sum = sum * 1.05;
	printf("%d\n", (int)sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a[i], &b[i]);
   ^