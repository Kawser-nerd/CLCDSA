#include <stdio.h>
#include <stdlib.h>
#define tree_valtype int
#define dag_valtype int
#define graph_valtype int
#define inf (int)(1e9)
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

typedef struct SCC_sub{
	int num; //???????
	int vertex_num; //???????????????
	int *vertexs; //?????????????????????
	dag_valtype val;
	int next_num;
	struct SCC_sub **next;
	int *next_weight;
	int prev_num;
	struct SCC_sub **prev;
	int *prev_weight;
}SCC; //?????(Strongly Connected Components)

typedef struct {
	int N;
	SCC **sorted_SCC; //topological sort??
}DAG; //????????(Directed Acyclic Graph)

int dfs(int next_bt, int *used, int *bt, int *bt_inv, graph_vertex *v){
	if(used[v->num] == 1){
		return next_bt;
	}
	else{
		int i;
		used[v->num] = 1;
		for(i = 0; i < v->next_num; i++){
			next_bt = dfs(next_bt, used, bt, bt_inv, v->next[i]);
		}
		bt[v->num] = next_bt;
		bt_inv[next_bt] = v->num;
		return next_bt + 1;
	}
}

void dfs_rev1(int next_SCC_num, int *used, int *SCC_num, int *next_num, int *prev_num, graph_vertex *v){
	if(used[v->num] == 1){
		int i;
		used[v->num] = 2;
		for(i = 0; i < v->prev_num; i++){
			dfs_rev1(next_SCC_num, used, SCC_num, next_num, prev_num, v->prev[i]);
		}
		SCC_num[v->num] = next_SCC_num;
		for(i = 0; i < v->next_num; i++){
			if(used[v->next[i]->num] == 1){
				next_num[v->num]++;
				prev_num[v->next[i]->num]++; //?????????????????????
			}
		}
	}
}

void dfs_rev2(SCC *now_SCC, int *used, int *SCC_num, graph_vertex *v, DAG *dag){
	if(used[v->num] == 2){
		int i;
		SCC *next_SCC;
		used[v->num] = 3;
		for(i = 0; i < v->prev_num; i++){
			dfs_rev2(now_SCC, used, SCC_num, v->prev[i], dag);
		}
		now_SCC->vertexs[now_SCC->vertex_num] = v->num;
		now_SCC->vertex_num++;
		for(i = 0; i < v->next_num; i++){
			if(used[v->next[i]->num] == 2){
				next_SCC = dag->sorted_SCC[SCC_num[v->next[i]->num]];
				if(now_SCC->num != next_SCC->num){ //???????????????
					now_SCC->next[now_SCC->next_num] = next_SCC;
					now_SCC->next_weight[now_SCC->next_num] = v->next_weight[i];
					now_SCC->next_num++;
					next_SCC->prev[next_SCC->prev_num] = now_SCC;
					next_SCC->prev_weight[next_SCC->prev_num] = v->next_weight[i];
					next_SCC->prev_num++;
				}
			}
		}
	}
}

DAG *build_DAG(graph *g, dag_valtype ini_val){
	int N = g->N, i;
	int *used = (int *)malloc(sizeof(int) * N);

	int *bt = (int *)malloc(sizeof(int) * N);
	int *bt_inv = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		used[i] = 0;
		bt[i] = -1;
		bt_inv[i] = -1;
	}
	int next_bt;
	for(i = 0, next_bt = 0; i < N; i++){
		next_bt = dfs(next_bt, used, bt, bt_inv, g->v[i]);
	}

	int *SCC_num = (int *)malloc(sizeof(int) * N);
	int *next_num = (int *)malloc(sizeof(int) * N);
	int *prev_num = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		SCC_num[i] = 0;
		next_num[i] = 0;
		prev_num[i] = 0;
	}
	int next_SCC_num;
	for(i = N - 1, next_SCC_num = 0; i >= 0; i--){
		if(used[bt_inv[i]] == 1){
			dfs_rev1(next_SCC_num, used, SCC_num, next_num, prev_num, g->v[bt_inv[i]]);
			next_SCC_num++;
		}
	}

	DAG *dag = (DAG *)malloc(sizeof(DAG));
	SCC *now_SCC;
	dag->N = next_SCC_num;
	dag->sorted_SCC = (SCC **)malloc(sizeof(SCC *) * dag->N);
	for(i = 0; i < dag->N; i++){
		dag->sorted_SCC[i] = (SCC *)malloc(sizeof(SCC));
		now_SCC = dag->sorted_SCC[i];
		now_SCC->num = i;
		now_SCC->vertex_num = 0;
		now_SCC->vertexs = NULL;
		now_SCC->val = ini_val;
		now_SCC->next_num = 0;
		now_SCC->next = NULL;
		now_SCC->next_weight = NULL;
		now_SCC->prev_num = 0;
		now_SCC->prev = NULL;
		now_SCC->prev_weight = NULL;
	}
	for(i = 0; i < N; i++){
		now_SCC = dag->sorted_SCC[SCC_num[i]];
		now_SCC->vertex_num++;
		now_SCC->next_num += next_num[i];
		now_SCC->prev_num += prev_num[i];
	}
	for(i = 0; i < dag->N; i++){
		now_SCC = dag->sorted_SCC[i];
		now_SCC->vertexs = (int *)malloc(sizeof(int) * now_SCC->vertex_num);
		now_SCC->next = (SCC **)malloc(sizeof(SCC *) * now_SCC->next_num);
		now_SCC->next_weight = (int *)malloc(sizeof(int) * now_SCC->next_num);
		now_SCC->prev = (SCC **)malloc(sizeof(SCC *) * now_SCC->prev_num);
		now_SCC->prev_weight = (int *)malloc(sizeof(int) * now_SCC->prev_num);
		now_SCC->vertex_num = 0;
		now_SCC->next_num = 0;
		now_SCC->prev_num = 0;
	}

	for(i = N - 1, next_SCC_num = 0; i >= 0; i--){
		if(used[bt_inv[i]] == 2){
			dfs_rev2(dag->sorted_SCC[next_SCC_num], used, SCC_num, g->v[bt_inv[i]], dag);
			next_SCC_num++;
		}
	}

	return dag;
}

