#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[3][11];
int main(){
	rep(i,0,3)scanf("%s",s[i]);
	puts(s[0][strlen(s[0])-1]==s[1][0]&&s[1][strlen(s[1])-1]==s[2][0]?"YES":"NO");
} ./Main.c: In function ‘main’:
./Main.c:11:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,3)scanf("%s",s[i]);
            ^