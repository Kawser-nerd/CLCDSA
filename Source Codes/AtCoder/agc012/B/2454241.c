#include <stdio.h>
#include <stdlib.h>
#define graph_valtype int

typedef struct {
	int c;
	int t;
}pair;

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

int main(){
	int N, M, a, b, Q, v, d, c, i, j, k;
	scanf("%d%d", &N, &M);
	graph *g = make_graph(N, 0);
	for(i = 0; i < M; i++){
		scanf("%d%d", &a, &b);
		a--;
		b--;
		set_edge_graph(a, b, 1, g);
		set_edge_graph(b, a, 1, g);
	}
	build_graph(g);
	pair **A = (pair **)malloc(sizeof(pair *) * N);
	for(i = 0; i < N; i++){
		A[i] = (pair *)malloc(sizeof(pair) * 11);
		for(j = 0; j <= 10; j++){
			A[i][j].c = 0;
			A[i][j].t = 0;
		}
	}
	scanf("%d", &Q);
	for(i = 1; i <= Q; i++){
		scanf("%d%d%d", &v, &d, &c);
		v--;
		A[v][d].c = c;
		A[v][d].t = i;
	}
	graph_vertex *nowv;
	for(k = 0; k <= 10; k++){
		for(i = 0; i < N; i++){
			nowv = g->v[i];
			for(j = 0; j < nowv->next_num; j++){
				for(d = 0; d < 10; d++){
					if(A[nowv->num][d].t < A[nowv->next[j]->num][d + 1].t){
						A[nowv->num][d] = A[nowv->next[j]->num][d + 1];
					}
				}
			}
		}
	}
	int thent, ans;
	for(i = 0; i < N; i++){
		thent = -1;
		for(d = 0; d <= 10; d++){
			if(thent < A[i][d].t){
				thent = A[i][d].t;
				ans = A[i][d].c;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:109:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:112:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^
./Main.c:127:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &Q);
  ^
./Main.c:129:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &v, &d, &c);
   ^