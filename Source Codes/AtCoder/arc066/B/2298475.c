#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define bit(n,m)((n>>m)&1)

#define M 1000000007
//a^b=x,a+b=y,a|b=b???(a,b)?(x,y)?1?1??????(a,b)??????????
//dp[????][a^b?(n mod 2**keta)???][a+b>=2**keta?][(a+b mod 2**keta)?(n mod 2**keta)???]
ll dp[99][2][2][2];
int main(){
	ll n;
	scanf("%lld",&n);
	dp[0][1][0][1]=1;
	rep(keta,0,62){
		rep(p,0,2)rep(q,0,2)rep(r,0,2){
			//0a,0b???0x,(0+?????)y
			dp[keta+1][p||bit(n,keta)][0][(q^r)?r:bit(n,keta)]+=dp[keta][p][q][r];
			//0a,1b???1x,(1+?????)y
			dp[keta+1][p&&bit(n,keta)][q][(q^r)?bit(n,keta):r]+=dp[keta][p][q][r];
			//1a,1b???0x,1(?????)y
			dp[keta+1][p||bit(n,keta)][1][(q^r)?r:bit(n,keta)]+=dp[keta][p][q][r];
		}
		rep(p,0,2)rep(q,0,2)rep(r,0,2)dp[keta+1][p][q][r]%=M;
	}
	printf("%lld\n",dp[62][1][0][1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^