#include <stdio.h>
int main(void){
	long long int n,a1=0,a2=0,a3=1,a4;
	scanf("%lld",&n);
	if(n>3){
		while(n!=3){
			a4=(a1+a2+a3)%10007;
			a1=a2%10007;
			a2=a3%10007;
			a3=a4%10007;
			n--;
		}
	printf("%lld\n",a4);
	}
	else if(n==1) printf("%lld\n",a1);
	else if(n==2) printf("%lld\n",a2);
	else printf("%lld\n",a3);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^