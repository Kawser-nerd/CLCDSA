#include <stdio.h>
#include <stdlib.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	for(int i=0;i<b;i++) a[i]=c;
	return;
}
int main(void)
{
	int n,t,i,k;
	int start;
	ll ans=0;
	scanf("%d %d",&n,&t);
	FOR(i,0,n){
		scanf("%d",&k);
		if(i!=0){
			if(start+t<k) ans+=t;
			else ans+=(k-start);
		}
		start=k;
	}
	printf("%lld\n",ans+t);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&t);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^