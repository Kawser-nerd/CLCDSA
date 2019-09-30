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
}

typedef struct {
	tree_vertex **array;
	int N;
}stack;

stack *make_stack(int maxN){
	stack *s = (stack *)malloc(sizeof(stack));
	s->array = (tree_vertex **)malloc(sizeof(tree_vertex *) * maxN);
	s->N = 0;
	return s;
}

int element_num_stack(stack *s){
	return s->N;
}

void add_data_stack(tree_vertex *val, stack *s){
	s->array[s->N] = val;
	s->N++;
}

tree_vertex *take_data_stack(stack *s){
	if(s->N == 0){
		printf("no data in the stack\n");
	}
	s->N--;
	return s->array[s->N];
}

tree_vertex *look_data_stack(stack *s){
	if(s->N == 0){
		printf("no data in the stack\n");
	}
	else{
		return s->array[s->N - 1];
	}
}

void flush_stack(stack *s){
	s->N = 0;
}

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, X, Y, a, b, i, j;
	scanf("%d%d%d", &N, &X, &Y);
	X--;
	Y--;
	tree *tr = make_tree(N, X, 0);
	tree *tb = make_tree(N, Y, 0);
	for(i = 1; i < N; i++){
		scanf("%d%d", &a, &b);
		set_edge_tree(a - 1, b - 1, 1, tr);
	}
	for(i = 1; i < N; i++){
		scanf("%d%d", &a, &b);
		set_edge_tree(a - 1, b - 1, 1, tb);
	}
	build_tree(tr);
	build_tree(tb);
	tree_vertex **vr = (tree_vertex **)malloc(sizeof(tree_vertex *) * N);
	tree_vertex **vb = (tree_vertex **)malloc(sizeof(tree_vertex *) * N);
	for(i = 0; i < N; i++){
		vr[tr->sorted_v[i]->num] = tr->sorted_v[i];
		vb[tb->sorted_v[i]->num] = tb->sorted_v[i];
	}
	tree_vertex *nowv, *parev;
	for(i = 1; i < N; i++){
		nowv = tr->sorted_v[i];
		nowv->val = nowv->parent->val + 1;
		nowv = tb->sorted_v[i];
		nowv->val = nowv->parent->val + 1;
	}
/*	for(i = 0; i < N; i++){
		printf("vb[%d]->val = %d\n", i, vb[i]->val);
	}
	printf("test3\n");
*/	int *escape = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		escape[i] = 0;
	}
	int hnv, hpv;
	for(i = 1; i < N; i++){
		nowv = tr->sorted_v[i];
		parev = nowv->parent;
		hnv = vb[nowv->num]->val;
		hpv = vb[parev->num]->val;
//		printf("nowv->num = %d\n", nowv->num);
//		printf("parev->num = %d\n", parev->num);
//		printf("hnv = %d\n", hnv);
//		printf("hpv = %d\n", hpv);
		if(hnv == hpv){
//			printf("test3.2\n");
			if(vb[nowv->num]->parent->num == vb[parev->num]->parent->num){
				escape[parev->num]++;
			}
		}
		else if(hnv < hpv){
			if(hpv == hnv + 1){
				if(vb[parev->num]->parent->num == vb[nowv->num]->num){
					escape[parev->num]++;
				}
			}
			else if(hpv == hnv + 2){
				if(vb[parev->num]->parent->parent->num == vb[nowv->num]->num){
					escape[parev->num]++;
				}
			}
		}
		else{
			if(hnv == hpv + 1){
//				printf("test3.5\n");
				if(vb[nowv->num]->parent->num == vb[parev->num]->num){
					escape[parev->num]++;
				}
			}
			else if(hnv == hpv + 2){
				if(vb[nowv->num]->parent->parent->num == vb[parev->num]->num){
					escape[parev->num]++;
				}
			}
		}
	}
	for(i = 0; i < N; i++){
		if(vr[i]->chilnum == escape[i]){
			escape[i] = 0;
		}
		else{
			escape[i] = 1;
		}
	}
/*	for(i = 0; i < N; i++){
		printf("escape[%d] = %d\n", i, escape[i]);
	}
*/	stack *s = make_stack(N);
	add_data_stack(tr->sorted_v[0], s);
	int ans = 0;
	while(element_num_stack(s) > 0){
		nowv = take_data_stack(s);
//		printf("nowv->num = %d\n", nowv->num);
		ans = max(ans, vb[nowv->num]->val);
//		printf("ans = %d\n", ans);
		if(nowv->val < vb[nowv->num]->val){
			if(escape[nowv->num] == 1){
				printf("-1\n");
				return 0;
			}
			else{
				for(j = 0; j < nowv->chilnum; j++){
					add_data_stack(nowv->children[j], s);
				}
			}
		}
	}
	printf("%d\n", 2 * ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:172:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &X, &Y);
  ^
./Main.c:178:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^
./Main.c:182:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^