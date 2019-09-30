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
int a[2000];
int b[2000];
int main(void)
{
	int i,j;
	ll n,x,k,ans=0;
	scanf("%lld%lld",&n,&x);
	FOR(i,0,n){
		scanf("%d",&a[i]);
		b[i]=a[i];
		ans+=a[i];
	}
	FOR(i,1,n){
		k=x*i;
		FOR(j,0,n){
			b[j]=MIN(b[j],a[(j-i+n)%n]);
			k+=b[j];
		}
		ans=MIN(ans,k);
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function �main�:
./Main.c:26:2: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&x);
  ^
./Main.c:28:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^