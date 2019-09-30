#include <stdio.h>
#include <stdlib.h>
#define int long long
#define AVL_keytype int
#define AVL_valtype int


//static int malloc_cont;
//static int free_cont;

typedef struct AVL_node_sub{
	AVL_keytype key; //???
	AVL_valtype val; //?
	int ele_num; //?????????
	int height; //????
	struct AVL_node_sub *left; //?????????
	struct AVL_node_sub *right; //?????????
}AVL_node;

typedef struct {
	AVL_node *root;
}AVL_tree;

int max(int a, int b){
	return a >= b ? a : b;
}

//????
//a < b ?????
//a = b ??0
//a > b ?????
int compare_AVL(AVL_keytype a, AVL_keytype b){
	return a - b;
}

int ele_num(AVL_node *r){
	if(r == NULL){
		return 0;
	}
	else{
		return r->ele_num;
	}
}

int height(AVL_node *r){
	if(r == NULL){
		return 0;
	}
	else{
		return r->height;
	}
}

//t???????????
//AVL_valtype??????????????free??
void release_AVL_node(AVL_node *r){
	free(r);
//	free_cont++;
}

AVL_node *build_AVL_node(AVL_keytype key, AVL_valtype val, AVL_node *left, AVL_node *right){
	AVL_node *newr;
	int left_h = height(left);
	int right_h = height(right);
	if(left_h > right_h + 1){
		AVL_node *ll = left->left;
		AVL_node *lr = left->right;
		if(height(ll) < height(lr)){
			newr = build_AVL_node(lr->key, lr->val, build_AVL_node(left->key, left->val, ll, lr->left), build_AVL_node(key, val, lr->right, right));
			release_AVL_node(lr);
		}
		else{
			newr = build_AVL_node(left->key, left->val, ll, build_AVL_node(key, val, lr, right));
		}
		release_AVL_node(left);
	}
	else if(right_h > left_h + 1){
		AVL_node *rr = right->right;
		AVL_node *rl = right->left;
		if(height(rr) < height(rl)){
			newr = build_AVL_node(rl->key, rl->val, build_AVL_node(key, val, left, rl->left), build_AVL_node(right->key, right->val, rl->right, rr));
			release_AVL_node(rl);
		}
		else{
			newr = build_AVL_node(right->key, right->val, build_AVL_node(key, val, left, rl), rr);
		}
		release_AVL_node(right);
	}
	else{
//		malloc_cont++;
		newr = (AVL_node *)malloc(sizeof(AVL_node));
		newr->key = key;
		newr->val = val;
		newr->ele_num = ele_num(left) + ele_num(right) + 1;
		newr->height = max(left_h, right_h) + 1;
		newr->left = left;
		newr->right = right;
	}
	return newr;
}

AVL_node *find_AVL_sub(AVL_keytype key, AVL_node *r){
	if(r == NULL){
		return NULL;
	}
	int comp = compare_AVL(key, r->key);
	if(comp == 0){
		return r;
	}
	else if(comp < 0){
		return find_AVL_sub(key, r->left);
	}
	else{
		return find_AVL_sub(key, r->right);
	}
}

AVL_node *kth_smallest_AVL_sub(int k, AVL_node *r){
	if(r == NULL || k < 1){
		printf("In function 'kth_smallest_AVL_sub':\nargument 'k' is out of range\n");
		return NULL;
	}
	else if(r->ele_num < k){
		printf("In function 'kth_smallest_AVL_sub':\nargument 'k' is out of range\n");
		return NULL;
	}
	else if(ele_num(r->left) == k - 1){
		return r;
	}
	else if(ele_num(r->left) > k - 1){
		return kth_smallest_AVL_sub(k, r->left);
	}
	else{
		return kth_smallest_AVL_sub(k - ele_num(r->left) - 1, r->right);
	}
}

int num_less_than_AVL_sub(AVL_keytype key, AVL_node *r){
	if(r == NULL){
		return 0;
	}
	else if(compare_AVL(key, r->key) < 0){
		return num_less_than_AVL_sub(key, r->left);
	}
	else{
		return ele_num(r->left) + num_less_than_AVL_sub(key, r->right) + 1;
	}
}

AVL_node *next_largest_AVL_sub(AVL_keytype key, AVL_node *r){
	if(r == NULL){
		return NULL;
	}
	else if(compare_AVL(key, r->key) <= 0){
		return next_largest_AVL_sub(key, r->left);
	}
	else{
		AVL_node *candidate = next_largest_AVL_sub(key, r->right);
		if(candidate == NULL){
			return r;
		}
		else{
			return candidate;
		}
	}
}

