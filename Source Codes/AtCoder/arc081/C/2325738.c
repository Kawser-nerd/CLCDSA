#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define bit(n,m)((n>>m)&1)

char s[200010];
ll a[10000][30];//????
ll b[10000][30];//???
int main(){
	scanf("%s",s);
	ll n=strlen(s);
	
	ll c=0,ss=0;
	for(int i=n-1;i>=0;i--){
		int t=s[i]-'a';
		if(!bit(ss,t)){
			ss|=1<<t;
			a[c][t]=i+1;
		}
		b[c][t]=i+1;
		if(ss==((1<<26)-1)){
			c++;
			ss=0;
		}
	}

	ll p=0;
	for(;c>=0;c--){
		rep(i,0,26)if(a[c][i]<=p){
			putchar(i+'a');
			if(c)p=b[c-1][i];
			break;
		}
	}
	puts("");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^