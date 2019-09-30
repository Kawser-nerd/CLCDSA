#include <stdio.h>
#include <stdlib.h>
#define ll long long int

ll X[100];
ll Y[100];
int N;
int K;

int InRange(ll t, ll l, ll r){
	return l <= t && t <= r; // inclusive;
}

ll min (ll a, ll b){
	return a < b ? a : b;
}

ll minRange(ll a, ll b, ll c, ll d){
	ll ret = a;
	ret = min(ret, b);
	ret = min(ret, c);
	ret = min(ret, d);
	return ret;
}
ll max (ll a, ll b){
	return a > b ? a : b;
}

ll maxRange(ll a, ll b, ll c, ll d){
	ll ret = a;
	ret = max(ret, b);
	ret = max(ret, c);
	ret = max(ret, d);
	return ret;
}

int main(){
	
	int i,j,k,l,m;
	scanf("%d%d",&N, &K);
	for(i=0;i<N;i++) scanf("%lld%lld",&X[i], &Y[i]);
	
	ll w0,w1,h0,h1;
	ll ar;
	
	ll ans = (ll)4e18;
	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			for(k=j;k<N;k++){
				for(l=k;l<N;l++){
				
					w0 = minRange(X[i],X[j],X[k],X[l]);
					w1 = maxRange(X[i],X[j],X[k],X[l]);
					h0 = minRange(Y[i],Y[j],Y[k],Y[l]);
					h1 = maxRange(Y[i],Y[j],Y[k],Y[l]);
					
					ar = (w1 - w0) * (h1 - h0);
					if(ar == 0) continue; // ????
					
					int cnt = 0;
					for(m=0;m<N;m++){
						if(InRange(X[m], w0, w1) && InRange(Y[m], h0, h1)) cnt++;
					}
					if(cnt >= K){
						ans = min(ans, ar);
					}
					
				}
			}
		}
	}
	
	printf("%lld\n",ans);
	
	
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N, &K);
  ^
./Main.c:41:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++) scanf("%lld%lld",&X[i], &Y[i]);
                   ^