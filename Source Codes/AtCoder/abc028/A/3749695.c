#include<stdio.h>
int N;
int main(){
	scanf("%d", &N);
	if(N < 60){
		printf("Bad\n");
	}else if(N < 90){
		printf("Good\n");
	}else if(N < 100){
		printf("Great\n");
	}else{
		printf("Perfect\n");
	}
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^