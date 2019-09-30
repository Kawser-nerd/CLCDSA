#include <stdio.h>

int main(){
	long long int N;
	scanf("%lld", &N);
	int k, digit[64];
	for(k = 0; N != 0; k++){
		digit[k] = N & 0x1;
		N >>= 1;
	}
	int i, left[2 * k - 1];
	for(i = 1; i <= k; i++){
		left[2 * i] = i;
	}
	int j = k;
	for(i = 0; i < k - 1; i++){
		if(digit[k - i - 2] == 1){
			left[2 * k - 3 - 2 * i] = j;
			j++;
		}
		else{
			left[2 * k - 3 - 2 * i] = 0;
		}
	}
	left[0] = j;
	printf("%d\n", 2 * j);
	for(i = 0; i < 2 * k - 1; i++){
		if(left[i] != 0){
			printf("%d ", left[i]);
		}
	}
	for(i = 1; i <= j; i++){
		printf("%d ", i);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^