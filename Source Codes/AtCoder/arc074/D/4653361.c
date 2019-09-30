#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int32_t flow_type;

const flow_type flow_inf=200;

typedef struct flow_edge{
  int vertex;
  int next;
  flow_type capacity;
} flow_edge;

typedef struct maxFlowGraph{
  flow_edge *edge;
  int *start;
  int vertex_num;
  int pointer;
  int edge_length;
} graph;

graph* newGraph(const int vertex_num){
  graph *g=(graph *)calloc(1,sizeof(graph));
  g->vertex_num=vertex_num;
  const int initial_length=4;
  g->edge=(flow_edge *)calloc(initial_length,sizeof(flow_edge));
  g->start=(int *)calloc(vertex_num,sizeof(int));
  g->pointer=0;
  g->edge_length=initial_length;
  for(int i=0;i<vertex_num;i++) g->start[i]=-1;
  return g;
}

void freeGraph(graph *g){
  free(g->edge);
  free(g->start);
  free(g);
}

void addEdge(graph *g,int from,int to,flow_type capa){
  if(g->pointer==g->edge_length){
    g->edge_length*=2;
    g->edge=(flow_edge *)realloc(g->edge,sizeof(flow_edge)*g->edge_length);
  }
  int p=g->pointer;
  g->edge[p]=(flow_edge){to,g->start[from],capa};
  g->start[from]=p;
  g->edge[p+1]=(flow_edge){from,g->start[to],0};
  g->start[to]=p+1;
  g->pointer+=2;
}

flow_type dinic_dfs(int v,graph *g,int dst,int *level,int *iter,flow_type e){
  if(v==dst) return e;
  flow_type sum=0;
  for(int p=iter[v];p!=-1 && e>0;p=g->edge[p].next,iter[v]=p){
    int u=g->edge[p].vertex;
    flow_type capa=g->edge[p].capacity;
    if(level[u]<=level[v] || capa<=0) continue;
    flow_type f=dinic_dfs(u,g,dst,level,iter,capa<e?capa:e);
    if(f>0){
      g->edge[p].capacity-=f;
      g->edge[p^1].capacity+=f;
      sum+=f;
      e-=f;
      if(e<=0) return sum;
    }
  }
  return sum;
}

flow_type dinic(const graph *input_graph,const int src,const int dst){
  const int vertex_num=input_graph->vertex_num;
  const int edge_num=input_graph->pointer;
  graph *g=(graph *)calloc(1,sizeof(graph));
  g->edge=(flow_edge *)malloc(sizeof(flow_edge)*edge_num);
  g->start=(int *)malloc(sizeof(int)*vertex_num);
  memcpy(g->edge,input_graph->edge,sizeof(flow_edge)*edge_num);
  memcpy(g->start,input_graph->start,sizeof(int)*vertex_num);
  int *level=(int *)calloc(vertex_num,sizeof(int));
  int *queue=(int *)calloc(vertex_num,sizeof(int));
  int *iter=(int *)calloc(vertex_num,sizeof(int));
  flow_type flow=0;
  while(1){
    memset(level,0,sizeof(int)*vertex_num);
    int front=0,last=0;
    level[src]=1;
    queue[last++]=src;
    while(front<last && level[dst]==0){
      const int v=queue[front++];
      for(int p=g->start[v];p!=-1;p=g->edge[p].next){
	int u=g->edge[p].vertex;
	if(g->edge[p].capacity>0 && level[u]==0){
	  level[u]=level[v]+1;
	  queue[last++]=u;
	}
      }
    }
    if(level[dst]==0) break;
    memcpy(iter,g->start,sizeof(int)*vertex_num);
    while(1){
      flow_type f=dinic_dfs(src,g,dst,level,iter,flow_inf);
      if(f<=0) break;
      flow+=f;
    }
  }
  freeGraph(g);
  free(level);
  free(queue);
  free(iter);
  return flow;
}

void run(void){
  int h,w;
  scanf("%d%d",&h,&w);
  char *s = (char *)calloc(h * w + 1, sizeof(char));
  int i,j;
  for(i = 0; i < h; i++) scanf("%s",s + i * w);
  graph *g = newGraph(h + w + 2);
  const int src = h + w;
  const int dst = h + w +1;
  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      if(s[i * w + j] == 'S'){
	addEdge(g, src, i + w, flow_inf);
	addEdge(g, src, j, flow_inf);
      }
      if(s[i * w + j] == 'T'){
	addEdge(g, i + w, dst, flow_inf);
	addEdge(g, j, dst, flow_inf);
      }
      if(s[i * w + j] != '.'){
	addEdge(g, i + w, j, 1);
	addEdge(g, j, i + w, 1);
      }
    }
  }
  int ans = dinic(g, src, dst);
  printf("%d\n",ans >= flow_inf ? -1 : ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:119:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:122:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i = 0; i < h; i++) scanf("%s",s + i * w);
                          ^