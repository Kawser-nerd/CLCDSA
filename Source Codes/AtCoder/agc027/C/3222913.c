#include <stdio.h>
#include <stdlib.h>
#define graph_valtype int
#define queue_valtype edge

typedef struct {
	int a;
	int b;
	int w;
}edge;

typedef struct q_node_sub{
	queue_valtype data;
	struct q_node_sub *next;
}q_node;

typedef struct {
	q_node *fst;
	q_node *last;
	int num;
}queue;

queue *make_queue(){
	queue *q = (queue *)malloc(sizeof(queue));
	q->fst = NULL;
	q->last = NULL;
	q->num = 0;
	return q;
}

int element_num_q(queue *q){
	return q->num;
}

void add_data_q(queue_valtype val, queue *q){
	q_node *last = (q_node *)malloc(sizeof(q_node));
	last->data = val;
	last->next = NULL;
	if(element_num_q(q) == 0){
		q->fst = last;
	}
	else{
		q->last->next = last;
	}
	q->last = last;
	q->num++;
}

queue_valtype take_data_q(queue *q){
	if(q->num == 0){
		printf("no data in the queue\n");
	}
	queue_valtype ans = q->fst->data;
	q_node *fst = q->fst;
	if(q->num == 1){
		q->fst = NULL;
		q->last = NULL;
	}
	else{
		q->fst = fst->next;
	}
	free(fst);
	q->num--;
	return ans;
}

queue_valtype look_data_q(queue *q){
	if(q->num == 0){
		printf("no data in the queue\n");
	}
	else{
		return q->fst->data;
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

signed compare_edge(const void *x, const void *y){
	int sub = ((edge *)x)->a - ((edge *)y)->a;
	if(sub == 0){
		return ((edge *)x)->b - ((edge *)y)->b;
	}
	else{
		return sub;
	}
}

char *s;
int *is_used;
graph *g;

int solve(int a, int b, int w){
	int i;
	if(is_used[w] == 1){
		return 1;
	}
	if(is_used[w] == 2){
		return 0;
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
	for(i = 0; i < M; i++){
		scanf("%d%d", &a, &b);
		es[2 * i].a = a - 1;
		es[2 * i].b = b - 1;
		es[2 * i + 1].a = b - 1;
		es[2 * i + 1].b = a - 1;
	}
	qsort(es, 2 * M, sizeof(edge), compare_edge);
	g = make_graph(N, 0);
	for(i = 1, j = 1; i < 2 * M; i++){
		if(es[i].a != es[i - 1].a || es[i].b != es[i - 1].b){
			es[j] = es[i];
			j++;
		}
	}
	M = j;
	for(i = 0; i < M; i++){
//		printf("es[%d] = (%d, %d, %d)\n", i, es[i].a, es[i].b, i);
		set_edge_graph(es[i].a, es[i].b, i, g);
	}
	build_graph(g);
	is_used = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		is_used[i] = -1;
	}
	for(i = 0; i < M; i++){
		if(solve(es[i].a, es[i].b, i) == 1){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
/*	queue *q = make_queue();
	edge e;
	graph_vertex *nowv;
	for(i = 0; i < M; i++){
		if(is_used[i] >= 0){
			continue;
		}
		printf("i = %d\n", i);
		e.a = es[i].a;
		e.b = es[i].b;
		e.w = i;
		add_data_q(e, q);
		while(element_num_q(q) > 0){
			e = take_data_q(q);
			a = e.a;
			b = e.b;
			j = e.w;
			printf(" (a, b, j) = (%d, %d, %d)\n", a, b, j);
			if(is_used[j] == i){
				printf("Yes\n");
				return 0;
			}
			if(is_used[j] >= 0){
				continue;
			}
			is_used[j] = i;
			nowv = g->v[b];
			for(k = 0; k < nowv->next_num; k++){
				if(s[a] != s[nowv->next[k]->num]){
					e.a = b;
					e.b = nowv->next[k]->num;
					e.w = nowv->next_weight[k];
					add_data_q(e, q);
				}
			}
		}
	}
	printf("No\n");
	return 0;
*/
} ./Main.c: In function ‘main’:
./Main.c:209:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:211:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:214:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^