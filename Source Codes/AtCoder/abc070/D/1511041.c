#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define INF (1e+18)
#define FOR(i,a,n) for(i=(a);i<(n);i++)
int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
void fill(int a[],int b,int c){
	int i;
	FOR(i,0,b) a[i]=c;
	return;
}
typedef struct LIST{
	int to,cost;
	struct LIST *next;
}Edge;
Edge** init(int v){
	Edge **edge=(Edge**)calloc(v,sizeof(Edge*));
	return edge;
}
void add_edge(Edge **edge,int s,int t,int c){
	Edge *tmp=(Edge*)malloc(sizeof(Edge));
	tmp->to=t,tmp->cost=c;
	tmp->next=edge[s];
	edge[s]=tmp;
	return;
}
void delete_edge(Edge **edge,int v){
	int i;
	Edge *e,*tmp;
	FOR(i,0,v){
		e=edge[i];
		while(e!=NULL){
			tmp=e->next;
			free(e);
			e=tmp;
		}
	}
	return;
}
ll d[100000];
Edge **edge;
void dfs(int v,ll dist){
	d[v]=dist;
	for(Edge *e=edge[v];e!=NULL;e=e->next){
		if(d[e->to]==INF) dfs(e->to,dist+e->cost);
	}
	return;
}
int main(void)
{
	int n,a,b,c,q,k,i;
	scanf("%d",&n);
	edge=init(n);
	FOR(i,0,n-1){
		scanf("%d%d%d",&a,&b,&c);
		a--,b--;
		add_edge(edge,a,b,c);
		add_edge(edge,b,a,c);
	}
	FOR(i,0,n) d[i]=INF;
	scanf("%d%d",&q,&k);
	dfs(--k,0LL);
	FOR(i,0,q){
		scanf("%d%d",&a,&b);
		printf("%lld\n",d[--a]+d[--b]);
	}
	delete_edge(edge,n);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:60:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:63:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^
./Main.c:69:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&q,&k);
  ^
./Main.c:72:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^