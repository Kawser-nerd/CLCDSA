#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define datatype int
#define array_size 31
#define inf (int)(1e9)

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
	datatype val;
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
graph *make_graph(int N, datatype ini_val){
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

typedef enum{
	false,
	true
}Boolean;

typedef struct node_sub{
	datatype data;
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

void add_data_q(datatype val, queue *q){
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

datatype take_data_q(queue *q){
	if(q->num == 0){
		printf("no data in the queue\n");
	}
	datatype ans = q->fst->data;
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

datatype look_data_q(queue *q){
	if(q->num == 0){
		printf("no data in the queue\n");
	}
	else{
		return q->fst->data;
	}
}

void to_empty(queue *q){
	datatype a;
	while(is_empty_q(q) == false){
		a = take_data_q(q);
	}
}

void output(int *prev, int i, char **s){
	if(prev[i] == -1){
		printf("%s\n", s[i]);
	}
	else{
		output(prev, prev[i], s);
		printf("%s\n", s[i]);
	}
}

int main(){
	int N, L, i, j, k, different_count;
	char *first = (char *)malloc(sizeof(char) * array_size);
	char *last = (char *)malloc(sizeof(char) * array_size);
	scanf("%s%s", first, last);
	L = strlen(first);
	scanf("%d", &N);
	char **s = (char **)malloc(sizeof(char *) * (N + 2));
	for(i = 0; i <= N + 1; i++){
		s[i] = (char *)malloc(sizeof(char) * (L + 1));
		if(1 <= i && i <= N){
			scanf("%s", s[i]);
		}
	}
	if(strcmp(first, last) == 0){
		printf("0\n");
		printf("%s\n", first);
		printf("%s\n", last);
		return 0;
	}
	strcpy(s[0], first);
	strcpy(s[N + 1], last);
	graph *g = make_graph(N + 2, inf);
	for(i = 0; i < N + 1; i++){
		for(j = i + 1; j <= N + 1; j++){
			different_count = 0;
			for(k = 0; k < L; k++){
				if(s[i][k] != s[j][k]){
					different_count++;
				}
			}
			if(different_count == 1){
				set_edge(g, i, j, 1);
				set_edge(g, j, i, 1);
			}
		}
	}
	build_graph(g);
	int *prev = (int *)malloc(sizeof(int) * (N + 2));
	for(i = 0; i <= N + 1; i++){
		prev[i] = -1;
	}
	queue *q = make_queue();
	g->v[0]->val = 0;
	add_data_q(0, q);
	vertex *nowv;
	while(is_empty_q(q) == false){
		nowv = g->v[take_data_q(q)];
		for(i = 0; i < nowv->next_num; i++){
			if(nowv->next[i]->val > nowv->val + 1){
				nowv->next[i]->val = nowv->val + 1;
				add_data_q(nowv->next[i]->num, q);
				prev[nowv->next[i]->num] = nowv->num;
			}
		}
	}
	if(prev[N + 1] == -1){
		printf("-1\n");
	}
	else{
		printf("%d\n", g->v[N + 1]->val - 1);
		output(prev, N + 1, s);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:200:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s", first, last);
  ^
./Main.c:202:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:207:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s", s[i]);
    ^