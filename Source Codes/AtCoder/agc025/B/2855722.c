#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#define FOR(i,a,n) for(i=(a);i<(n);i++)
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define MOD 998244353
#define SIZE 300005
#define LOCAL
#ifdef LOCAL
    #define DEBUG(...) printf(" "__VA_ARGS__)
#else
    #define DEBUG(...)
#endif /* LOCAL */
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
ll inv[SIZE],f[SIZE],finv[SIZE];
void make_table(){
	int i;
	f[0]=f[1]=1; finv[0]=finv[1]=1;
	inv[1]=1;
	FOR(i,2,SIZE){
		inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
		f[i]=(f[i-1]*(ll)i)%MOD;
		finv[i]=(finv[i-1]*inv[i])%MOD;
	}
	return;
}
ll comb(int n,int k){
	if(n<0||k<0||n<k) return 0;
	return (((f[n]*finv[k])%MOD)*finv[n-k])%MOD;
}

int main(void)
{
	int n,a,b,i;
	ll k,s,t,res=0;
	make_table();
	scanf("%d%d%d%lld",&n,&a,&b,&k);
	FOR(i,0,n+1){
		s=k-(ll)a*i;
		if(s%b==0&&s/b<=n){
			t=comb(n,i)*comb(n,s/b)%MOD;
			res=(res+t)%MOD;
		}
	}
	printf("%lld\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%lld",&n,&a,&b,&k);
  ^