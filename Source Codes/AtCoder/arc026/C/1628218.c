#include <stdio.h>
#include <stdlib.h>
#define int long long
#define datatype light
#define inf (int)(1e18)

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int sum(int a, int b){
	if(a >= inf || b >= inf){
		return inf;
	}
	else{
		return a + b;
	}
}

int rep_min(int a, int N){
	return a;
}


int malloc_count = 0;

typedef struct node_sub{
	int N; //????????(2??)
	int val; //?
	int arg1; //??????1??
	int arg2; //??????2??
	struct node_sub *left; //???, [0, N / 2)???
	struct node_sub *right; //???, [N / 2, N)???
}node; //???

typedef struct {
	node *root; //????????????????
	int e0; //?????
	int e1; //?????
	int (*sum)(int x, int y); //????
	int (*pro)(int x, int y); //????
	int (*rep_sum)(int x, int N); //?????
}segment_tree;

//???r??????????
void argument_update(node *r, int arg1, int arg2, segment_tree *t){
	r->arg2 = (t->sum)((t->pro)(arg1, r->arg2), arg2);
	r->arg1 = (t->pro)(arg1, r->arg1);
}

//???N?????????
node *make_node(int N, segment_tree *t){
	malloc_count++;
	node *r = (node *)malloc(sizeof(node));
	r->N = N;
	r->val = t->e0;
	r->arg1 = t->e1;
	r->arg2 = t->e0;
	r->left = NULL;
	r->right = NULL;
	return r;
}

//???r????????
void out_node(node *r){
	printf("N = %lld\n", r->N);
	printf("val = %lld\n", r->val);
	printf("arg1 = %lld\n", r->arg1);
	printf("arg2 = %lld\n", r->arg2);
	if(r->left == NULL && r->right == NULL){
		printf("no_children\n");
	}
	else{
		printf("have_children\n");
	}
	printf("\n");
}

//????(???????)??????
int true_val(node *r, segment_tree *t){
	return (t->sum)((t->pro)(r->arg1, r->val), (t->rep_sum)(r->arg2, r->N));
}

//??????????(???????)?????
//????????????
void propagate(node *r, segment_tree *t){
	if(r->N > 1){
		if(r->left == NULL && r->right == NULL){
			r->left = make_node(r->N / 2, t);
			r->right = make_node(r->N / 2, t);
		}
		if(r->arg1 != t->e1 || r->arg2 != t->e0){
			argument_update(r->left, r->arg1, r->arg2, t);
			argument_update(r->right, r->arg1, r->arg2, t);
			r->val = true_val(r, t);
			r->arg1 = t->e1;
			r->arg2 = t->e0;
		}
	}
	else if(r->arg1 != t->e1 || r->arg2 != t->e0){
		r->val = true_val(r, t);
		r->arg1 = t->e1;
		r->arg2 = t->e0;
	}
}

//n???????2????
int next_exponent_of_2(int n){
	if(n == 0){
		return 1;
	}
	n |= (n >> 1);
	n |= (n >> 2);
	n |= (n >> 4);
	n |= (n >> 8);
	n |= (n >> 16);
//	n |= (n >> 32); //long long??
	return (n << 1) ^ n - 1;
}

void update_sub(int a, int b, int arg1, int arg2, node *r, segment_tree *t){
	if(r->N <= a || b <= 0){
		return;
	}
	else if(a <= 0 && r->N <= b){
//		printf("(arg1, arg2) = (%lld, %lld)\n", r->arg1, r->arg2);
		argument_update(r, arg1, arg2, t);
//		printf("(arg1, arg2) = (%lld, %lld)\n", r->arg1, r->arg2);
	}
	else{
		propagate(r, t);
		update_sub(a, b, arg1, arg2, r->left, t);
		update_sub(a - r->N / 2, b - r->N / 2, arg1, arg2, r->right, t);
		r->val = (t->sum)(true_val(r->left, t), true_val(r->right, t));
//		out_node(r->left);
//		out_node(r->right);
//		printf("true_val(r->left, t) = %lld\n", true_val(r->left, t));
//		printf("true_val(r->right, t) = %lld\n", true_val(r->right, t));
//		printf("(r->N, r->val) = (%lld, %lld)\n", r->N, r->val);
	}
}

