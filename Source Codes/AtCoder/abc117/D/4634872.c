#include <stdio.h>
#include <stdlib.h>
#define ll long long int
ll max(ll x, ll y){return x<y?y:x;}
int main(void){
	int n,i,j;
	ll k,ans=0,A,c[40]={0},K[40];
	scanf("%d %lld",&n,&k);
	for(i=0;i<n;i++){
		scanf("%lld",&A);
		for(j=0;j<40;j++){
			c[j] += A%2;
			A = A>>1;
		}
	}
	k++;
	for(i=0;i<40;i++){
		K[i] = k%2;
		k >>= 1;
	}
	
	for(i=0;i<40;i++){
		if(K[i]){
			ll ans2 = c[i]<<i;
			for(j=39;j>i;j--){
				ll x;
				if(K[j])x=n-c[j];
				else x=c[j];
				ans2 += x<<j;
			}
			for(j=0;j<i;j++){
				ll x;
				if(c[j]>n/2)x=c[j];
				else x=n-c[j];
				ans2 += x<<j;
			}
			ans = max(ans,ans2);
		}
	}
	printf("%lld",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %lld",&n,&k);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&A);
   ^