typedef struct tree_edge_sub tree_edge;

typedef struct {
	int num;
	int nearnum;
	tree_edge *near;
}tree_vertex_sub;

struct tree_edge_sub{
	tree_vertex_sub *v;
	int w;
	tree_edge *next;
};

typedef struct tree_v_sub tree_vertex;

struct tree_v_sub{
	int num;
	tree_valtype val;
	tree_vertex *parent;
	int pareweight;
	int chilnum;
	tree_vertex **children;
	int *chilweight;
};

typedef struct {
	int N;
	int root;
	tree_vertex_sub **v_s;
	tree_vertex **v;
	tree_vertex **sorted_v;
}tree;

//???N, ????root, ???????ini_val?????
tree *make_tree(int N, int root, tree_valtype ini_val){
	int i;
	tree *t = (tree *)malloc(sizeof(tree));
	t->N = N;
	t->root = root;
	t->v_s = (tree_vertex_sub **)malloc(sizeof(tree_vertex_sub *) * N);
	t->v = (tree_vertex **)malloc(sizeof(tree_vertex *) * N);
	t->sorted_v = (tree_vertex **)malloc(sizeof(tree_vertex *) * N);
	tree_vertex *parent_in_law = (tree_vertex *)malloc(sizeof(tree_vertex));
	parent_in_law->num = -1;
	parent_in_law->val = ini_val;
	parent_in_law->parent = NULL;
	parent_in_law->pareweight = -1;
	parent_in_law->chilnum = 0;
	parent_in_law->children = NULL;
	parent_in_law->chilweight = NULL;
	for(i = 0; i < N; i++){
		(t->v_s)[i] = (tree_vertex_sub *)malloc(sizeof(tree_vertex_sub));
		(t->v_s)[i]->num = i;
		(t->v_s)[i]->nearnum = 0;
		(t->v_s)[i]->near = NULL;
		(t->v)[i] = (tree_vertex *)malloc(sizeof(tree_vertex));
		(t->v)[i]->num = i;
		(t->v)[i]->val = ini_val;
		(t->v)[i]->parent = parent_in_law;
		(t->v)[i]->pareweight = -1;
		(t->v)[i]->chilnum = 0;
		(t->v)[i]->children = NULL;
		(t->v)[i]->chilweight = NULL;
		(t->sorted_v)[i] = NULL;
	}
	return t;
}

//?t???a???b?????w??????? (0 <= a, b <= N - 1)
void set_edge_tree(int a, int b, int w, tree *t){
	tree_edge *new1 = (tree_edge *)malloc(sizeof(tree_edge));
	new1->v = (t->v_s)[b];
	new1->w = w;
	new1->next = (t->v_s)[a]->near;
	(t->v_s)[a]->near = new1;
	(t->v_s)[a]->nearnum++;

	tree_edge *new2 = (tree_edge *)malloc(sizeof(tree_edge));
	new2->v = (t->v_s)[a];
	new2->w = w;
	new2->next = (t->v_s)[b]->near;
	(t->v_s)[b]->near = new2;
	(t->v_s)[b]->nearnum++;
}

