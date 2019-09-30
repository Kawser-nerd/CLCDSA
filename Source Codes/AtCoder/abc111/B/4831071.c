#include<stdio.h>
int main(void){
	int N,x,a,b,c,i;
	scanf("%d", &N);
	x = N;
	for (i = 0; i < 999 - N; i++){
		
		if (x % 111 == 0){
			break;
		}
		x++;
	}
	printf("%d", x);

		return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^