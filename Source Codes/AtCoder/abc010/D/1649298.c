#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
#define swap(type,a,b) do{type t=a;a=b;b=t;}while(0);
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define INF 1000000000
#define MAX_V 105
#define MAX_E 20000
typedef struct LIST{
	int to,cap;
	struct LIST *rev; //???????
	struct LIST *next;
}Edge;
Edge *g[MAX_V],*iter[MAX_V];
Edge edge[MAX_E],rev[MAX_E];
int level[MAX_V];
int que[MAX_V];
int e_size=0;
void add_edge(int s,int t,int c){
	edge[e_size].next=g[s]; g[s]=&edge[e_size];
	rev[e_size].next=g[t]; g[t]=&rev[e_size++];
	g[s]->to=t,g[s]->cap=c;
	g[t]->to=s,g[t]->cap=0;
	g[s]->rev=g[t]; g[t]->rev=g[s];
	return;
}
void bfs(int s){
	int front=0,rear=0,v;
	Edge *e;
	memset(level,-1,sizeof(level));
	level[s]=0;
	que[rear++]=s;
	while(front!=rear){
		v=que[front++];
		for(e=g[v];e!=NULL;e=e->next){
			if(e->cap>0&&level[e->to]<0){
				level[e->to]=level[v]+1;
				que[rear++]=e->to;
			}
		}
	}
	return;
}
int dfs(int v,int t,int f){
	int d; Edge *e;
	if(v==t) return f;
	for(;iter[v]!=NULL;iter[v]=iter[v]->next){
		e=iter[v];
		if(e->cap>0&&level[v]<level[e->to]){
			d=dfs(e->to,t,MIN(f,e->cap));
			if(d>0){
				e->cap-=d;
				e->rev->cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0,f;
	while(1){
		bfs(s);
		if(level[t]<0) return flow;
		memcpy(iter,g,sizeof(g));
		while((f=dfs(s,t,INF))>0) flow+=f;
	}
}
int main(void)
{
	int n,g,e,s,t,a,b,i;
	scanf("%d%d%d",&n,&g,&e);
	s=0,t=n;
	FOR(i,0,g){
		scanf("%d",&a);
		add_edge(a,t,1);
	}
	FOR(i,0,e){
		scanf("%d%d",&a,&b);
		add_edge(a,b,1);
		add_edge(b,a,1);
	}
	printf("%d\n",max_flow(s,t));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:74:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&g,&e);
  ^
./Main.c:77:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:81:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^