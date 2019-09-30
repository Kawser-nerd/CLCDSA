#include <stdio.h>

int A[100005];
int tmp[100005];

int main() {

	int N;

	scanf("%d",&N);

	int i;

	for (i = 0; i < N; i++) {
		scanf(" %d",&A[i]);
		tmp[A[i]]++;
	}

	int k = 0;

	for (i = 0; i < 100005; i++) {
		if (tmp[i] > 0) {
			k++;
		}
	}

	if (k % 2 == 0) { printf("%d\n",k-1); }
	else { printf("%d\n",k); }


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %d",&A[i]);
   ^