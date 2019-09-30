#include <stdio.h>
#include <stdlib.h>
#define int long long
#define graph_valtype int

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

#define queue_valtype vertex *

typedef enum{
	false,
	true
}Boolean;

typedef struct node_sub{
	queue_valtype data;
	struct node_sub *next;
}node;

typedef struct {
	node *fst;
	node *last;
	int num;
}queue;

queue *make_queue(){
	queue *q = (queue *)malloc(sizeof(queue));
	q->fst = NULL;
	q->last = NULL;
	q->num = 0;
	return q;
}

Boolean is_empty_q(queue *q){
	if(q->num == 0){
		return true;
	}
	else{
		return false;
	}
}

void add_data_q(queue_valtype val, queue *q){
	node *last = (node *)malloc(sizeof(node));
	last->data = val;
	last->next = NULL;
	if(is_empty_q(q) == true){
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
	node *fst = q->fst;
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

void to_empty(queue *q){
	queue_valtype a;
	while(is_empty_q(q) == false){
		a = take_data_q(q);
	}
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

signed main(){
	int N, M, u, v, i, j;
	scanf("%lld%lld", &N, &M);
	graph *g = make_graph(N, -1);
	for(i = 0; i < M; i++){
		scanf("%lld%lld", &u, &v);
		u--;
		v--;
		set_edge(g, u, v, 0);
		set_edge(g, v, u, 0);
	}
	build_graph(g);
	int x = 0, y = 0, z = 0, flug;
	queue *q = make_queue();
	vertex *nowv;
	for(i = 0; i < N; i++){
//		printf("i = %lld\n", i);
		nowv = g->v[i];
		if(nowv->val == -1){
			nowv->val = 0;
			if(nowv->next_num == 0){
				x++;
			}
			else{
				add_data_q(nowv, q);
				flug = 0;
				while(is_empty_q(q) == false){
					nowv = take_data_q(q);
					for(j = 0; j < nowv->next_num; j++){
						if(nowv->next[j]->val == -1){
							nowv->next[j]->val = 1 - nowv->val;
							add_data_q(nowv->next[j], q);
						}
						else if(nowv->val == nowv->next[j]->val){
							flug = 1;
						}
					}
				}
//				printf("flug = %lld\n", flug);
				if(flug == 0){
					y++;
				}
				else{
					z++;
				}
			}
		}
	}
/*	for(i = 0; i < N; i++){
		printf("g->v[%lld]->val = %lld\n", i, g->v[i]->val);
	}
	printf("(x, y, z) = (%lld, %lld, %lld)\n", x, y, z);
*/	printf("%lld\n", 2 * (N * x + y * y + y * z) - x * x + z * z);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:188:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^
./Main.c:191:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &u, &v);
   ^