AVL_node *next_smallest_AVL_sub(AVL_keytype key, AVL_node *r){
	if(r == NULL){
		return NULL;
	}
	else if(compare_AVL(key, r->key) >= 0){
		return next_smallest_AVL_sub(key, r->right);
	}
	else{
		AVL_node *candidate = next_smallest_AVL_sub(key, r->left);
		if(candidate == NULL){
			return r;
		}
		else{
			return candidate;
		}
	}
}

AVL_node *insert_AVL_sub(AVL_keytype key, AVL_valtype val, AVL_node *r){
	AVL_node *newr;
	if(r == NULL){
		newr = build_AVL_node(key, val, NULL, NULL);
	}
	else{
		int comp = compare_AVL(key, r->key);
		if(comp == 0){
			printf("In function 'insert_AVL_sub':\nkey '%d' already exists\n", key);
			newr = build_AVL_node(r->key, val, r->left, r->right);
		}
		else if(comp < 0){
			newr = build_AVL_node(r->key, r->val, insert_AVL_sub(key, val, r->left), r->right);
		}
		else{
			newr = build_AVL_node(r->key, r->val, r->left, insert_AVL_sub(key, val, r->right));
		}
		release_AVL_node(r);
	}
	return newr;
}

AVL_node *erase_AVL_sub_sub(AVL_node *r){
	if(r->left == NULL){
		return r->right;
	}
	else{
		return build_AVL_node(r->key, r->val, erase_AVL_sub_sub(r->left), r->right);
	}
}

AVL_node *erase_AVL_sub(AVL_keytype key, AVL_node *r, AVL_node **ans){
	AVL_node *newr;
	if(r == NULL){
		newr = NULL;
	}
	else{
		int comp = compare_AVL(key, r->key);
		if(comp == 0){
			*ans = r;
			if(r->left == NULL && r->right == NULL){
				newr = NULL;
			}
			else if(r->right == NULL){
				newr = r->left;
			}
			else if(r->left == NULL){
				newr = r->right;
			}
			else{
				AVL_node *next_larger = kth_smallest_AVL_sub(1, r->right);
				newr = build_AVL_node(next_larger->key, next_larger->val, r->left, erase_AVL_sub_sub(r->right));
				release_AVL_node(next_larger);
			}
		}
		else{
			if(comp < 0){
				newr = build_AVL_node(r->key, r->val, erase_AVL_sub(key, r->left, ans), r->right);
			}
			else{
				newr = build_AVL_node(r->key, r->val, r->left, erase_AVL_sub(key, r->right, ans));
			}
			release_AVL_node(r);
		}
	}
	return newr;
}

void storeall_AVL_sub(AVL_keytype *array, int k, AVL_node *r){
	if(r != NULL){
		storeall_AVL_sub(array, k, r->left);
		array[k + ele_num(r->left)] = r->key;
		storeall_AVL_sub(array, k + ele_num(r->left) + 1, r->right);
	}
}

void outall_AVL_sub(AVL_node *r){
	if(r != NULL){
		outall_AVL_sub(r->left);
		printf("(key, val, ele_num, height) = (%d, %d, %d, %d)\n", r->key, r->val, r->ele_num, r->height);
		outall_AVL_sub(r->right);
	}
}

//AVL_tree?????
AVL_tree *make_AVL_tree(){
	AVL_tree *t = (AVL_tree *)malloc(sizeof(AVL_tree));
	t->root = NULL;
	return t;
}

//t?????????????
int element_num_AVL(AVL_tree *t){
	return ele_num(t->root);
}

//????key?????????????
//????NULL???
AVL_node *find_AVL(AVL_keytype key, AVL_tree *t){
	return find_AVL_sub(key, t->root);
}

//?????k???key?????????????
//1 ? k ? ele_num(t->root) ?????????NULL???(????????)
AVL_node *kth_smallest_AVL(int k, AVL_tree *t){
	return kth_smallest_AVL_sub(k, t->root);
}

//????key???????????
int num_less_than_AVL(AVL_keytype key, AVL_tree *t){
	return num_less_than_AVL_sub(key, t->root);
}

//key???????????????????????????
//????NULL???
AVL_node *next_largest_AVL(AVL_keytype key, AVL_tree *t){
	return next_largest_AVL_sub(key, t->root);
}

//key???????????????????????????
//????NULL???
AVL_node *next_smallest_AVL(AVL_keytype key, AVL_tree *t){
	return next_smallest_AVL_sub(key, t->root);
}

//???key, ?val?????????
//?????????????????(????????)
void insert_AVL(AVL_keytype key, AVL_valtype val, AVL_tree *t){
	t->root = insert_AVL_sub(key, val, t->root);
}

//???key?????????????
//????????NULL???
AVL_node *erase_AVL(AVL_keytype key, AVL_tree *t){
	AVL_node *ans = NULL;
	t->root = erase_AVL_sub(key, t->root, &ans);
	return ans;
}

