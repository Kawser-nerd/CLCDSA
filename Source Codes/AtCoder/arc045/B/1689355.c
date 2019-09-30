#include <stdio.h>
#include <stdlib.h>
#define datatype int
#define inf (int)(1e9 + 7)

datatype min(datatype a, datatype b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

datatype sum(datatype a, datatype b){
	if(a >= inf || b >= inf){
		return inf;
	}
	else{
		return a + b;
	}
}

datatype rep_min(datatype a, int N){
	return a;
}




int malloc_count = 0;

typedef struct node_sub{
	int N; //????????(2??)
	datatype val; //?
	datatype arg1; //??????1??
	datatype arg2; //??????2??
	struct node_sub *left; //???, [0, N / 2)???
	struct node_sub *right; //???, [N / 2, N)???
}node; //???

typedef struct {
	node *root; //????????????????
	datatype e0; //?????
	datatype e1; //?????
	datatype (*sum)(datatype x, datatype y); //????
	datatype (*pro)(datatype x, datatype y); //????
	datatype (*rep_sum)(datatype x, int N); //?????
}segment_tree;

//???r??????????
void argument_update(node *r, datatype arg1, datatype arg2, segment_tree *t){
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
	printf("N = %d\n", r->N);
	printf("val = %d\n", r->val);
	printf("arg1 = %d\n", r->arg1);
	printf("arg2 = %d\n", r->arg2);
	if(r->left == NULL && r->right == NULL){
		printf("no_children\n");
	}
	else{
		printf("have_children\n");
	}
	printf("\n");
}

//????(???????)??????
datatype true_val(node *r, segment_tree *t){
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

void update_sub(int a, int b, datatype arg1, datatype arg2, node *r, segment_tree *t){
	if(r->N <= a || b <= 0){
		return;
	}
	else if(a <= 0 && r->N <= b){
		argument_update(r, arg1, arg2, t);
	}
	else{
		propagate(r, t);
		update_sub(a, b, arg1, arg2, r->left, t);
		update_sub(a - r->N / 2, b - r->N / 2, arg1, arg2, r->right, t);
		r->val = (t->sum)(true_val(r->left, t), true_val(r->right, t));
	}
}

datatype query_sub(int a, int b, node *r, segment_tree *t){
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
//???, datatype?????????????
//????,
//datatype???????????(??????, ??????, ?????, ??????)
//datatype??????????(??????, ??????)
//??????
//???????????
segment_tree *make_segment_tree(datatype e0, datatype e1, datatype (*sum)(datatype x, datatype y), datatype (*pro)(datatype x, datatype y), datatype (*rep_sum)(datatype x, int N)){
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
void update(int a, int b, datatype arg1, datatype arg2, segment_tree *t){
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
}

//[a, b)???????????
datatype query(int a, int b, segment_tree *t){
	if(t->root == NULL){
		return t->e0;
	}
	else{
		return query_sub(a, b, t->root, t);
	}
}

int main(){
	int N, M, i, k = 0;
	scanf("%d%d", &N, &M);
	segment_tree *seg_t = make_segment_tree(inf, 0, min, sum, rep_min);
	update(1, N + 1, 0, 0, seg_t);
	int *s = (int *)malloc(sizeof(int) * M);
	int *t = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		scanf("%d%d", &s[i], &t[i]);
		update(s[i], t[i] + 1, 1, inf, seg_t);
	}
/*	printf("test:\n");
	for(i = 1; i <= N; i++){
		printf("%d\n", query(i, i + 1, seg_t));
	}
	printf("\n");
*/	int *ans = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		if(query(s[i], t[i] + 1, seg_t) > 1){
			ans[k] = i + 1;
			k++;
		}
	}
	printf("%d\n", k);
	for(i = 0; i < k; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:212:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:218:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &s[i], &t[i]);
   ^