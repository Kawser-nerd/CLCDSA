#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define bit(n,m)((n>>m)&1)
int main(){
    ll n,ans,tmp,num[11],ss=0;
    char s[11];
	scanf("%s",s);
	n=strlen(s);
    rep(i,0,n)num[i]=s[i]-48;
	rep(i,0,1<<(n-1)){
		ss=0;
		tmp=num[0];
		rep(j,0,n-1){
			if(bit(i,j))tmp=tmp*10+num[j+1];
			else {
				ss+=tmp;
				tmp=num[j+1];
			}
		}
		ss+=tmp;
		ans+=ss;
    }
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^