#include<stdio.h>

int main(){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	long long z;
	z=b/2;
	if(z<=a){
		printf("%lld",z);
	}
	else{
		z-=a;
		z*=2;
		z/=4;
		a+=z;
		printf("%lld",a);
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&a,&b);
  ^