#include <stdio.h>
#include <stdlib.h>
#define int long long
#define graph_valtype int
#define heap_valtype pair
#define inf (int)(1e18)

typedef struct {
	int v_num;
	int dis;
}pair;

int compare(heap_valtype a, heap_valtype b){
	return a.dis - b.dis;
}

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

typedef enum{
	false,
	true
}boolean;

typedef struct node_sub{
	heap_valtype val;
	struct node_sub *parent;
	struct node_sub *prev;
	struct node_sub *next;
	struct node_sub *left;
	struct node_sub *right;
}node;

typedef struct {
	int num;
	node *root;
	node *last;
}heap;

/*
int compare(heap_valtype a, heap_valtype b){
	return a - b;
}
*/

//heap???
heap *make_heap(){
	heap *h = (heap *)malloc(sizeof(heap));
	h->num = 0;
	h->root = NULL;
	h->last = NULL;
	return h;
}

//????????
boolean is_empty(heap *h){
	if(h->num == 0){
		return true;
	}
	else{
		return false;
	}
}

void up_heapify(node *n, heap *h){
	if(n->parent != NULL){
		if(compare(n->val, n->parent->val) < 0){
			heap_valtype tmp;
			tmp = n->val;
			n->val = n->parent->val;
			n->parent->val = tmp;
			up_heapify(n->parent, h);
		}
	}
}

//??????
void insert(heap_valtype val, heap *h){
	node *new = (node *)malloc(sizeof(node));
	new->val = val;
	new->next = NULL;
	new->left = NULL;
	new->right = NULL;
	if(is_empty(h) == true){
		new->parent = NULL;
		new->prev = NULL;
		h->root = new;
		h->last = new;
	}
	else if(h->num == 1){
		new->parent = h->root;
		new->prev = h->root;
		h->root->left = new;
		h->root->next = new;
		h->last = new;
		up_heapify(new, h);
	}
	else{
		new->prev = h->last;
		h->last->next = new;
		if(h->last->parent->right == NULL){
			new->parent = h->last->parent;
			h->last->parent->right = new;
		}
		else{
			new->parent = h->last->parent->next;
			h->last->parent->next->left = new;
		}
		h->last = new;
		up_heapify(new, h);
	}
	h->num++;
}

void down_heappify(node *n, heap *h){
	if(n->left != NULL){
		heap_valtype tmp;
		if(n->right == NULL){
			if(compare(n->val, n->left->val) > 0){
				tmp = n->val;
				n->val = n->left->val;
				n->left->val = tmp;
				down_heappify(n->left, h);
			}
		}
		else{
			if(compare(n->left->val, n->right->val) <= 0 && compare(n->val, n->left->val) > 0){
				tmp = n->val;
				n->val = n->left->val;
				n->left->val = tmp;
				down_heappify(n->left, h);
			}
			else if(compare(n->left->val, n->right->val) > 0 && compare(n->val, n->right->val) > 0){
				tmp = n->val;
				n->val = n->right->val;
				n->right->val = tmp;
				down_heappify(n->right, h);
			}
		}
	}
}

//??????????
heap_valtype take_min(heap *h){
	if(h->num == 0){
		printf("no data in the heap\n");
	}
	heap_valtype ans = h->root->val;
	node *ln = h->last;
	if(h->num == 1){
		h->root = NULL;
		h->last = NULL;
	}
	else{
		ln->prev->next = NULL;
		if(ln->parent->right == NULL){
			ln->parent->left = NULL;
		}
		else{
			ln->parent->right = NULL;
		}
		h->last = ln->prev;
		h->root->val = ln->val;
		down_heappify(h->root, h);
	}
	free(ln);
	h->num--;
	return ans;
}

heap_valtype look_min(heap *h){
	if(h->num == 0){
		printf("no data in the heap\n");
	}
	return h->root->val;
}

int *Dijkstra(graph *g, int s){
	int N = g->N, i;
	int *distance = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		distance[i] = inf;
	}
	heap *h = make_heap();
	pair p;
	p.v_num = s;
	p.dis = 0;
	insert(p, h);
	vertex *nowv;
	while(is_empty(h) == false){
		p = take_min(h);
		nowv = g->v[p.v_num];
		if(p.dis < distance[nowv->num]){
			distance[nowv->num] = p.dis;
			for(i = 0; i < nowv->next_num; i++){
				p.v_num = nowv->next[i]->num;
				p.dis = distance[nowv->num] + nowv->next_weight[i];
				insert(p, h);
			}
		}
	}
	return distance;
}

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int N, M, T, a, b, c, i, ans = 0;
	scanf("%lld%lld%lld", &N, &M, &T);
	int *A = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	graph *g1 = make_graph(N, 0);
	graph *g2 = make_graph(N, 0);
	for(i = 0; i < M; i++){
		scanf("%lld%lld%lld", &a, &b, &c);
		set_edge(g1, a - 1, b - 1, c);
		set_edge(g2, b - 1, a - 1, c);
	}
	build_graph(g1);
	build_graph(g2);
	int *go_distance = Dijkstra(g1, 0);
	int *back_distance = Dijkstra(g2, 0);
	for(i = 0; i < N; i++){
//		printf("go_distance[%lld] = %lld\n", i, go_distance[i]);
//		printf("back_distance[%lld] = %lld\n", i, back_distance[i]);
		if(T > go_distance[i] + back_distance[i]){
			ans = max(ans, A[i] * (T - (go_distance[i] + back_distance[i])));
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:305:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &N, &M, &T);
  ^
./Main.c:308:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^
./Main.c:313:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &a, &b, &c);
   ^