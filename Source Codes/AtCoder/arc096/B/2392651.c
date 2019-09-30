#include <stdio.h>
#include <stdlib.h>
#define int long long
#define lust_valtype int

//?
lust_valtype sum(lust_valtype a, lust_valtype b);

//?
lust_valtype pro(lust_valtype a, lust_valtype b);

//a?N??????????
lust_valtype rep_sum(lust_valtype a, int N);

//min?+
#define inf (int)(1e18)

lust_valtype max(lust_valtype a, lust_valtype b){
	if(a >= b){
		return a;
	}
	else{
		return b;
	}
}

lust_valtype sum(lust_valtype a, lust_valtype b){
	if(a <= -inf || b <= -inf){
		return -inf;
	}
	else{
		return a + b;
	}
}

lust_valtype rep_max(lust_valtype a, int N){
	return a;
}



int malloc_count = 0;

typedef struct node_sub{
	int N; //????????(2??)
	lust_valtype val; //?
	lust_valtype arg1; //??????1??
	lust_valtype arg2; //??????2??
	struct node_sub *left; //???, [0, N / 2)???
	struct node_sub *right; //???, [N / 2, N)???
}node; //???

typedef struct {
	node *root; //????????????????
	lust_valtype e0; //?????
	lust_valtype e1; //?????
	lust_valtype (*sum)(lust_valtype x, lust_valtype y); //????
	lust_valtype (*pro)(lust_valtype x, lust_valtype y); //????
	lust_valtype (*rep_sum)(lust_valtype x, int N); //?????
}segment_tree;

//???r??????????
void argument_update(node *r, lust_valtype arg1, lust_valtype arg2, segment_tree *t){
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
lust_valtype true_val(node *r, segment_tree *t){
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

void update_sub(int a, int b, lust_valtype arg1, lust_valtype arg2, node *r, segment_tree *t){
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

lust_valtype query_sub(int a, int b, node *r, segment_tree *t){
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
//???, lust_valtype?????????????
//????,
//lust_valtype???????????(??????, ??????, ?????, ??????)
//lust_valtype??????????(??????, ??????)
//??????
//???????????
segment_tree *make_segment_tree(lust_valtype e0, lust_valtype e1, lust_valtype (*sum)(lust_valtype x, lust_valtype y), lust_valtype (*pro)(lust_valtype x, lust_valtype y), lust_valtype (*rep_sum)(lust_valtype x, int N)){
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
void update(int a, int b, lust_valtype arg1, lust_valtype arg2, segment_tree *t){
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
lust_valtype query(int a, int b, segment_tree *t){
	if(t->root == NULL){
		return t->e0;
	}
	else{
		return query_sub(a, b, t->root, t);
	}
}

signed main(){
	int N, C, i;
	scanf("%lld%lld", &N, &C);
	int *x = (int *)malloc(sizeof(int) * (N + 1));
	int *v = (int *)malloc(sizeof(int) * (N + 1));
	x[0] = 0;
	v[0] = 0;
	for(i = 1; i <= N; i++){
		scanf("%lld%lld", &x[i], &v[i]);
	}
	int *vsum = (int *)malloc(sizeof(int) * (N + 1));
	vsum[0] = 0;
	for(i = 1; i <= N; i++){
		vsum[i] = vsum[i - 1] + v[i];
	}
	int *dv = (int *)malloc(sizeof(int) * (N + 1));
	for(i = 0; i <= N; i++){
		vsum[i] = vsum[i] - x[i];
		dv[i] = vsum[i] - x[i];
	}

	int *xR = (int *)malloc(sizeof(int) * (N + 1));
	int *vR = (int *)malloc(sizeof(int) * (N + 1));
	xR[0] = 0;
	vR[0] = 0;
	for(i = 1; i <= N; i++){
		xR[i] = C - x[N - i + 1];
		vR[i] = v[N - i + 1];
	}
	int *vsumR = (int *)malloc(sizeof(int) * (N + 1));
	vsumR[0] = 0;
	for(i = 1; i <= N; i++){
		vsumR[i] = vsumR[i - 1] + vR[i];
	}
	int *dvR = (int *)malloc(sizeof(int) * (N + 1));
	for(i = 0; i <= N; i++){
		vsumR[i] = vsumR[i] - xR[i];
		dvR[i] = vsumR[i] - xR[i];
	}

	int ans = 0;
	segment_tree *t = make_segment_tree(-inf, 0, max, sum, rep_max);
	for(i = 0; i <= N; i++){
		update(i, i + 1, -inf, vsumR[i], t);
	}
	for(i = 0; i <= N; i++){
		ans = max(ans, dv[i] + query(0, N - i + 1, t));
	}

	for(i = 0; i <= N; i++){
		update(i, i + 1, -inf, vsum[i], t);
	}
	for(i = 0; i <= N; i++){
		ans = max(ans, dvR[i] + query(0, N - i + 1, t));
	}

	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘out_node’:
./Main.c:83:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("N = %d\n", r->N);
         ^
./Main.c:84:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("val = %d\n", r->val);
         ^
./Main.c:85:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("arg1 = %d\n", r->arg1);
         ^
./Main.c:86:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("arg2 = %d\n", r->arg2);
         ^
./Main.c: In function ‘main’:
./Main.c:223:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &C);
  ^
./Main.c:229:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &x[i], &v...