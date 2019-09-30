#include <stdio.h>
#include <stdlib.h>

#define datatype int

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
	int num;
}stack;

stack *make_stack(){
	stack *s = (stack *)malloc(sizeof(stack));
	s->fst = NULL;
	s->num = 0;
	return s;
}

Boolean stack_is_empty(stack *s){
	if(s->num == 0){
		return true;
	}
	else{
		return false;
	}
}

void stack_add_data(datatype val, stack *s){
	node *fst = (node *)malloc(sizeof(node));
	fst->data = val;
	fst->next = s->fst;
	s->fst = fst;
	s->num++;
}

datatype stack_take_data(stack *s){
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

datatype stack_look_data(stack *q){
	if(q->num == 0){
		printf("no data in the stack\n");
	}
	else{
		return q->fst->data;
	}
}

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

Boolean queue_is_empty(queue *q){
	if(q->num == 0){
		return true;
	}
	else{
		return false;
	}
}

void queue_add_data(datatype val, queue *q){
	node *last = (node *)malloc(sizeof(node));
	last->data = val;
	last->next = NULL;
	if(queue_is_empty(q) == true){
		q->fst = last;
	}
	else{
		q->last->next = last;
	}
	q->last = last;
	q->num++;
}

datatype queue_take_data(queue *q){
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

datatype queue_look_data(queue *q){
	if(q->num == 0){
		printf("no data in the queue\n");
	}
	else{
		return q->fst->data;
	}
}

void insert_node(int val, node **v){
	node *new = (node *)malloc(sizeof(node));
	new->data = val;
	new->next = *v;
	*v = new;
}

int main(){
	int N, a, b, v, i;
	node *n;
	scanf("%d", &N);
	node **relative = (node **)malloc(sizeof(node *) * N);
	int *parent = (int *)malloc(sizeof(int) * N);
	Boolean *exist = (Boolean *)malloc(sizeof(Boolean) * N);
	for(i = 0; i < N; i++){
		relative[i] = NULL;
		exist[i] = true;
	}
	for(i = 1; i < N; i++){
		scanf("%d%d", &a, &b);
		a--;
		b--;
		insert_node(a, &relative[b]);
		insert_node(b, &relative[a]);
	}
	stack *s = make_stack();
	queue *q = make_queue();
	queue_add_data(0, q);
	stack_add_data(0, s);
	parent[0] = -1;
	while(queue_is_empty(q) == false){
		v = queue_take_data(q);
		for(n = relative[v]; n != NULL; n = n->next){
			if(n->data != parent[v]){
				queue_add_data(n->data, q);
				stack_add_data(n->data, s);
				parent[n->data] = v;
			}
		}
	}
	while(stack_is_empty(s) == false){
		v = stack_take_data(s);
		if(exist[v] == true){
			if(exist[parent[v]] == true){
				exist[parent[v]] = false;
			}
			else{
				printf("First\n");
				return 0;
			}
		}
	}
	printf("Second\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:140:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:149:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^