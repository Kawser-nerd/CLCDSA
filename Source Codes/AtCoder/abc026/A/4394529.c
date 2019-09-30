#include <stdio.h>
int main(void){
	int x,y,a;
	scanf("%d",&a);
	if(a%2==0){
		x=a/2;
		y=a/2;
	}
	else{
		x=a/2+1;
		y=a/2;
	}
	printf("%d\n",x*y);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^