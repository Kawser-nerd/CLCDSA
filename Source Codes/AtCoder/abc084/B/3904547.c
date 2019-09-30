#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[99];
int main(){
	int n,m;
	scanf("%d%d%s",&n,&m,s);
	int flag=1;
	rep(i,0,n)if(s[i]=='-')flag=0;
	if(s[n]!='-')flag=0;
	rep(i,0,m)if(s[n+1+i]=='-')flag=0;
	puts(flag?"Yes":"No");
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%s",&n,&m,s);
  ^