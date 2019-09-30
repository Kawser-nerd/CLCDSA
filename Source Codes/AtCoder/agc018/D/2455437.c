#include <stdio.h>
#include <stdlib.h>
#define int long long
#define tree_valtype int
#define inf (int)(2e18)

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
}

int min(int a, int b){
	return a <= b ? a : b;
}

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int N, A, B, C, i, j;
	scanf("%lld", &N);
	tree *t = make_tree(N, 0, 1);
	for(i = 1; i < N; i++){
		scanf("%lld%lld%lld", &A, &B, &C);
		set_edge_tree(A - 1, B - 1, C, t);
	}
	build_tree(t);
	tree_vertex *nowv;
	int ans = 0, sub;
	for(i = N - 1; i > 0; i--){
		nowv = t->sorted_v[i];
		nowv->parent->val += nowv->val;
		ans += 2 * min(nowv->val, N - nowv->val) * nowv->pareweight;
	}
	int max_sub_tree, min_edge;
	for(i = N - 1; i >= 0; i--){
		nowv = t->sorted_v[i];
		if(N % 2 == 0 && nowv->val == N / 2){
			sub = nowv->pareweight;
			break;
		}
		if(nowv->chilnum > 0){
			max_sub_tree = 0;
			min_edge = inf;
			if(i > 0){
				max_sub_tree = N - nowv->val;
				min_edge = nowv->pareweight;
			}
			for(j = 0; j < nowv->chilnum; j++){
				max_sub_tree = max(max_sub_tree, nowv->children[j]->val);
				min_edge = min(min_edge, nowv->chilweight[j]);
			}
			if(max_sub_tree <= N / 2){
				sub = min_edge;
			}
		}
	}
	printf("%lld\n", ans - sub);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:136:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:139:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &A, &B, &C);
   ^