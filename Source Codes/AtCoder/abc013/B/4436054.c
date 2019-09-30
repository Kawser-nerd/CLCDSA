#include<stdio.h>
int main(void)
{
	int a,b,n;
	scanf("%d",&a);
	scanf("%d",&b);
	if(a>b){
		n=a-b;
		if(n>5){
		n=b+10-a;
		}
	}else{
		n=b-a;
		if(n>5){
			n=a+10-b;
		}
	}
	printf("%d\n",n);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&b);
  ^