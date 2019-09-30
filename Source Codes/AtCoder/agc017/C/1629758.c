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
int a[200000];
int b[200001];
int cnt[200001];
int main(void)
{
	int n,m,sum=0,x,y,t1,t2,i,j;
	scanf("%d%d",&n,&m);
	FOR(i,0,n){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	FOR(i,1,n+1){
		b[MAX(0,i-cnt[i])]++;
		b[i]--;
	}
	FOR(i,1,n) b[i]+=b[i-1];
	FOR(i,0,n) sum+=(b[i]==0);
	//FOR(i,0,n) printf("%d ",b[i]);
	FOR(i,0,m){
		scanf("%d %d",&x,&y);
		x--;
		t1=a[x]-cnt[a[x]];
		if(t1>=0&&--b[t1]==0) sum++;
		cnt[a[x]]--;
		
		t2=y-cnt[y]-1;
		if(t2>=0&&++b[t2]==1) sum--;
		cnt[y]++;
		
		printf("%d\n",sum);
		a[x]=y;
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&x,&y);
   ^