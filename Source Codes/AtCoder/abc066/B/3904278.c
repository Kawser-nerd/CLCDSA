#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[210];
int main(){
	scanf("%s",s);
	ll n=strlen(s);
	if(n%2==1)n--;
	else n-=2;
	while(1){
		int flag=1;
		rep(i,0,n/2){
			if(s[i]!=s[i+n/2]){
				flag=0;
				break;
			}
		}
		if(flag){
			printf("%lld",n);
			return 0;
		}
		n-=2;
	}
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^