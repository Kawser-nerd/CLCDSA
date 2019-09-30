#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int c(const void*a,const void*b){return strcmp((char*)a,(char*)b);}

ll n;
char s[110][110];
int main(){
	scanf("%lld%*lld",&n);
	rep(i,0,n)scanf("%s",s[i]);
	qsort(s,n,110,c);
	rep(i,0,n)printf("%s",s[i]);
} ./Main.c: In function ‘main’:
./Main.c:14:8: warning: use of assignment suppression and length modifier together in gnu_scanf format [-Wformat=]
  scanf("%lld%*lld",&n);
        ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%*lld",&n);
  ^
./Main.c:15:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%s",s[i]);
            ^