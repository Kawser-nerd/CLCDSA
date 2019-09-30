#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll d[100010];
ll c[100010];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1)c[i]=1;
	d[1]=1;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		c[y]++;
		if(d[x])d[y]=1;
		c[x]--;
		if(!c[x])d[x]=0;
		
	}
	ll ans=0;
	rep(i,1,n+1)ans+=d[i];
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^