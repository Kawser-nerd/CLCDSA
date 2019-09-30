#include<stdio.h>

int main(){
	long long a,b,x;
	scanf("%lld%lld%lld",&a,&b,&x);
	long long z,c;
	if(a%x==0){
		z=a/x;
	}
	else{
		z=a/x+1;
	}
	c=b/x;
	printf("%lld",c-z+1);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&x);
  ^