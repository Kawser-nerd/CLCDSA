#include <stdio.h>

int A[100001];

int main(void) {
	int i, N, a, ans,count = 0, double_count = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &a);
		if (A[a] == 0 || A[a] == 1) {
			A[a]++;
		} 
		else {
			A[a]--;
		}
	}

	for (i = 1; i <= 100000; i++) {
		if (A[i] == 2) {
			double_count++;
		}
		count += A[i];
	}

	ans = count - double_count - (double_count % 2);
	printf("%d", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^