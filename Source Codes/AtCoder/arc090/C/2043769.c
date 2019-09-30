#include <stdio.h>
#include <stdlib.h>
#define int long long
#define graph_valtype int
#define heap_valtype pair
#define inf (int)(1e18)

int MOD(int a){
	a %= (int)(1e9 + 7);
	return a >= 0 ? a : a + (int)(1e9 + 7);
}

typedef struct {
	int v_num;
	int dis;
	int prev;
}pair;

int compare(heap_valtype a, heap_valtype b){
	return a.dis - b.dis;
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

typedef struct heap_node_sub{
	heap_valtype val;
	struct heap_node_sub *parent;
	struct heap_node_sub *prev;
	struct heap_node_sub *next;
	struct heap_node_sub *left;
	struct heap_node_sub *right;
}heap_node;

typedef struct {
	int N;
	heap_node *root;
	heap_node *last;
}heap;

//heap???
heap *make_heap(){
	heap *h = (heap *)malloc(sizeof(heap));
	h->N = 0;
	h->root = NULL;
	h->last = NULL;
	return h;
}

int element_num_heap(heap *h){
	return h->N;
}

void up_heapify(heap_node *n, heap *h){
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
void add_data_heap(heap_valtype val, heap *h){
	heap_node *new = (heap_node *)malloc(sizeof(heap_node));
	new->val = val;
	new->next = NULL;
	new->left = NULL;
	new->right = NULL;
	if(element_num_heap(h) == 0){
		new->parent = NULL;
		new->prev = NULL;
		h->root = new;
		h->last = new;
	}
	else if(element_num_heap(h) == 1){
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
	h->N++;
}

void down_heappify(heap_node *n, heap *h){
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
heap_valtype take_min_heap(heap *h){
	if(element_num_heap(h) == 0){
		printf("no data in the heap\n");
	}
	heap_valtype ans = h->root->val;
	heap_node *ln = h->last;
	if(element_num_heap(h) == 1){
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
	h->N--;
	return ans;
}

heap_valtype look_min_heap(heap *h){
	if(element_num_heap(h) == 0){
		printf("no data in the heap\n");
	}
	return h->root->val;
}

int *Dijkstra(graph *g, int s, int *path_num){
	int N = g->N, i;
	int *distance = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		distance[i] = inf;
	}
	heap *h = make_heap();
	pair p;
	p.v_num = s;
	p.dis = 0;
	p.prev = s;
	add_data_heap(p, h);
	graph_vertex *nowv;
	while(element_num_heap(h) > 0){
		p = take_min_heap(h);
		nowv = g->v[p.v_num];
		if(p.dis == distance[nowv->num]){
			path_num[nowv->num] = MOD(path_num[nowv->num] + path_num[p.prev]);
		}
		if(p.dis < distance[nowv->num]){
			distance[nowv->num] = p.dis;
			path_num[nowv->num] = path_num[p.prev];
			for(i = 0; i < nowv->next_num; i++){
				p.v_num = nowv->next[i]->num;
				p.dis = distance[nowv->num] + nowv->next_weight[i];
				p.prev = nowv->num;
				add_data_heap(p, h);
			}
		}
	}
	return distance;
}

signed main(){
	int N, M, S, T, u, v, d, i, j;
	scanf("%lld%lld", &N, &M);
	scanf("%lld%lld", &S, &T);
	S--;
	T--;
	graph *g = make_graph(N, 0);
	for(i = 0; i < M; i++){
		scanf("%lld%lld%lld", &u, &v, &d);
		u--;
		v--;
		set_edge_graph(u, v, d, g);
		set_edge_graph(v, u, d, g);
	}
	build_graph(g);
	int *path_num_S = (int *)malloc(sizeof(int) * N);
	int *path_num_T = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		path_num_S[i] = 0;
		path_num_T[i] = 0;
	}
	path_num_S[S] = 1;
	path_num_T[T] = 1;
	int *dis_S = Dijkstra(g, S, path_num_S);
	int *dis_T = Dijkstra(g, T, path_num_T);
	int ans = MOD(path_num_S[T] * path_num_T[S]);
	graph_vertex *nowv;
	for(i = 0; i < N; i++){
		if(dis_S[i] + dis_T[i] == dis_S[T] && dis_S[i] == dis_T[i]){
			ans = MOD(ans - MOD(path_num_S[i] * path_num_S[i]) * MOD(path_num_T[i] * path_num_T[i]));
		}
		nowv = g->v[i];
		for(j = 0; j < nowv->next_num; j++){
			if(/*nowv->num < nowv->next[j]->num 
			 &&*/ dis_S[nowv->num] + nowv->next_weight[j] + dis_T[nowv->next[j]->num] == dis_S[T] 
			 && 2 * dis_S[nowv->num] < dis_S[T] 
			 && 2 * dis_T[nowv->next[j]->num] < dis_T[S]){
			 	ans = MOD(ans - MOD(path_num_S[nowv->num] * path_num_S[nowv->num]) * MOD(path_num_T[nowv->next[j]->num] * path_num_T[nowv->next[j]->num]));
			}
		}
	}
/*	for(i = 0; i < N; i++){
		printf("dis_S[%lld] = %lld\n", i, dis_S[i]);
	}
	printf("\n");
	for(i = 0; i < N; i++){
		printf("dis_T[%lld] = %lld\n", i, dis_T[i]);
	}
	printf("\n");
	for(i = 0; i < N; i++){
		printf("path_num_S[%lld] = %lld\n", i, path_num_S[i]);
	}
	printf("\n");
	for(i = 0; i < N; i++){
		printf("path_num_T[%lld] = %lld\n", i, path_num_T[i]);
	}
	printf("\n");
*/	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:296:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^
./Main.c:297:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &S, &T);
  ^
./Main.c:302:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &u, &v, &d);
   ^