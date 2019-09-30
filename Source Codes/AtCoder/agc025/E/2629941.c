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

typedef struct {
	int all_ancestor_num;
	int ancestor_num;
	tree_vertex **ancestors;
}data_LCA;

int digit_count(int n){
	int ans;
	for(ans = -1; n != 0; ans++){
		n >>= 1;
	}
	return ans;
}

data_LCA **reserve_LCA(tree *t){
	int N = t->N, i, j;
	data_LCA **datas = (data_LCA **)malloc(sizeof(data_LCA *) * N);
	tree_vertex *nowv;
	data_LCA *nowdata;
	nowv = t->sorted_v[0];
	datas[nowv->num] = (data_LCA *)malloc(sizeof(data_LCA));
	nowdata = datas[nowv->num];
	nowdata->all_ancestor_num = 0;
	nowdata->ancestor_num = 0;
	nowdata->ancestors = NULL;
	for(i = 1; i < N; i++){
		nowv = t->sorted_v[i];
		datas[nowv->num] = (data_LCA *)malloc(sizeof(data_LCA));
		nowdata = datas[nowv->num];
		nowdata->all_ancestor_num = datas[nowv->parent->num]->all_ancestor_num + 1;
		nowdata->ancestor_num = digit_count(nowdata->all_ancestor_num) + 1;
		nowdata->ancestors = (tree_vertex **)malloc(sizeof(tree_vertex *) * nowdata->ancestor_num);
		nowdata->ancestors[0] = nowv->parent;
		for(j = 1; j < nowdata->ancestor_num; j++){
			nowdata->ancestors[j] = datas[nowdata->ancestors[j - 1]->num]->ancestors[j - 1];
		}
	}
	return datas;
}

//2??????a,b?reserve_LCA?????datas?????a?b?LCA(??????)????????
int LCA(int a, int b, data_LCA **datas){
	int tmp, i;
	if(datas[a]->all_ancestor_num < datas[b]->all_ancestor_num){
		tmp = a;
		a = b;
		b = tmp;
	}
	for(i = datas[a]->ancestor_num - 1; i >= 0 && datas[a]->ancestor_num > 0; i--){
		while(i >= datas[a]->ancestor_num){
			i--;
		}
		if(datas[datas[a]->ancestors[i]->num]->all_ancestor_num >= datas[b]->all_ancestor_num){
			a = datas[a]->ancestors[i]->num;
		}
	}
	if(a == b){
		return a;
	}
	else{
		for(i = datas[a]->ancestor_num - 1; i >= 0; i--){
			while(i >= datas[a]->ancestor_num){
				i--;
			}
			if(datas[a]->ancestors[i] != datas[b]->ancestors[i]){
				a = datas[a]->ancestors[i]->num;
				b = datas[b]->ancestors[i]->num;
			}
		}
		return datas[a]->ancestors[0]->num;
	}
}

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, M, a, b, i, j;
	scanf("%d%d", &N, &M);
	tree *t = make_tree(N, 0, 0);
	for(i = 1; i < N; i++){
		scanf("%d%d", &a, &b);
		set_edge_tree(a - 1, b - 1, 1, t);
	}
	build_tree(t);
	int *u = (int *)malloc(sizeof(int) * M);
	int *v = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		scanf("%d%d", &u[i], &v[i]);
		u[i]--;
		v[i]--;
	}
	data_LCA **datas = reserve_LCA(t);
	int *sum = (int *)malloc(sizeof(int) * N);
	int *up = (int *)malloc(sizeof(int) * N);
	int *down = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		sum[i] = 0;
		up[i] = 0;
		down[i] = 0;
	}
	tree_vertex *nowv;
	for(i = 0; i < M; i++){
		nowv = t->v[u[i]];
		while(nowv != NULL){
			sum[nowv->num]++;
			nowv = nowv->parent;
		}
		nowv = t->v[v[i]];
		while(nowv != NULL){
			sum[nowv->num]++;
			nowv = nowv->parent;
		}
		nowv = t->v[LCA(u[i], v[i], datas)];
		while(nowv != NULL){
			sum[nowv->num] -= 2;
			nowv = nowv->parent;
		}
	}
	int T = 0;
	for(i = 0; i < N; i++){
		T += min(sum[i], 2);
	}
	printf("%d\n", T);

	int now, dir, lcau, lcav;
	int *u_ans = (int *)malloc(sizeof(int) * M);
	int *v_ans = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		u_ans[i] = -1;
		v_ans[i] = -1;
	}
	while(1){
		now = -1;
		for(i = 0; i < N; i++){
			if(sum[i] == up[i] + down[i] + 1 && sum[i] >= 2){
				if(up[i] == 0){
					now = i;
					dir = 1;
					break;
				}
				if(down[i] == 0){
					now = i;
					dir = -1;
					break;
				}
			}
		}
		if(now == -1){
			for(i = 0; i < N; i++){
				if(sum[i] > up[i] + down[i]){
					now = i;
					dir = 1;
					break;
				}
			}
		}
		if(now == -1){
			break;
		}
		for(i = 0; i < M; i++){
			if(u_ans[i] == -1){
				lcau = LCA(u[i], now, datas);
				lcav = LCA(v[i], now, datas);
				if(lcau == now && lcav != now){
					j = i;
					break;
				}
				if(lcau != now && lcav == now){
					j = i;
					dir *= -1;
					break;
				}
			}
		}
		if(dir == 1){
			u_ans[j] = u[j];
			v_ans[j] = v[j];
		}
		else{
			u_ans[j] = v[j];
			v_ans[j] = u[j];
		}
		nowv = t->v[u[j]];
		while(nowv != NULL){
			if(dir == 1){
				up[nowv->num]++;
			}
			else{
				down[nowv->num]++;
			}
			nowv = nowv->parent;
		}
		nowv = t->v[v[j]];
		while(nowv != NULL){
			if(dir == 1){
				down[nowv->num]++;
			}
			else{
				up[nowv->num]++;
			}
			nowv = nowv->parent;
		}
		nowv = t->v[LCA(u[j], v[j], datas)];
		while(nowv != NULL){
			up[nowv->num]--;
			down[nowv->num]--;
			nowv = nowv->parent;
		}
	}
	for(i = 0; i < M; i++){
		printf("%d %d\n", u_ans[i] + 1, v_ans[i] + 1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:204:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:207:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^
./Main.c:214:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &u[i], &v[i]);
   ^