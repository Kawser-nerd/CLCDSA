#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n;
	int max = 0;
	int a[2][100];
	int i, j;
	int sum[2] = { 0 };
	int sum0;
	scanf("%d", &n);
	for (i = 0; i < 2; ++i){
		for (j = 0; j < n; ++j){
			scanf("%d", &a[i][j]);
			sum[i] += a[i][j];
		}
	}
	sum0 = a[0][0] + sum[1];
	for (i = 0; i < n; ++i){
		if (sum0 > max)max = sum0;

		sum0 = sum0 - a[1][i] + a[0][i + 1];
	}
	printf("%d\n", max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:14:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &a[i][j]);
    ^