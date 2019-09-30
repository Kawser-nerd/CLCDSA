#include <stdio.h>
#include <stdlib.h>
/* sqrt ???????sqrt(a)*sqrt(a)=n ???*/
int dig(long long x){
	int c = 0;
	while(x>0){x/=10;c++;}
	return c;
}

int main(void){
	long long n,i,j;
	scanf("%lld",&n);
	int c=dig(n);
	for(i=1;i*i<=n;i++){
		if(n%i==0){
			if(n/i>i)j=n/i;
			else j=i;
			int d = dig(j);
			if(d<c)c=d;
		}
	}
	
	printf("%d",c);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^