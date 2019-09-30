#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[110],t[110];
int main(){
	scanf("%s%s",s,t);
	ll sn=strlen(s);
	ll tn=strlen(t);
	if(sn<tn)puts("LESS");
	else if(sn>tn)puts("GREATER");
	else{
		rep(i,0,sn){
			if(s[i]<t[i]){
				puts("LESS");
				return 0;
			}
			if(s[i]>t[i]){
				puts("GREATER");
				return 0;
			}
		}
		puts("EQUAL");
	}
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s,t);
  ^