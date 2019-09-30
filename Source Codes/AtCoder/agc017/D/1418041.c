#include <stdio.h>
#include <stdlib.h>

#define datatype int

typedef struct edge_sub {
	int v;
	struct edge_sub *next;
}edge;

typedef struct {
	int num;
	int parent;
	int grundy;
	edge *e;
}vertex;

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

void add_edge(int x, int y, vertex *V){
	edge *new;
	new = (edge *)malloc(sizeof(edge));
	new->v = y;
	new->next = V[x].e;
	V[x].e = new;
	new = (edge *)malloc(sizeof(edge));
	new->v = x;
	new->next = V[y].e;
	V[y].e = new;
}

typedef struct {
	node *fst;
	int num;
}stack;

stack *make_stack(){
	stack *s = (stack *)malloc(sizeof(stack));
	s->fst = NULL;
	s->num = 0;
	return s;
}

Boolean is_empty_s(stack *s){
	if(s->num == 0){
		return true;
	}
	else{
		return false;
	}
}

void add_data_s(datatype val, stack *s){
	node *fst = (node *)malloc(sizeof(node));
	fst->data = val;
	fst->next = s->fst;
	s->fst = fst;
	s->num++;
}

datatype take_data_s(stack *s){
	if(s->num == 0){
		printf("no data in the stack\n");
	}
	datatype ans = s->fst->data;
	node *fst = s->fst;
	s->fst = fst->next;
	free(fst);
	s->num--;
	return ans;
}

int main(){
	int N, x, y, i;
	vertex v;
	edge *e;
	scanf("%d", &N);
	vertex *V = (vertex *)malloc(sizeof(vertex) * N);
	for(i = 0; i < N; i++){
		V[i].num = i;
		V[i].parent = -1;
		V[i].grundy = 0;
		V[i].e = NULL;
	}
	for(i = 1; i < N; i++){
		scanf("%d%d", &x, &y);
		add_edge(x - 1, y - 1, V);
	}
	queue *q = make_queue();
	stack *s = make_stack();
	add_data_q(0, q);
	add_data_s(0, s);
	while(is_empty_q(q) == false){
		v = V[take_data_q(q)];
		//printf("v.num = %d\n", v.num);
		//printf("v.parent = %d\n", v.parent);
		e = v.e;
		while(e != NULL){
			if(e->v != v.parent){
				//printf("e->v = %d\n", e->v);
				V[e->v].parent = v.num;
				add_data_q(e->v, q);
				add_data_s(e->v, s);
			}
			e = e->next;
		}
	}
	while(1){
		v = V[take_data_s(s)];
		//printf("v.num = %d\n", v.num);
		//printf("v.grundy = %d\n", v.grundy);
		if(v.parent == -1){
			break;
		}
		V[v.parent].grundy ^= (v.grundy + 1);
	}
	if(V[0].grundy == 0){
		printf("Bob\n");
	}
	else{
		printf("Alice\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:140:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:149:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x, &y);
   ^