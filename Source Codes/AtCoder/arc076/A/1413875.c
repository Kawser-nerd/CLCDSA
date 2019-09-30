#include <stdio.h>
#include<string.h>

int main(void)
{
	long long int n,m,i,ans,m2=1,m3;
	scanf("%lld %lld",&n,&m);
	
	if(n-m>=2||m-n>=2){
		printf("0\n");
	} else if(n-m==0){
		for(i=m;i>=2;i--){
			m2*=i;
			m2=m2%(10*10*10*10*10*10*10*10*10+7);
		}
		m3=(2*m2*m2)%(10*10*10*10*10*10*10*10*10+7);
		printf("%lld\n",m3);
	} else if(n-m==1||m-n==1){
		for(i=m;i>=2;i--){
			m*=(i-1);
			m=m%(10*10*10*10*10*10*10*10*10+7);
		}
		for(i=n;i>=2;i--){
			n*=(i-1);
			n=n%(10*10*10*10*10*10*10*10*10+7);
		}
		ans=(n*m)%(10*10*10*10*10*10*10*10*10+7);
		printf("%lld\n",ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&m);
  ^