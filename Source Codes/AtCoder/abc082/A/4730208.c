#include<stdio.h>
int main(void)
{
	int a,b,i;
	
	scanf("%d%d",&a,&b);
	i=a+b;
	
	if(i%2==0){
		printf("\n%d\n\n",i/2);
	}else{
		printf("\n%d\n\n",(i+1)/2);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^