#include <stdio.h>
#include <stdlib.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define INF 1000000000
typedef struct LIST{
	int to;
	struct LIST *next;
}Edge;
Edge** init(int v){
	Edge **edge=(Edge**)calloc(v,sizeof(Edge*));
	return edge;
}
void add_edge(Edge **edge,int s,int t){
	Edge *tmp=(Edge*)malloc(sizeof(Edge));
	tmp->to=t;
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
Edge **edge;
int color[100000];
int num[100000];
void dfs(int v,int d,int c){
	Edge *e;
	num[v]=d;
	if(color[v]==0) color[v]=c;
	for(e=edge[v];e!=NULL;e=e->next){
		if(num[e->to]<d-1)dfs(e->to,d-1,c);
	}
	return;
}
int v[100000],d[100000],c[100000];
int main(void)
{
	int n,m,q,a,b,i;
	scanf("%d%d",&n,&m);
	edge=init(n);
	FOR(i,0,m){
		scanf("%d%d",&a,&b);
		add_edge(edge,--a,--b);
		add_edge(edge,b,a);
	}
	scanf("%d",&q);
	FOR(i,0,q){
		scanf("%d%d%d",&v[i],&d[i],&c[i]);
		v[i]--;
	}
	FOR(i,0,n) num[i]=-1;
	for(i=q-1;i>=0;i--) dfs(v[i],d[i],c[i]);
	FOR(i,0,n) printf("%d\n",color[i]);
	delete_edge(edge,n);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:53:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^
./Main.c:57:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&q);
  ^
./Main.c:59:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&v[i],&d[i],&c[i]);
   ^