#include <stdio.h>
#include <stdlib.h>
#define deque_valtype pair
#define graph_valtype int
#define inf (int)(1e9)

typedef struct {
	int v_num;
	int dis;
}pair;

typedef struct edge_sub edge;

typedef struct {
	int num;
	int next_num;
	edge *next;
	int prev_num;
}vertex_sub;

struct edge_sub{
	vertex_sub *v;
	int w;
	edge *next;
};

typedef struct v_sub vertex;

struct v_sub{
	int num;
	graph_valtype val;
	int next_num;
	vertex **next;
	int *next_weight;
	int prev_num;
	vertex **prev;
	int *prev_weight;
};

typedef struct {
	int N;
	vertex_sub **v_s;
	vertex **v;
}graph;

//???N, ???????ini_val???????
graph *make_graph(int N, graph_valtype ini_val){
	int i;
	graph *g = (graph *)malloc(sizeof(graph));
	g->N = N;
	g->v_s = (vertex_sub **)malloc(sizeof(vertex_sub *) * N);
	g->v = (vertex **)malloc(sizeof(vertex *) * N);
	for(i = 0; i < N; i++){
		(g->v_s)[i] = (vertex_sub *)malloc(sizeof(vertex_sub));
		(g->v_s)[i]->num = i;
		(g->v_s)[i]->next_num = 0;
		(g->v_s)[i]->next = NULL;
		(g->v_s)[i]->prev_num = 0;
		(g->v)[i] = (vertex *)malloc(sizeof(vertex));
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
void set_edge(graph *g, int a, int b, int w){
	edge *new1 = (edge *)malloc(sizeof(edge));
	new1->v = (g->v_s)[b];
	new1->w = w;
	new1->next = (g->v_s)[a]->next;
	(g->v_s)[a]->next = new1;
	(g->v_s)[a]->next_num++;
	(g->v_s)[b]->prev_num++;
}

//set_edge??????
void build_graph(graph *g){
	int i;
	vertex_sub **v_s = g->v_s;
	vertex **v = g->v;
	vertex *nowv;
	edge *nowe;
	for(i = 0; i < g->N; i++){
		v[i]->next = (vertex **)malloc(sizeof(vertex *) * v_s[i]->next_num);
		v[i]->next_weight = (int *)malloc(sizeof(int) * v_s[i]->next_num);
		v[i]->prev = (vertex **)malloc(sizeof(vertex *) * v_s[i]->prev_num);
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

typedef struct dq_node_sub{
	deque_valtype val;
	struct dq_node_sub *prev;
	struct dq_node_sub *next;
}dq_node;

typedef struct {
	int N;
	dq_node *first;
	dq_node *last;
}deque;

deque *make_deque(){
	deque *dq = (deque *)malloc(sizeof(deque));
	dq->N = 0;
	dq->first = NULL;
	dq->last = NULL;
	return dq;
}

void add_first_data_deque(deque_valtype val, deque *dq){
	dq_node *first = (dq_node *)malloc(sizeof(dq_node));
	first->val = val;
	first->prev = NULL;
	first->next = dq->first;
	dq->first = first;
	dq->N++;
	if(dq->N == 1){
		dq->last = first;
	}
	else{
		first->next->prev = first;
	}
}

void add_last_data_deque(deque_valtype val, deque *dq){
	dq_node *last = (dq_node *)malloc(sizeof(dq_node));
	last->val = val;
	last->prev = dq->last;
	last->next = NULL;
	dq->last = last;
	dq->N++;
	if(dq->N == 1){
		dq->first = last;
	}
	else{
		last->prev->next = last;
	}
}

deque_valtype take_first_data_deque(deque *dq){
	if(dq->N == 0){
		printf("In function 'take_first_data_deque':\nThere is no data in the deque");
	}
	deque_valtype ans = dq->first->val;
	dq->N--;
	if(dq->N == 0){
		free(dq->first);
		dq->first = NULL;
		dq->last == NULL;
	}	
	else{
		dq->first = dq->first->next;
		free(dq->first->prev);
		dq->first->prev = NULL;
	}
	return ans;
}

deque_valtype take_last_data_deque(deque *dq){
	if(dq->N == 0){
		printf("In function 'take_last_data_deque':\nThere is no data in the deque");
	}
	deque_valtype ans = dq->last->val;
	dq->N--;
	if(dq->N == 0){
		free(dq->last);
		dq->first = NULL;
		dq->last == NULL;
	}	
	else{
		dq->last = dq->last->prev;
		free(dq->last->next);
		dq->last->next = NULL;
	}
	return ans;
}

deque_valtype look_first_data_deque(deque *dq){
	if(dq->N == 0){
		printf("In function 'look_first_data_deque':\nThere is no data in the deque");
	}
	return dq->first->val;
}

deque_valtype look_last_data_deque(deque *dq){
	if(dq->N == 0){
		printf("In function 'look_last_data_deque':\nThere is no data in the deque");
	}
	return dq->last->val;
}

void out_all_deque(deque *dq){
	dq_node *now = dq->first;
	while(now != NULL){
		printf("%d\n", now->val);
		now = now->next;
	}
}

int main(){
	int K, i;
	pair p;
	vertex *nowv;
	scanf("%d", &K);
	graph *g = make_graph(K, inf);
	for(i = 0; i < K; i++){
		set_edge(g, i, (i + 1) % K, 1);
		set_edge(g, i, (i * 10) % K, 0);
	}
	build_graph(g);
	deque *dq = make_deque();
	p.v_num = 1;
	p.dis = 1;
	add_first_data_deque(p, dq);
	while(dq->N > 0){
		p = take_last_data_deque(dq);
		nowv = g->v[p.v_num];
		if(p.dis < nowv->val){
			nowv->val = p.dis;
			for(i = 0; i < nowv->next_num; i++){
				p.v_num = nowv->next[i]->num;
				p.dis = nowv->val + nowv->next_weight[i];
				if(nowv->next_weight[i] == 0){
					add_last_data_deque(p, dq);
				}
				else{
					add_first_data_deque(p, dq);
				}
			}
		}
	}
	printf("%d\n", g->v[0]->val);
	return 0;
} ./Main.c: In function ‘out_all_deque’:
./Main.c:214:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘pair {aka struct <anonymous>}’ [-Wformat=]
   printf("%d\n", now->val);
          ^
./Main.c: In function ‘main’:
./Main.c:223:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &K);
  ^