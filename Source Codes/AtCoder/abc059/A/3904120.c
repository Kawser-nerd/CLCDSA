#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[3][20];
int main(){
	scanf("%s%s%s",s[0],s[1],s[2]);
	printf("%c%c%c",s[0][0]^32,s[1][0]^32,s[2][0]^32);
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s%s",s[0],s[1],s[2]);
  ^