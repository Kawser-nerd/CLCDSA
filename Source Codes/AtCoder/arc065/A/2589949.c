#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

char s[100010];
ll n;
int main(){
	scanf("%s",s);
	n=strlen(s);
	for(ll i=n-1;i>=0;){
		if(i>=4&&!strcmp(s+i-4,"dream"))i-=5,s[i+1]=0;
		else if(i>=6&&!strcmp(s+i-6,"dreamer"))i-=7,s[i+1]=0;
		else if(i>=4&&!strcmp(s+i-4,"erase"))i-=5,s[i+1]=0;
		else if(i>=5&&!strcmp(s+i-5,"eraser"))i-=6,s[i+1]=0;
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^