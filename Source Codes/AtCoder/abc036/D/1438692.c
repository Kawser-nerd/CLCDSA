#include <stdio.h>
#include <stdlib.h>

#define int long long
#define datatype paint_way
#define p (int)(1e9 + 7)

typedef struct {
	int w;
	int b;
}paint_way;

typedef struct edge_sub{
	int v;
	int w;
	struct edge_sub *next;
}edge;

typedef struct {
	int nearnum;
	edge *near;
}vertex_sub;

typedef struct {
	int num;
	datatype val;
	int parent;
	int pareweight;
	int chilnum;
	int *children;
	int *chilweight;
}vertex;

typedef struct {
	int N;
	int root;
	vertex_sub *v_s;
	vertex *v;
	int *sorted_v;
}tree;

tree *make_tree(int N, int root, datatype val){
	int i;
	tree *t = (tree *)malloc(sizeof(tree));
	t->N = N;
	t->root = root;
	t->v_s = (vertex_sub *)malloc(sizeof(vertex_sub) * N);
	t->v = (vertex *)malloc(sizeof(vertex) * N);
	t->sorted_v = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		(t->v_s)[i].nearnum = 0;
		(t->v_s)[i].near = NULL;
		(t->v)[i].num = i;
		(t->v)[i].val = val;
		(t->v)[i].parent = -1;
		(t->v)[i].pareweight = -1;
		(t->v)[i].chilnum = 0;
		(t->v)[i].children = NULL;
		(t->v)[i].chilweight = NULL;
		(t->sorted_v)[i] = -1;
	}
	return t;
}

void set_edge(tree *t, int a, int b, int w){
	edge *new1 = (edge *)malloc(sizeof(edge));
	new1->v = b;
	new1->w = w;
	new1->next = (t->v_s)[a].near;
	(t->v_s)[a].near = new1;
	(t->v_s)[a].nearnum++;
	edge *new2 = (edge *)malloc(sizeof(edge));
	new2->v = a;
	new2->w = w;
	new2->next = (t->v_s)[b].near;
	(t->v_s)[b].near = new2;
	(t->v_s)[b].nearnum++;
}

void build_tree(tree *t){
	vertex_sub *v_s = t->v_s;
	vertex *v = t->v;
	int *sorted_v = t->sorted_v;
	sorted_v[0] = t->root;
	if(t->N > 1){
		int i, j, nowv;
		edge *nowe;
		for(i = 0, j = 1; j - i > 0; i++){
			nowv = sorted_v[i];
			if(i == 0){
				v_s[nowv].nearnum++;
			}
			v[nowv].children = (int *)malloc(sizeof(int) * (v_s[nowv].nearnum - 1));
			v[nowv].chilweight = (int *)malloc(sizeof(int) * (v_s[nowv].nearnum - 1));
			if(i == 0){
				v_s[nowv].nearnum--;
			}
			for(nowe = v_s[nowv].near; nowe != NULL; nowe = nowe->next){
				if(nowe->v != v[nowv].parent){
					(v[nowv].children)[v[nowv].chilnum] = nowe->v;
					(v[nowv].chilweight)[v[nowv].chilnum] = nowe->w;
					v[nowv].chilnum++;
					v[nowe->v].parent = nowv;
					v[nowe->v].pareweight = nowe->w;
					sorted_v[j] = nowe->v;
					j++;
				}
			}
		}
	}
}

signed main(){
	int N, a, b, i;
	scanf("%lld", &N);
	paint_way val;
	val.w = 1;
	val.b = 1;
	tree *t = make_tree(N, 0, val);
	for(i = 1; i < N; i++){
		scanf("%lld%lld", &a, &b);
		set_edge(t, a - 1, b - 1, 1);
	}
	build_tree(t);
	for(i = N - 1; i > 0; i--){
		(t->v)[(t->v)[(t->sorted_v)[i]].parent].val.w = ((t->v)[(t->v)[(t->sorted_v)[i]].parent].val.w * ((t->v)[(t->sorted_v)[i]].val.w + (t->v)[(t->sorted_v)[i]].val.b)) % p;
		(t->v)[(t->v)[(t->sorted_v)[i]].parent].val.b = ((t->v)[(t->v)[(t->sorted_v)[i]].parent].val.b * (t->v)[(t->sorted_v)[i]].val.w) % p;
	}
	printf("%lld\n", ((t->v)[0].val.w + (t->v)[0].val.b) % p);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:115:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:121:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &a, &b);
   ^