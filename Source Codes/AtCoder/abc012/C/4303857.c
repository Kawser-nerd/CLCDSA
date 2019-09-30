#include<stdio.h>
int main(void)
{
	int n,s=0,i,j,a;
	scanf("%d",&n);
	for(i=1;i<=9;i++){
		for(j=1;j<=9;j++){
			s+=i*j;
		}
	}
	a=s-n;
	for(i=1;i<=9;i++){
		if(a%i==0&&(a/i)<=9){
			printf("%d x %d\n",i,a/i);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^