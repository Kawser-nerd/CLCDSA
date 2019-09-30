#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, a, b, i, sum = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		scanf("%d%d", &a, &b);
		sum += a * b;
	}
	printf("%d\n", (sum * 105) / 100);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^