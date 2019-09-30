#include <stdio.h>
#include <stdlib.h>
#define datatype int


//??????
datatype sum(datatype a, datatype b){
	return a + b;
}

datatype pro(datatype a, datatype b){
	return a * b;
}

datatype rep_sum(datatype a, int N){
	return a * N;
}

typedef enum {
	false,
	true
}Boolean;

typedef struct node_sub node;

typedef struct {
	datatype (*update_function)(node *r, datatype arg1, datatype arg2); //????
	datatype arg1; //??????1??
	datatype arg2; //??????2??
}update_operation; //????

struct node_sub{
	int N; //????????(2??)
	datatype val; //?
	Boolean is_lazy; //true??????????
	update_operation upop; //??????????
	struct node_sub *left; //???, [0, N / 2)???
	struct node_sub *right; //???, [N / 2, N)???
}; //???

typedef struct {
	node *root; //????????????????
	datatype e; //??????
	datatype (*calc)(datatype x, datatype y); //??
	update_operation nuop; //not update operation, ?????????
}segment_tree;

//arg1???????????????????arg2?????
//arg1???????????????????arg2??????
datatype linear_function(node *r, datatype arg1, datatype arg2){
	return sum(pro(arg1, r->val), rep_sum(arg2, r->N));
}

//2????????????
//former?later???????
update_operation combine_update_operation(update_operation later, update_operation former){
	update_operation ans;
	if(later.update_function == &linear_function && former.update_function == &linear_function){
		ans.update_function = &linear_function;
		ans.arg1 = pro(later.arg1, former.arg1);
		ans.arg2 = sum(pro(later.arg1, former.arg2), later.arg2);
	}
	return ans;
}

//???N?????????
node *make_node(int N, segment_tree *t){
	node *r = (node *)malloc(sizeof(node));
	r->N = N;
	r->val = t->e;
	r->is_lazy = false;
	r->upop = t->nuop;
	r->left = NULL;
	r->right = NULL;
	return r;
}

//???????????
void out_node(node *r){
	printf("N = %d\n", r->N);
	printf("val = %d\n", r->val);
	if(r->is_lazy == true){
		printf("is_lazy\n");
	}
	else{
		printf("is_not_lazy\n");
	}
	if((r->upop).update_function == &linear_function){
		printf("linear_function(%d, %d)\n", (r->upop).arg1, (r->upop).arg2);
	}
	if(r->left == NULL && r->right == NULL){
		printf("no_children\n");
	}
	else{
		printf("have_children\n");
	}
}

//????(???????)??????
datatype true_val(node *r){
	return ((r->upop).update_function)(r, (r->upop).arg1, (r->upop).arg2);
}

//??????????(???????)?????
//????????????
void propagate(node *r, segment_tree *t){
	if(r->N > 1){
		if(r->left == NULL && r->right == NULL){
			r->left = make_node(r->N / 2, t);
			r->right = make_node(r->N / 2, t);
		}
		if(r->is_lazy == true){
			r->left->is_lazy = true;
			r->left->upop = combine_update_operation(r->upop, r->left->upop);
			r->right->is_lazy = true;
			r->right->upop = combine_update_operation(r->upop, r->right->upop);
		}
	}
	if(r->is_lazy == true){
		r->val = true_val(r);
		r->is_lazy = false;
		r->upop = t->nuop;
	}
}

//n???????2????
int next_exponent_of_2(int n){
	n |= (n >> 1);
	n |= (n >> 2);
	n |= (n >> 4);
	n |= (n >> 8);
	n |= (n >> 16);
//	n |= (n >> 32); //long long??
	return (n << 1) ^ n - 1;
}

void update_sub(int a, int b, update_operation upop, node *r, segment_tree *t){
	if(r->N <= a || b <= 0){
		return;
	}
	else if(a <= 0 && r->N <= b){
		r->is_lazy = true;
		r->upop = combine_update_operation(upop, r->upop);
	}
	else{
		propagate(r, t);
		update_sub(a, b, upop, r->left, t);
		update_sub(a - r->N / 2, b - r->N / 2, upop, r->right, t);
		r->val = (t->calc)(true_val(r->left), true_val(r->right));
	}
}

datatype query_sub(int a, int b, node *r, segment_tree *t){
	if(r->N <= a || b <= 0){
		return t->e;
	}
	else if(a <= 0 && r->N <= b){
		return true_val(r);
	}
	else{
		propagate(r, t);
		return (t->calc)(query_sub(a, b, r->left, t), query_sub(a - r->N / 2, b - r->N / 2, r->right, t));
	}
}

//???e, ??calc, ?????????nuop ?segment_tree?????
segment_tree *make_segment_tree(datatype e, datatype (*calc)(datatype x, datatype y), update_operation nuop){
	segment_tree *t = (segment_tree *)malloc(sizeof(segment_tree));
	t->root = NULL;
	t->e = e;
	t->calc = calc;
	t->nuop = nuop;
	return t;
}

//[a, b)????????upop???
void update(int a, int b, update_operation upop, segment_tree *t){
	if(t->root == NULL){
		t->root = make_node(next_exponent_of_2(b - 1), t);
	}
	else if(t->root->N < b){
		node *r = make_node(2 * t->root->N, t);
		r->val = t->root->val;
		r->left = t->root;
		r->right = make_node(r->left->N, t);
		t->root = r;
		update(a, b, upop, t);
		return;
	}
	update_sub(a, b, upop, t->root, t);
}

//[a, b)????????????
datatype query(int a, int b, segment_tree *t){
	if(t->root == NULL){
		return t->e;
	}
	else{
		return query_sub(a, b, t->root, t);
	}
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int N, i;
	long long ans = 0;
	scanf("%d", &N);
	int *B = (int *)malloc(sizeof(int) * N);
	int *B_inv = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &B[i]);
		B[i]--;
		B_inv[B[i]] = i;
	}
	update_operation upop;
	upop.update_function = &linear_function;
	upop.arg1 = 1;
	upop.arg2 = 0;
	segment_tree *t = make_segment_tree(0, &sum, upop);
	upop.arg1 = 0;
	upop.arg2 = 1;
	update(0, N, upop, t);
	upop.arg1 = 0;
	upop.arg2 = 0;
	for(i = 0; i < N; i++){
		ans += min(query(0, B_inv[i], t), query(B_inv[i] + 1, N, t));
		update(B_inv[i], B_inv[i] + 1, upop, t);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:215:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:219:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &B[i]);
   ^