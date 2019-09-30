#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF 100000000
#define FOR(i,a,n) for(i=a;i<n;i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
int a[100000];
ll d[100000];
int main(void)
{
	int n,i;
	ll sum=0,cnt=0,k,t;
	scanf("%d",&n);
	k=(ll)n*(n+1)/2;
	FOR(i,0,n){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(sum%k){
		puts("NO");
		return 0;
	}
	t=sum/k;
	FOR(i,0,n){
		d[i]=a[i]-a[(i+1)%n]+t;
		if(d[i]<0||d[i]%n){
			puts("NO");
			return 0;
		}
		cnt+=d[i]/n;
	}
	if(cnt==t) puts("YES");
	else puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^