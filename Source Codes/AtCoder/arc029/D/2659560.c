#include <stdio.h>
#include <stdlib.h>
#define int long long
#define tree_valtype int
#define ms_valtype int
#define inf (int)(1e18)

//????
int compare_ms(ms_valtype a, ms_valtype b){
	return b - a;
}

//??
void sort_sub(ms_valtype *origin, int left, int right, ms_valtype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if(k == right){
				origin[i] = tmp[j];
				j++;
			}
			else if(compare_ms(tmp[j], tmp[k]) <= 0 && j < half){
				origin[i] = tmp[j];
				j++;
			}
			else{
				origin[i] = tmp[k];
				k++;
			}
		}
	}
}

void sort(ms_valtype *origin, int N){
	ms_valtype *tmp = (ms_valtype *)malloc(sizeof(ms_valtype) * N);
	sort_sub(origin, 0, N, tmp);
	free(tmp);
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

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

signed main(){
	int N, M, a, b, i, j, k, l;
	scanf("%lld", &N);
	int *s = (int *)malloc(sizeof(int) * N);
	int ssum = 0;
	for(i = 0; i < N; i++){
		scanf("%lld", &s[i]);
		ssum += s[i];
	}
	tree *T = make_tree(N, 0, 1);
	for(i = 1; i < N; i++){
		scanf("%lld%lld", &a, &b);
		set_edge_tree(a - 1, b - 1, 1, T);
	}
	build_tree(T);
	scanf("%lld", &M);
	int *t = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		scanf("%lld", &t[i]);
	}
	sort(t, M);
	int *sum = (int *)malloc(sizeof(int) * M);
	sum[0] = t[0];
	for(i = 1; i < M; i++){
		sum[i] = sum[i - 1] + t[i];
	}
	tree_vertex *nowv;
	for(i = N - 1; i > 0; i--){
		nowv = T->sorted_v[i];
		nowv->parent->val += nowv->val;
	}
	int **dp = (int **)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		dp[i] = (int *)malloc(sizeof(int) * (T->v[i]->val + 1));
		for(j = 0; j <= T->v[i]->val; j++){
			dp[i][j] = s[i];
		}
		dp[i][0] = 0;
	}
	int subnum;
	int *subarray = (int *)malloc(sizeof(int) * N);
	int **subspace = (int **)malloc(sizeof(int *) * N);
	tree_vertex *chilv;
	for(i = 0; i < N; i++){
		subspace[i] = (int *)malloc(sizeof(int) * N);
	}
	for(i = N - 1; i >= 0; i--){
		nowv = T->sorted_v[i];
		if(nowv->chilnum > 0){
			subnum = 0;
			subarray[0] = 0;
			for(j = 0; j < nowv->chilnum; j++){
				chilv = nowv->children[j];
				for(k = 0; k <= subnum; k++){
					for(l = 0; l <= chilv->val; l++){
						subspace[k][l] = subarray[k] + dp[chilv->num][l];
					}
				}
				for(k = 0; k <= subnum + chilv->val; k++){
					subarray[k] = inf;
				}
				for(k = 0; k <= subnum; k++){
					for(l = 0; l <= chilv->val; l++){
						subarray[k + l] = min(subarray[k + l], subspace[k][l]);
					}
				}
				subnum += chilv->val;
			}
			for(k = 0; k <= subnum; k++){
				dp[nowv->num][k + 1] += subarray[k];
			}
		}
	}
/*	for(i = 0; i < N; i++){
		printf("i = %lld\n", i);
		for(j = 0; j <= T->v[i]->val; j++){
			printf("%lld ", dp[i][j]);
		}
		printf("\n");
	}
*/	int ans = ssum;
	for(i = 1; i <= min(N, M); i++){
		ans = max(ans, ssum - dp[0][i] + sum[i - 1]);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:175:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:179:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &s[i]);
   ^
./Main.c:184:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &a, &b);
   ^
./Main.c:188:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &M);
  ^
./Main.c:191:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &t[i]);
   ^