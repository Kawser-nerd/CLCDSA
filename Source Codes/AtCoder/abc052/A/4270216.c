#include<stdio.h>

int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a*b>=c*d){
		printf("%d",a*b);
	}
	else{
		printf("%d",c*d);
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&a,&b,&c,&d);
  ^