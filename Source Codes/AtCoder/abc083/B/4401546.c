#include <stdio.h>

int main (void){
	
	int N, A, B;

	scanf("%d", &N);
	scanf("%d", &A);
	scanf("%d", &B);

	int i, sum = 0, SUM = 0;
	int sum4 = 0, sum3 = 0, sum2 = 0, sum1 = 0, sum0 = 0;

	for(i = 1; i <= N; i++){
		sum4 = i / 10000;
		sum3 = (i - 10000 * sum4) / 1000;
		sum2 = (i - 10000 * sum4 - 1000 * sum3) / 100;
		sum1 = (i - 10000 * sum4 - 1000 * sum3 - 100 * sum2) / 10;
		sum0 = (i - 10000 * sum4 - 1000 * sum3 - 100 * sum2 - 10 * sum1);

		sum = sum4 + sum3 + sum2 + sum1 + sum0;

		if( A <= sum && sum <= B){
			SUM = SUM + i;
		}
	}

	printf("%d\n", SUM);

	return 0;

} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &A);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &B);
  ^