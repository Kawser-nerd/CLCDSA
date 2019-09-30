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
int map[100][100];
int sum[100][100];
int main(void)
{
	int h,w,ans=0,t,i,j,k,l;
	scanf("%d%d",&h,&w);
	FOR(i,0,h){
		FOR(j,0,w){
			scanf("%d",&map[i][j]);
			if(i%2==j%2) map[i][j]=-map[i][j];
		}
	}
	FOR(i,0,h){
		FOR(j,0,w){
			sum[i][j]=map[i][j];
			if(i>0) sum[i][j]+=sum[i-1][j];
			if(j>0) sum[i][j]+=sum[i][j-1];
			if(i>0&&j>0) sum[i][j]-=sum[i-1][j-1];
		}
	}
	FOR(i,0,h){
		FOR(j,0,w){
			FOR(k,i,h){
				FOR(l,j,w){
					t=sum[k][l];
					if(i>0) t-=sum[i-1][l];
					if(j>0) t-=sum[k][j-1];
					if(i>0&&j>0) t+=sum[i-1][j-1];
					if(t==0) ans=MAX(ans,(k-i+1)*(l-j+1));
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:26:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&map[i][j]);
    ^