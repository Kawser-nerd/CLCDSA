#include<stdio.h>
int main(void)
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(b<=a && c<=a){
		printf("%d\n",a*10+b+c);
	}
	else if(a<=b && c<=b){
		printf("%d\n",b*10+a+c);
	}
	else{
		printf("%d\n",c*10+a+b);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^