#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
ll power(ll x,ll n,ll mod){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int a[100001];
int main(void)
{
	int n,t,i;
	ll mod=(1e+9)+7;
	scanf("%d",&n);
	FOR(i,0,n){
		scanf("%d",&t);
		a[t]++;
	}
	if(n%2&&a[0]!=1) puts("0");
	else{
		for(i=n%2+1;i<n;i+=2){
			if(a[i]!=2){
				puts("0");
				return 0;
			}
		}
		printf("%lld\n",power(2LL,(ll)n/2,mod));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^