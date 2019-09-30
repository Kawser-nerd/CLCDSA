#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 10000000000LL
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(ll*)a>*(ll*)b?1:-1;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int main(void)
{
	ll s[3],w,h,i;
	ll res=INF;
	scanf("%lld%lld",&h,&w);
	FOR(i,1,h){
		s[0]=i*w;
		s[1]=MAX((h-i)/2*w,(h-i)*(w/2));
		s[2]=h*w-s[0]-s[1];
		qsort(s,3,sizeof(ll),comp);
		res=MIN(res,s[2]-s[0]);
	}
	swap(ll,h,w);
	FOR(i,1,h){
		s[0]=i*w;
		s[1]=MAX((h-i)/2*w,(h-i)*(w/2));
		s[2]=h*w-s[0]-s[1];
		qsort(s,3,sizeof(ll),comp);
		res=MIN(res,s[2]-s[0]);
	}
	printf("%lld",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&h,&w);
  ^