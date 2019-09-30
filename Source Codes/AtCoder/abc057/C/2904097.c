#include <stdio.h>
#include <math.h>

typedef long long ll;

int main(){

	ll N;

	scanf("%lld",&N);

	ll stop=(ll)(sqrt((double)N)+1ll);

	ll i;

	int ans=114514;

	for(i=1ll;i<=stop;i+=1ll){

		if(N%i==0ll){

			ll j=N/i;

			int digit=0;

			while(j!=0ll){
				j/=10ll;
				digit++;
			}
			if(ans>digit){ans=digit;}
		}
	}
	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&N);
  ^