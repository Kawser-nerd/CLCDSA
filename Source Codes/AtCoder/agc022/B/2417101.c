#include <stdio.h>
#include <stdlib.h>
 
int main(){
	int N, k, l, i;
	scanf("%d", &N);
	if(N == 3){
		printf("2 5 63\n");
		return 0;
	}
	if(N <= 15002){
		k = N - 2;
		l = 2;
	}
	else{
		if(N % 2 == 1){
			k = 14999;
			l = N - k;
		}
		else{
			k = 15000;
			l = N - k;
		}
	}
	if(k % 3 == 1){
		for(i = 1; i <= (k / 3) * 3; i++){
			printf("%d ", 2 * i);
		}
		printf("%d ", 2 * (k / 3 + 1) * 3);
	}
	else{
		for(i = 1; i <= k; i++){
			printf("%d ", 2 * i);
		}
	}
	for(i = 1; i <= l; i++){
		printf("%d ", 6 * i - 3);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^