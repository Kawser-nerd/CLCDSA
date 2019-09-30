#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int a[N];
	int  i, j, k;
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int max, min;
	for (i = 0, max = a[0]; i < N; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	for (i = 0, min = a[0]; i < N; i++) {
		if (min > a[i]) {
			min = a[i];
		}
	}
	printf("%d\n", max - min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^