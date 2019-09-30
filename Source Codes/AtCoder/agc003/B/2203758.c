#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll ans;
ll d[100010];
int main(){
	int n;
	scanf("%d",&n);
	int t=0;
	while(n--){
		int m;
		scanf("%d",&m);
		if(t&&m){
			ans++;
			m--;
		}
		ans+=m/2;
		t=m%2;
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^