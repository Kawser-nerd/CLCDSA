#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int m[N];
	int i, j;
	for (i = 0; i < N; i++) {
		scanf("%d", &m[i]);
	}
	int sum = 0;
	for (i = 0; i < N; i++) {
		if (m[i] >= 80) {
			continue;
		} 
		if (m[i] < 80) {
			sum += (80 - m[i]);
		}
	}
	printf("%d\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &m[i]);
   ^