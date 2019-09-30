#include <stdio.h>
#include <stdlib.h>
#define graph_valtype int

typedef struct {
	int a;
	int b;
	int w;
}edge;

typedef struct graph_edge_sub graph_edge;

typedef struct {
	int num;
	int next_num;
	graph_edge *next;
	int prev_num;
}graph_vertex_sub;

struct graph_edge_sub{
	graph_vertex_sub *v;
	int w;
	graph_edge *next;
};

typedef struct graph_v_sub graph_vertex;

struct graph_v_sub{
	int num;
	graph_valtype val;
	int next_num;
	graph_vertex **next;
	int *next_weight;
	int prev_num;
	graph_vertex **prev;
	int *prev_weight;
};

typedef struct {
	int N;
	graph_vertex_sub **v_s;
	graph_vertex **v;
}graph;

//???N, ???????ini_val???????
graph *make_graph(int N, graph_valtype ini_val){
	int i;
	graph *g = (graph *)malloc(sizeof(graph));
	g->N = N;
	g->v_s = (graph_vertex_sub **)malloc(sizeof(graph_vertex_sub *) * N);
	g->v = (graph_vertex **)malloc(sizeof(graph_vertex *) * N);
	for(i = 0; i < N; i++){
		(g->v_s)[i] = (graph_vertex_sub *)malloc(sizeof(graph_vertex_sub));
		(g->v_s)[i]->num = i;
		(g->v_s)[i]->next_num = 0;
		(g->v_s)[i]->next = NULL;
		(g->v_s)[i]->prev_num = 0;
		(g->v)[i] = (graph_vertex *)malloc(sizeof(graph_vertex));
		(g->v)[i]->num = i;
		(g->v)[i]->val = ini_val;
		(g->v)[i]->next_num = 0;
		(g->v)[i]->next = NULL;
		(g->v)[i]->next_weight = NULL;
		(g->v)[i]->prev_num = 0;
		(g->v)[i]->prev = NULL;
		(g->v)[i]->prev_weight = NULL;
	}
	return g;
}

//???g???a????b???w??????? (0 <= a, b <= N - 1)
void set_edge_graph(int a, int b, int w, graph *g){
	graph_edge *new1 = (graph_edge *)malloc(sizeof(graph_edge));
	new1->v = (g->v_s)[b];
	new1->w = w;
	new1->next = (g->v_s)[a]->next;
	(g->v_s)[a]->next = new1;
	(g->v_s)[a]->next_num++;
	(g->v_s)[b]->prev_num++;
}

//set_edge_graph??????
void build_graph(graph *g){
	int i;
	graph_vertex_sub **v_s = g->v_s;
	graph_vertex **v = g->v;
	graph_vertex *nowv;
	graph_edge *nowe;
	for(i = 0; i < g->N; i++){
		v[i]->next = (graph_vertex **)malloc(sizeof(graph_vertex *) * v_s[i]->next_num);
		v[i]->next_weight = (int *)malloc(sizeof(int) * v_s[i]->next_num);
		v[i]->prev = (graph_vertex **)malloc(sizeof(graph_vertex *) * v_s[i]->prev_num);
		v[i]->prev_weight = (int *)malloc(sizeof(int) * v_s[i]->prev_num);
	}
	for(i = 0; i < g->N; i++){
		nowv = v[i];
		for(nowe = v_s[i]->next; nowe != NULL; nowe = nowe->next){
			(nowv->next)[nowv->next_num] = v[nowe->v->num];
			(nowv->next_weight)[nowv->next_num] = nowe->w;
			nowv->next_num++;
			(v[nowe->v->num]->prev)[v[nowe->v->num]->prev_num] = nowv;
			(v[nowe->v->num]->prev_weight)[v[nowe->v->num]->prev_num] = nowe->w;
			v[nowe->v->num]->prev_num++;
		}
	}
}

char *s;
int *is_used;
graph *g;

int solve(int a, int b, int w){
	int i;
	if(is_used[w] > 0){
		return 2 - is_used[w];
	}
	is_used[w] = 1;
	graph_vertex *nowv = g->v[b];
	for(i = 0; i < nowv->next_num; i++){
		if(s[a] != s[nowv->next[i]->num]){
			if(solve(b, nowv->next[i]->num, nowv->next_weight[i]) == 1){
				return 1;
			}
		}
	}
	is_used[w] = 2;
	return 0;
}

int main(){
	int N, M, a, b, i, j, k;
	scanf("%d%d", &N, &M);
	s = (char *)malloc(sizeof(char) * N);
	scanf("%s", s);
	edge *es = (edge *)malloc(sizeof(edge) * 2 * M);
	g = make_graph(N, 0);
	for(i = 0; i < M; i++){
		scanf("%d%d", &a, &b);
		es[2 * i].a = a - 1;
		es[2 * i].b = b - 1;
		es[2 * i + 1].a = b - 1;
		es[2 * i + 1].b = a - 1;
		set_edge_graph(a - 1, b - 1, 2 * i, g);
		set_edge_graph(b - 1, a - 1, 2 * i + 1, g);
	}
	build_graph(g);
	is_used = (int *)malloc(sizeof(int) * 2 * M);
	for(i = 0; i < 2 * M; i++){
		is_used[i] = 0;
	}
	for(i = 0; i < 2 * M; i++){
		if(solve(es[i].a, es[i].b, i) == 1){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:132:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:134:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:138:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^