#include <stdio.h>
#include <stdlib.h>

struct shop {
	long long int A;
	long long int B;
};

int compare(const void *a, const void *b) {
	struct shop *A = (struct shop *)a;
	struct shop *B = (struct shop *)b;
	if(A->A < B->A) return -1;
	if(A->A > B->A) return 1;
	return 0;
}

int main() {
	long long int N;
	long long int M;
	long long int index = 0;
	struct shop *shop;
	long long int i;
	long long int min_money = 0;

	scanf("%lld", &N);
	scanf("%lld", &M);
	shop = (struct shop *)malloc(sizeof(struct shop) * N);
	for(i = 0;i<N;i++) {
		scanf("%lld", &shop[i].A);
		scanf("%lld", &shop[i].B);
	}
	qsort(shop, N, sizeof(struct shop), compare);

	for(i=0;i<N;i++) {
		if(shop[i].B <= M) {
			min_money += shop[i].A * shop[i].B;
			M = M - shop[i].B;
		} else {
			min_money += shop[i].A * M;
			break;
		}
	}
	printf("%lld\n", min_money);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:26:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &M);
  ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &shop[i].A);
   ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &shop[i].B);
   ^