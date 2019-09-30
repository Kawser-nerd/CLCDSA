#include <stdio.h>
#include <stdlib.h>
#define tree_valtype int

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

void release_tree(tree *t){
	int i;
	tree_vertex *nowv;
	for(i = 0; i < t->N; i++){
		nowv = t->v[i];
		free(nowv->children);
		free(nowv->chilweight);
		free(nowv);
	}
	free(t->v);
	free(t->sorted_v);
	free(t);
}

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, K, A, B, i, j, k, l;
	scanf("%d%d", &N, &K);
	tree *T = make_tree(N, 0, 0);
	for(i = 1; i < N; i++){
		scanf("%d%d", &A, &B);
		set_edge_tree(A - 1, B - 1, 1, T);
	}
	int ans = N, count;
	tree *t;
	tree_vertex *nowv;
	if(K % 2 == 0){
		for(i = 0; i < N; i++){
//			printf("i = %d\n", i);
			t = make_tree(N, i, 0);
			t->v_s = T->v_s;
			build_tree(t);
			count = 0;
			for(j = 0; j < N; j++){
				nowv = t->sorted_v[j];
				if(nowv->val > K / 2){
					count++;
				}
				for(k = 0; k < nowv->chilnum; k++){
					nowv->children[k]->val = nowv->val + 1;
				}
			}
//			printf("count = %d\n", count);
			ans = min(ans, count);
			release_tree(t);
		}
	}
	else{
		for(i = 0; i < N; i++){
			t = make_tree(N, i, 0);
			t->v_s = T->v_s;
			build_tree(t);
			for(l = 0; l < t->sorted_v[0]->chilnum; l++){
//				printf("(i, sorted_v[0]->children[l]->num) = (%d, %d)\n", i, t->sorted_v[0]->children[l]->num);
				for(j = 0; j < N; j++){
					t->sorted_v[j]->val = 0;
				}
				count = 0;
				for(j = 0; j < N; j++){
					nowv = t->sorted_v[j];
					if(nowv->val > K / 2){
						count++;
					}
					for(k = 0; k < nowv->chilnum; k++){
						if(j > 0 || k != l){
							nowv->children[k]->val = nowv->val + 1;
						}
					}
				}
				ans = min(ans, count);
			}
			release_tree(t);
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:145:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:148:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &A, &B);
   ^