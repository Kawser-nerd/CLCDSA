#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

char s[100010];
int main(){
	scanf("%s",s);
	ll n=strlen(s);
	ll ans=0;
	rep(i,0,n){
		if(s[i]=='U')ans+=i;
		else ans+=n-1-i;
	}
	printf("%lld\n",ans+n*(n-1));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^