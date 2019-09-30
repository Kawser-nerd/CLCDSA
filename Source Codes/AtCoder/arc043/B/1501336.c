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
int binary_upper(int a[],int n,int k){
	int left=-1; int right=n;
	while(right-left>1){
		int mid=(left+right)/2;
		if(a[mid]<=k) left=mid;
		else right=mid;
	}
	return left;
}
int a[100000];
int dp[100000][4];
int main(void)
{
	int n,k,i,j;
	const int MOD=(1e+9)+7;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),comp);
	FOR(i,0,n) dp[i][0]=i+1;
	FOR(i,1,n){
		k=binary_upper(a,n,a[i]/2);
		FOR(j,1,4){
			dp[i][j]=dp[i-1][j];
			if(k>=0) dp[i][j]+=dp[k][j-1];
			dp[i][j]%=MOD;
		}
	}
	printf("%d\n",dp[n-1][3]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:36:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",&a[i]);
             ^