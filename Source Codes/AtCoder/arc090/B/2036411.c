#include <stdio.h>
#include <stdlib.h>
#define graph_valtype int
#define stack_valtype int

typedef struct stack_node_sub{
	stack_valtype val;
	struct stack_node_sub *next;
}stack_node;

typedef struct {
	stack_node *fst;
	int num;
}stack;

stack *make_stack(){
	stack *s = (stack *)malloc(sizeof(stack));
	s->fst = NULL;
	s->num = 0;
	return s;
}

int element_num_stack(stack *s){
	return s->num;
}

void add_data_stack(stack_valtype val, stack *s){
	stack_node *fst = (stack_node *)malloc(sizeof(stack_node));
	fst->val = val;
	fst->next = s->fst;
	s->fst = fst;
	s->num++;
}

stack_valtype take_data_stack(stack *s){
	if(s->num == 0){
		printf("no data in the stack\n");
	}
	stack_valtype ans = s->fst->val;
	stack_node *fst = s->fst;
	s->fst = fst->next;
	free(fst);
	s->num--;
	return ans;
}

stack_valtype look_data_stack(stack *s){
	if(s->num == 0){
		printf("no data in the stack\n");
	}
	else{
		return s->fst->val;
	}
}

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
	int N, M, L, R, D, i;
	scanf("%d%d", &N, &M);
	graph *g = make_graph(N, 0);
	for(i = 0; i < M; i++){
		scanf("%d%d%d", &L, &R, &D);
		L--;
		R--;
		set_edge_graph(L, R, D, g);
		set_edge_graph(R, L, -D, g);
	}
	build_graph(g);
	int *is_used = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		is_used[i] = 0;
	}
	is_used[0] = 1;
	stack *s = make_stack();
	int not_arrive_next = 0, nextv;
	graph_vertex *nowv;
	add_data_stack(0, s);
	while(not_arrive_next < N){
		if(element_num_stack(s) == 0){
			while(is_used[not_arrive_next] == 1){
				not_arrive_next++;
				if(not_arrive_next >= N){
					break;
				}
			}
			if(not_arrive_next < N){
				add_data_stack(not_arrive_next, s);
				is_used[not_arrive_next] = 1;
			}
		}
		else{
			nowv = g->v[take_data_stack(s)];
			for(i = 0; i < nowv->next_num; i++){
				nextv = nowv->next[i]->num;
				if(is_used[nextv] == 0){
					g->v[nextv]->val = nowv->val + nowv->next_weight[i];
					add_data_stack(nextv, s);
					is_used[nextv] = 1;
				}
				else{
					if(g->v[nextv]->val != nowv->val + nowv->next_weight[i]){
						printf("No\n");
						return 0;
					}
				}
			}
		}
	}
	printf("Yes\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:155:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:158:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &L, &R, &D);
   ^