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
#define MOD 1000000007
#define SIZE 100005
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
int lower_bound(int a[],int n,int k){
	int left=-1; int right=n;
	while(right-left>1){
		int mid=(left+right)/2;
		if(a[mid]<=k) left=mid;
		else right=mid;
	}
	return right;
}
int a[100000],b[100000],c[100000];
ll cnt[100001];
int main(void)
{
	int n,id,i;
	ll res=0;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d",a+i);
	FOR(i,0,n) scanf("%d",b+i);
	FOR(i,0,n) scanf("%d",c+i);
	qsort(a,n,sizeof(int),comp);
	qsort(b,n,sizeof(int),comp);
	qsort(c,n,sizeof(int),comp);
	FOR(i,0,n){
		cnt[i]=n-lower_bound(c,n,b[i]);
	}
	for(i=n-2;i>=0;i--) cnt[i]+=cnt[i+1];
	FOR(i,0,n){
		id=lower_bound(b,n,a[i]);
		res+=cnt[id];
	}
	printf("%lld\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:34:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",a+i);
             ^
./Main.c:35:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",b+i);
             ^
./Main.c:36:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",c+i);
             ^