#include <stdio.h>
int main(void){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(b/a < c ){
		printf("%d",b/a);
	}else{
		printf("%d",c);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^