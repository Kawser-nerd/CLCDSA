#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
ll fact[10001];
int t[10000];
int main(void)
{
	const int MOD=(1e+9)+7;
	int n,i,cnt=0;
	ll penalty=0,res=1;
	fact[1]=1;
	FOR(i,2,10001) fact[i]=fact[i-1]*i%MOD;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d",&t[i]);
	qsort(t,n,sizeof(int),comp);
	FOR(i,0,n){
		penalty+=t[i]*(n-i);
	}
	FOR(i,0,n){
		cnt=1;
		while(t[i]==t[i+1]) cnt++,i++;
		res=res*fact[cnt]%MOD;
	}
	printf("%lld\n%lld\n",penalty,res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:31:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",&t[i]);
             ^