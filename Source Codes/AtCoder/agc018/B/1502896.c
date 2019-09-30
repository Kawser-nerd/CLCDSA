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
int a[300][300];
int used[300];
int n,m,res=INF;
void dfs(int cnt){
	int b[300],num=0,max,i,j;
	if(cnt==m) return;
	FOR(i,0,m) b[i]=0;
	FOR(i,0,n){
		FOR(j,0,m){
			if(!used[a[i][j]]){
				b[a[i][j]]++;
				break;
			}
		}
	}
	FOR(i,0,m){
		if(num<b[i]){
			num=b[i];
			max=i;
		}
	}
	res=MIN(res,num);
	used[max]=1;
	dfs(cnt+1);
	return;
}
int main(void)
{
	int i,j;
	scanf("%d%d",&n,&m);
	FOR(i,0,n){
		FOR(j,0,m){
			scanf("%d",&a[i][j]);
			a[i][j]--;
		}
	}
	dfs(0);
	printf("%d\n",res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:52:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a[i][j]);
    ^