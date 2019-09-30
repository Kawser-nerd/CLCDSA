#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[99];
int a[99];
int main(){
	scanf("%s",s);
	ll n=strlen(s);
	rep(i,0,n)if(a[s[i]-'a']++){
		puts("no");
		return 0;
	}
	puts("yes");
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^