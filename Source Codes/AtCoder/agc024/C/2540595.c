#include<stdio.h>
#define MAX 200000

int main() {
	int N, A[MAX];
	long long cnt = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			if (A[0] != 0) {
				cnt = -1;
				break;
			}
		}
		else if (A[i] > A[i - 1] + 1) {
			cnt = -1;
			break;
		}
		else if (A[i] == A[i - 1] + 1) {
			cnt++;
		}
		else if (A[i] <= A[i - 1]) {
			cnt += A[i];
		}
	}

	printf("%lld\n", cnt);


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^