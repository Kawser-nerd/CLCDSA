#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define NUM 20001
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
ll a[100000],b[100000];
int main(void)
{
	int n,i;
	ll res=0,k;
	scanf("%d",&n);
	FOR(i,0,n) scanf("%lld%lld",&a[i],&b[i]);
	for(i=n-1;i>=0;i--){
		a[i]+=res;
		k=(a[i]+b[i]-1)/b[i];
		res+=b[i]*k-a[i];
	}
	printf("%lld\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:25:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%lld%lld",&a[i],&b[i]);
             ^