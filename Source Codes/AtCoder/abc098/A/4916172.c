#include<stdio.h>
int main(void)
{
	int a,b,wa,sa,seki;
	scanf("%d %d",&a,&b);
	wa=a+b;
	sa=a-b;
	seki=a*b;
	if(sa<=wa && seki<=wa){
		printf("%d\n",wa);
	}
	else if(wa<=sa && seki<=sa){
		printf("%d\n",sa);
	}
	else{
		printf("%d\n",seki);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^