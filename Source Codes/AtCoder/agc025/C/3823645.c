#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int tl[200020],tr[200010];
int*l=tl+100010,*r=tr+100010;
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		int x,y;
		scanf("%d%d",&x,&y);
		l[x]++;
		r[y]++;
	}
	l[0]++;r[0]++;
	for(int i=100005;i>=-100005;i--)l[i-1]+=l[i];
	rep(i,-100005,100005)r[i+1]+=r[i];
	
	//???[i,i+1]???????i????????????i+1????????????min
	ll ans=0;
	rep(i,-100005,100005)ans+=min(r[i],l[i+1]);
	printf("%lld",ans*2);
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^