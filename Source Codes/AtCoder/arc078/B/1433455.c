#include <stdio.h>
#include <stdlib.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
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
int used[100000];
Edge **edge;
void dfs(int d[],int v,int k){
	Edge *e;
	d[v]=k; used[v]=1;
	for(e=edge[v];e!=NULL;e=e->next){
		if(!used[e->to]) dfs(d,e->to,k+1);
	}
	return;
}
int d1[100000],d2[100000];
int main(void)
{
	int n,a,b,cnt=0,i;
	scanf("%d",&n);
	edge=init(n);
	FOR(i,0,n-1){
		scanf("%d%d",&a,&b);
		add_edge(edge,--a,--b);
		add_edge(edge,b,a);
	}
	dfs(d1,0,0);
	FOR(i,0,n) used[i]=0;
	dfs(d2,n-1,0);
	FOR(i,0,n) if(d1[i]<=d2[i]) cnt++;
	printf("%s",cnt>n/2?"Fennec":"Snuke");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^