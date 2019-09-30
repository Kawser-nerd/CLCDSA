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
int upper_bound(ll a[],int n,ll k){
	int left=-1; int right=n;
	while(right-left>1){
		int mid=(left+right)/2;
		if(a[mid]<=k) left=mid;
		else right=mid;
	}
	return right;
}
ll a[30000],b[30000];
int n,k;
int check(ll t){
	int cnt=0,i;
	FOR(i,0,n){
		cnt+=upper_bound(a,n,t/b[i]);
	}
	return cnt>=k;
}
int main(void)
{
	int i;
	ll l=0,r=1e+18,mid;
	scanf("%d%d",&n,&k);
	FOR(i,0,n) scanf("%lld",&a[i]);
	FOR(i,0,n) scanf("%lld",&b[i]);
	qsort(a,n,sizeof(ll),comp);
	while(r>l){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:43:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%lld",&a[i]);
             ^
./Main.c:44:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%lld",&b[i]);
             ^