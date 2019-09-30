#include <stdio.h>

int main(){
	int N, d, i, maxd = 0, sum = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d", &d);
		if(d > maxd){
			maxd = d;
		}
		sum += d;
	}
	printf("%d\n", sum);
	if(2 * maxd <= sum){
		printf("0\n");
	}
	else{
		printf("%d\n", 2 * maxd - sum);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &d);
   ^