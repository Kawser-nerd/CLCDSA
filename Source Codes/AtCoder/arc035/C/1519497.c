#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MIN3(a,b,c) MIN(a,MIN(b,c))
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
int d[400][400];
int main(void)
{
	int n,m,a,b,c,q,i,j,k;
	ll sum;
	scanf("%d%d",&n,&m);
	FOR(i,0,n){
		FOR(j,0,n){
			d[i][j]=INF;
		}
		d[i][i]=0;
	}
	FOR(i,0,m){
		scanf("%d%d%d",&a,&b,&c);
		a--,b--;
		d[a][b]=d[b][a]=c;
	}
	FOR(k,0,n){
		FOR(i,0,n){
			FOR(j,0,n){
				d[i][j]=MIN(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	scanf("%d",&q);
	FOR(i,0,q){
		scanf("%d%d%d",&a,&b,&c);
		a--,b--;
		FOR(j,0,n){
			FOR(k,0,n){
				d[j][k]=MIN3(d[j][k],d[j][a]+d[b][k]+c,d[j][b]+d[a][k]+c);
			}
		}
		sum=0;
		FOR(j,0,n){
			FOR(k,j+1,n){
				sum+=d[j][k];
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^
./Main.c:46:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&q);
  ^
./Main.c:48:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^