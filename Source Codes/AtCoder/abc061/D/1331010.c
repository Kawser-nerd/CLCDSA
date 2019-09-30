#include <stdio.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
#define INF 10000000000000LL
#define ll long long

typedef struct{
	int from;
	int to;
	int cost;
} Edge;
Edge edge[2000];
ll d[1000];
int neg[1000];
int main(void)
{
	int m,n,flag,i,j;
	Edge e;
	scanf("%d%d",&n,&m);
	FOR(i,0,n) d[i]=INF;
	FOR(i,0,m){
		scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].cost);
		edge[i].from--;
		edge[i].to--;
		edge[i].cost*=-1;
	}
	d[0]=0;
	FOR(i,0,2*n){
		flag=0;
		FOR(j,0,m){
			e=edge[j];
			if(d[e.from]==INF) continue;
			if(d[e.to]>d[e.from]+e.cost){
				d[e.to]=d[e.from]+e.cost;
				if(e.to==n-1) flag=1;
			}
		}
		if(i>=n-1&&flag){
			puts("inf");
			return 0;
		}
	}
	printf("%lld\n",-d[n-1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].cost);
   ^