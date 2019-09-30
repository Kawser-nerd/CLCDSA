#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 2000000000
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int n,a,b;
int h[100000];
int check(ll t){
	int i,d=a-b;
	ll k=b*t;
	FOR(i,0,n){
		if(h[i]>k){
			t-=((h[i]-k+d-1)/d);
		}
	}
	return t>=0;
}
int main(void)
{
	int i;
	ll l=0,r=INF,mid;
	scanf("%d%d%d",&n,&a,&b);
	FOR(i,0,n) scanf("%d",&h[i]);
	FOR(i,0,100){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%lld\n",r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&a,&b);
  ^
./Main.c:36:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  FOR(i,0,n) scanf("%d",&h[i]);
             ^