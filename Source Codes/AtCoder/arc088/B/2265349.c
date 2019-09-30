#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define max(p,q)((p)>(q)?(p):(q))

char s[100010];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	
	ll ans=n;
	rep(i,0,n-1)if(s[i]!=s[i+1])ans=min(ans,max(n-1-i,i+1));
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^