#include<stdio.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	if((a*b)%2== 1){
		printf("Odd\n");
		
	}else{
		printf("Even\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^