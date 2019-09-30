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
int a[5000];
int dp[5000];
int n,k;
int check(int x){
	int i,j;
	if(a[x]>=k) return 1;
	FOR(i,1,k) dp[i]=0;
	dp[0]=1;
	FOR(i,0,n){
		if(i!=x&&a[i]<k){
			for(j=k-a[i];j>=0;j--){
				if(dp[j]) dp[j+a[i]]=1;
			}
		}
	}
	FOR(i,k-a[x],k){
		if(dp[i]) return 1;
	}
	return 0;
}
int main(void)
{
	int i,l,r,mid;
	scanf("%d%d",&n,&k);
	FOR(i,0,n) scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),comp);
	l=-1,r=n;
	while(r-l>1){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",l+1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:43:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:44:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",&a[i]);
             ^