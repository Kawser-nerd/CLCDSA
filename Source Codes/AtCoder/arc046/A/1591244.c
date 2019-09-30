#include <stdio.h>

int main(){
	int N, i;
	scanf("%d", &N);
	for(i = 0; i < (N - 1) / 9 + 1; i++){
		printf("%d", (N - 1) % 9 + 1);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^