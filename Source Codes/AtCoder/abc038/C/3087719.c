#include <stdio.h>

typedef long long ll;

int a[100005];

int main() {

	int N;

	scanf("%d",&N);

	int i;

	for(i=0;i<N;i++){
	scanf(" %d",&a[i]);
	}

	int l,r;

	l=0;
	r=0;

	ll ans=0ll;

	while(1){
	
		if(r==N-2){
			if(a[N-2]>=a[N-1]){
			ll add=(ll)(r-l+1);
			ans+=add*(add+1ll)/2ll;
			ans+=1ll;
			}
			else{
			ll add=(ll)(N-l);
			ans+=add*(add+1ll)/2ll;
			}
			break;
		}

		if(a[r]>=a[r+1]){
		ll add=(ll)(r-l+1);
		ans+=add*(add+1ll)/2ll;
		l=r+1;
		r=r+1;
		}
		else{
		r++;
		}	
	}

	printf("%lld\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf(" %d",&a[i]);
  ^