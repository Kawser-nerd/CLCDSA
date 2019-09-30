#include <stdio.h>
#include <stdlib.h>

#define datatype int

typedef enum{
	false,
	true
}Boolean;

typedef struct edge_sub{
	int v;
	struct edge_sub *next;
}edge;

typedef struct {
	int num;
	int parent;
	int dis;
	Boolean is_path;
	edge *near;
}vertex;

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

void to_empty(queue *q){
	datatype a;
	while(is_empty_q(q) == false){
		a = take_data_q(q);
	}
}

int main(){
	int N, a, b, i, ans = 0;
	scanf("%d", &N);
	vertex *v = (vertex *)malloc(sizeof(vertex) * N);
	for(i = 0; i < N; i++){
		v[i].num = i;
		v[i].parent = -1;
		v[i].dis = 0;
		v[i].is_path = false;
		v[i].near = NULL;
	}
	edge *new;
	for(i = 1; i < N; i++){
		scanf("%d%d", &a, &b);
		a--;
		b--;
		new = (edge *)malloc(sizeof(edge));
		new->v = b;
		new->next = v[a].near;
		v[a].near = new;
		new = (edge *)malloc(sizeof(edge));
		new->v = a;
		new->next = v[b].near;
		v[b].near = new;
	}
	queue *q = make_queue();
	add_data_q(0, q);
	int nowv;
	edge *e;
	while(is_empty_q(q) == false){
		nowv = take_data_q(q);
		//printf("nowv = %d\n", nowv);
		e = v[nowv].near;
		while(e != NULL){
			if(e->v != v[nowv].parent){
				v[e->v].parent = nowv;
				v[e->v].dis  = v[nowv].dis + 1;
				add_data_q(e->v, q);
			}
			e = e->next;
		}
	}
	//printf("test1\n");
	nowv = N - 1;
	while(nowv != -1){
		//printf("nowv = %d\n", nowv);
		v[nowv].is_path = true;
		nowv = v[nowv].parent;
	}
	//printf("test2\n");
	to_empty(q);
	add_data_q(0, q);
	//printf("v[N - 1].dis = %d\n", v[N - 1].dis);
	while(is_empty_q(q) == false){
		nowv = take_data_q(q);
		ans++;
		//printf("nowv = %d\n", nowv);
		e = v[nowv].near;
		while(e != NULL){
			if(e->v != v[nowv].parent){
				if(v[e->v].is_path == false || v[e->v].dis < v[N - 1].dis / 2 + 1){
					add_data_q(e->v, q);
				}
			}
			e = e->next;
		}
	}
	//printf("%d\n", ans);
	if(ans > N / 2){
		printf("Fennec\n");
	}
	else{
		printf("Snuke\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:93:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:104:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^