//?????key???????????????
AVL_keytype *storeall_AVL(AVL_tree *t){
	AVL_keytype *array = (AVL_keytype *)malloc(sizeof(AVL_keytype) * element_num_AVL(t));
	storeall_AVL_sub(array, 0, t->root);
	return array;
}

//????????key??????????
void outall_AVL(AVL_tree *t){
	outall_AVL_sub(t->root);
}

typedef struct _node node;

struct _node{
	int i;
	int j;
	struct _node *next;
};

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a % b);
	}
}

int lcm(int a, int b){
	return (a / gcd(a, b)) * b;
}

int is_prime(int n){
	int i;
	for(i = 2; i * i <= n; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

signed main(){
	int N, i, j, k;
	scanf("%lld", &N);
	int **A = (int **)malloc(sizeof(int *) * (N + 2));
	for(i = 0; i <= N + 1; i++){
		A[i] = (int *)malloc(sizeof(int) * (N + 2));
		for(j = 0; j <= N + 1; j++){
			A[i][j] = 1;
		}
	}
//	printf("test1\n");
	int *b = (int *)malloc(sizeof(int) * (N + 2));
	int *c = (int *)malloc(sizeof(int) * (N + 2));
	for(i = 1, j = 3; i <= N; i++, j++){
		if(i % 2 == 1){
			while(is_prime(j) == 0){
				j++;
			}
			b[i] = j;
		}
		else{
			b[i] = b[i - 1];
			j--;
		}
		c[i] = b[i];
/*		if(((i - 1) / 2) % 2 == 0){
			b[i] = N / 2 - (i - 1) / 4;
		}
		else{
			b[i] = (i + 5) / 4;
		}
		c[i] = b[i];
*/
//		b[i] = (i + 1) / 2 + 1;
//		c[i] = (i + 1) / 2 + 1;
	}
/*	for(i = 1; i <= N; i++){
		printf("b[%lld] = %lld\n", i, b[i]);
	}
*/	
/*	int max_val1 = 200000;
	node **nodes = (node **)malloc(sizeof(node *) * (max_val1 + 1));
	for(i = 0; i <= max_val1; i++){
		nodes[i] = NULL;
	}
	node *node_sub;
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			if((i + j) % 2 == 0){
				A[i][j] = b[i] * c[j];
				node_sub = nodes[A[i][j]];
				nodes[A[i][j]] = (node *)malloc(sizeof(node));
				nodes[A[i][j]]->i = i;
				nodes[A[i][j]]->j = j;
				nodes[A[i][j]]->next = node_sub;
			}
		}
	}
*/
	AVL_tree *t = make_AVL_tree();
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			if((i + j) % 2 == 0){
				A[i][j] = b[i] * c[j];
				if(i > j){
					A[i][j] += 2 * b[i] * c[j];
				}
				if(i % 2 == 0){
					A[i][j] += b[i] * c[j];
				}
				insert_AVL(A[i][j], 1, t);
			}
		}
	}
//	printf("test3\n");
/*	for(i = 0; i <= max_val1; i++){
		for(node_sub = nodes[i], j = 1; node_sub != NULL; node_sub = node_sub->next, j++){
			if(j > 1){
				while((i * j <= max_val1 && nodes[i * j] != NULL) || find_AVL(i * j, t) != NULL){
					j++;
				}
			}
			A[node_sub->i][node_sub->j] = i * j;
			insert_AVL(i * j, 1, t);
		}
	}
*/
//	printf("test4\n");
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
//			printf("(i, j) = (%lld, %lld)\n", i, j);
			if((i + j) % 2 == 1){
				A[i][j] = lcm(lcm(A[i - 1][j], A[i + 1][j]), lcm(A[i][j - 1], A[i][j + 1]));
				for(k = 1; find_AVL(A[i][j] * k + 1, t) != NULL; k++){}
				A[i][j] = A[i][j] * k + 1;
				insert_AVL(A[i][j], 1, t);
			}
		}
	}
	int maxA = 0;
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			if(A[i][j] > maxA){
				maxA = A[i][j];
			}
		}
	}
//	printf("maxA = %lld\n", maxA);
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			printf("%lld ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘insert_AVL_sub’:
./Main.c:194:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
    printf("In function 'insert_AVL_sub':\nkey '%d' already exists\n", key);
           ^
./Main.c: In function ‘outall_AVL_sub’:
./Main.c:265:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
   printf("(key, val, ele_num, height) = (%d, %d, %d, %d)\n", r->key, r->val, r->ele_num, r->height);
          ^
./Main.c:265:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘long long int’ [-Wformat=]
./Main.c:265:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long long int’ [-Wformat=]
./Main.c:265:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 5 has type ‘long long int’ [-Wformat=]
./Main.c: In function ‘main’:
./Main.c:370:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_res...