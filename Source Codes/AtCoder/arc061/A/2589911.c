#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

#define bit(n,m)((n>>m)&1)
ll n;
ll ans;
char s[99];
int main(){
	scanf("%s",s);
	n=strlen(s);
	rep(i,0,1<<(n-1)){
		ll ss=0;
		ll temp=s[0]-48;
		rep(j,0,n-1){
			if(bit(i,j))temp=temp*10+s[j+1]-48;
			else {
				ss+=temp;
				temp=s[j+1]-48;
			}
		}
		ss+=temp;
		ans+=ss;
	}
	
	printf("%lld\n",ans);
	
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^