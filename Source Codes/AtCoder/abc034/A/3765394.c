#include<stdio.h>
int x, y;
int main(){
	scanf("%d%d", &x, &y);
	if(x<y){
		printf("Better\n");
	}else{
		printf("Worse\n");
	}
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &x, &y);
  ^