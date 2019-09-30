#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define MOD 1000000007
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
ll calc(int t){
	ll res=1;
	while(t>1){
		res=res*(t--)%MOD;
	}
	return res;
}
int main(void)
{
	int n,m,i;
	ll t,x,y,z;
	scanf("%d%d",&n,&m);
	if(n<m) swap(int,n,m);
	if(n>m+1){
		puts("0");
		return 0;
	}
	if(n==m+1) printf("%lld\n",calc(n)*calc(m)%MOD);
	else printf("%lld\n",calc(n)*calc(m)*2%MOD);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^