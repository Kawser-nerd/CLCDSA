#include<stdio.h>

#define bb 2000000000000

int main(){
	long long a,k,ans=0;
	scanf("%lld%lld",&a,&k);
	if(k>=1){
		while(a<bb){
			a+=a*k+1;
			ans++;
		}
	}else ans=bb-a;
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&a,&k);
  ^