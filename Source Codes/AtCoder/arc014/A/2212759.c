#include <stdio.h>

int main(){
	int N;
	scanf("%d", &N);
	if(N % 2 == 0){
		printf("Blue\n");
	}
	else{
		printf("Red\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^