int query_sub(int a, int b, node *r, segment_tree *t){
	if(r->N <= a || b <= 0){
		return t->e0;
	}
	else if(a <= 0 && r->N <= b){
		return true_val(r, t);
	}
	else if(r->left == NULL && r->right == NULL){
		return (t->rep_sum)(r->arg2, (b < r->N ? b : r->N) - (0 < a ? a : 0));
	}
	else{
		propagate(r, t);
		return (t->sum)(query_sub(a, b, r->left, t), query_sub(a - r->N / 2, b - r->N / 2, r->right, t));
	}
}

//?????e0
//?????e1
//????sum
//????pro
//?????rep_sum
//?segment_tree?????
//???, int?????????????
//????,
//int???????????(??????, ??????, ?????, ??????)
//int??????????(??????, ??????)
//??????
//???????????
segment_tree *make_segment_tree(int e0, int e1, int (*sum)(int x, int y), int (*pro)(int x, int y), int (*rep_sum)(int x, int N)){
	segment_tree *t = (segment_tree *)malloc(sizeof(segment_tree));
	t->root = NULL;
	t->e0 = e0;
	t->e1 = e1;
	t->sum = sum;
	t->pro = pro;
	t->rep_sum = rep_sum;
	return t;
}

//[a, b)???????arg1, arg2??????????
//arg1???????????????????arg2?????
//arg1???????????????????arg2??????
void update(int a, int b, int arg1, int arg2, segment_tree *t){
	if(t->root == NULL){
		t->root = make_node(next_exponent_of_2(b - 1), t);
	}
	else if(t->root->N < b){
		node *r = make_node(2 * t->root->N, t);
		r->val = true_val(t->root, t);
		r->left = t->root;
		r->right = make_node(r->left->N, t);
		t->root = r;
		update(a, b, arg1, arg2, t);
		return;
	}
	update_sub(a, b, arg1, arg2, t->root, t);
//	printf("(t->root->val, t->root->arg1, t->root->arg2) = (%lld, %lld)\n", t->root->val, t->root->arg1, t->root->arg2);
}

//[a, b)???????????
int query(int a, int b, segment_tree *t){
	if(t->root == NULL){
		return t->e0;
	}
	else{
		return query_sub(a, b, t->root, t);
	}
}

typedef struct {
	int l;
	int r;
	int c;
}light;

//????
int compare(datatype a, datatype b){
	return a.l - b.l;
}

//??
void sort_sub(datatype *origin, int left, int right, datatype *tmp){
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
			else if(compare(tmp[j], tmp[k]) <= 0 && j < half){
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

void sort(datatype *origin, int N){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	sort_sub(origin, 0, N, tmp);
	free(tmp);
}

signed main(){
	int N, L, l, r, c, i;
	scanf("%lld%lld", &N, &L);
	light *lights = (light *)malloc(sizeof(light) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld%lld", &lights[i].l, &lights[i].r, &lights[i].c);
	}
	sort(lights, N);
	segment_tree *t = make_segment_tree(inf, 0, &min, &sum, &rep_min);
	update(0, 1, inf, 0, t);
//	out_node(t->root);
	for(i = 0; i < N; i++){
//		printf("test3.5: i = %lld\n", i);
/*		int j;
		for(j = 0; j <= L; j++){
			printf("query(%lld, %lld, t) = %lld\n", j, j + 1, query(j, j + 1, t));
		}
*/		l = lights[i].l;
		r = lights[i].r;
		c = lights[i].c;
/*		printf("test3.8: (l, r, c) = (%lld, %lld, %lld)\n", l, r, c);
		printf("test3.9: query(%lld, %lld, t) = %lld\n", l, r, query(l, r, t));
*/		update(r, r + 1, 0, query(l, r, t) + c, t);
//		printf("\n");
	}
/*	out_node(t->root);
	out_node(t->root->left);
	out_node(t->root->right);
	out_node(t->root->left->left);
	out_node(t->root->left->right);
*/	printf("%lld\n", query(L, L + 1, t));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:262:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &L);
  ^
./Main.c:265:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &lights[i].l, &lights[i].r, &lights[i].c);
   ^