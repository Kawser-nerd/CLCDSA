#include <stdio.h>

int main(void){

	int N;
	int num1 = 0, num2 = 0, num3 = 0;
	int SUM = 0;

	scanf("%d", &N);

	num1 = N / 100;
	num2 = (N - num1 * 100) / 10;
	num3 = N - num1 * 100 - num2 * 10;

	SUM = num3 * 100 + num2 * 10 + num1 * 1;

	if(N == SUM){
		printf("Yes\n");
	}else{
		printf("No\n");
	}

	return 0;

} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^