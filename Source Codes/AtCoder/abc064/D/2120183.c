#include<stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

int main(){
	int n;
	char s[110];
	scanf("%d%s",&n,s);
	int m=0,t=0;
	rep(i,0,n){
		if(s[i]==')')t++;
		else t--;
		m=max(m,t);
	}
	rep(i,0,m)putchar('(');
	printf("%s",s);
	rep(i,0,m-t)putchar(')');
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%s",&n,s);
  ^