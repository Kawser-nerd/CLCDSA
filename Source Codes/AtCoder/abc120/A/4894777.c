#include<stdio.h>

int main(void)
{
	int a,b,c,d;

	scanf("%d %d %d",&a,&b,&c);
	
	d=b/a;

	if(d>=c){
	printf("%d\n",c);

	}else{
		printf("%d\n",d);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^