//set_edge_tree??????
void build_tree(tree *t){
	int i, j;
	tree_vertex_sub **v_s = t->v_s;
	tree_vertex **v = t->v;
	tree_vertex **sorted_v = t->sorted_v;
	sorted_v[0] = v[t->root];
	tree_vertex *nowv;
	tree_edge *nowe;
	for(i = 0, j = 1; j - i > 0; i++){
		nowv = sorted_v[i];
		if(i == 0){
			v_s[nowv->num]->nearnum++;
		}
		nowv->children = (tree_vertex **)malloc(sizeof(tree_vertex *) * (v_s[nowv->num]->nearnum - 1));
		nowv->chilweight = (int *)malloc(sizeof(int) * (v_s[nowv->num]->nearnum - 1));
		if(i == 0){
			v_s[nowv->num]->nearnum--;
		}
		for(nowe = v_s[nowv->num]->near; nowe != NULL; nowe = nowe->next){
			if(nowe->v->num != nowv->parent->num){
				(nowv->children)[nowv->chilnum] = v[nowe->v->num];
				(nowv->chilweight)[nowv->chilnum] = nowe->w;
				nowv->chilnum++;
				v[nowe->v->num]->parent = nowv;
				v[nowe->v->num]->pareweight = nowe->w;
				sorted_v[j] = v[nowe->v->num];
				j++;
			}
		}
	}
	sorted_v[0]->parent = NULL;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int Q, q;
	scanf("%d", &Q);
	for(q = 0; q < Q; q++){
		int N, a, b, i, j, k, ans, fixed;
		scanf("%d", &N);
		tree *tA = make_tree(N, 0, 0);
		for(i = 1; i < N; i++){
			scanf("%d%d", &a, &b);
			set_edge_tree(a - 1, b - 1, 1, tA);
		}
		tree *tB = make_tree(N, 0, 0);
		for(i = 1; i < N; i++){
			scanf("%d%d", &a, &b);
			set_edge_tree(a - 1, b - 1, 1, tB);
		}
		tree **tAs = (tree **)malloc(sizeof(tree *) * N);
		tree **tBs = (tree **)malloc(sizeof(tree *) * N);
		tree_vertex *nowvA, *nowvB;
		graph *g;
		DAG *dag;
		for(i = 0, ans = inf; i < N; i++){
			tAs[i] = make_tree(N, i, 0);
			tAs[i]->v_s = tA->v_s;
			build_tree(tAs[i]);
			tBs[i] = make_tree(N, i, 0);
			tBs[i]->v_s = tB->v_s;
			build_tree(tBs[i]);
			tAs[i]->sorted_v[0]->val = 1;
			tBs[i]->sorted_v[0]->val = 1;
			for(j = 1, fixed = 1; j < N; j++){
				nowvA = tAs[i]->sorted_v[j];
				nowvB = tBs[i]->v[nowvA->num];
				if(nowvA->parent->val == 1 && nowvA->parent->num == nowvB->parent->num){
					nowvA->val = 1;
					nowvB->val = 1;
					fixed++;
				}
			}
			g = make_graph(N, 0);
			for(j = 1; j < N; j++){
				nowvA = tAs[i]->sorted_v[j];
				if(nowvA->parent->val == 0){
					set_edge_graph(nowvA->num, nowvA->parent->num, 1, g);
				}
				nowvB = tBs[i]->sorted_v[j];
				if(nowvB->parent->val == 0){
					set_edge_graph(nowvB->parent->num, nowvB->num, 1, g);
				}
			}
			build_graph(g);
			dag = build_DAG(g, 0);
//			printf("fixed[%d] = %d\n", i, fixed);
//			printf("dag->N = %d\n", dag->N);
			if(dag->N == N){
				ans = min(ans, N - fixed);
			}
		}
		for(i = 0; i < N; i++){
			for(j = 0; j < N; j++){
				if(tBs[j]->v[i]->chilnum > 0){
					continue;
				}
				g = make_graph(N, 0);
				for(k = 1; k < N; k++){
					nowvA = tAs[i]->sorted_v[k];
					set_edge_graph(nowvA->num, nowvA->parent->num, 1, g);
					nowvB = tBs[j]->sorted_v[k];
					set_edge_graph(nowvB->parent->num, nowvB->num, 1, g);
				}
				build_graph(g);
				dag = build_DAG(g, 0);
				if(dag->N == N){
					ans = min(ans, N);
				}
			}
		}
		if(ans == inf){
			printf("-1\n");
		}
		else{
			printf("%d\n", ans);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:385:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &Q);
  ^
./Main.c:388:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:391:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d", &a, &b);
    ^
./Main.c:396:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d", &a, &b);
    ^