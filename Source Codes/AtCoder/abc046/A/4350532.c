#include <stdio.h>

int main(void)
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	
	if(a==b&&b==c&&c==a){
		printf("1\n");
	}else if(a==b||b==c||c==a){
		printf("2\n");
	}else{
		printf("3\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^