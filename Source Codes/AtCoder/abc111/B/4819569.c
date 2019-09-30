#include<stdio.h>
int main(void){
	int N;
	scanf("%d",&N);
	int a;
	if((N%111)==0){
		printf("%d",N);
	}else{
		printf("%d",((N/111)+1)*111);
	}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^