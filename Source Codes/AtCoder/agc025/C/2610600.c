#include <stdio.h>
#include <stdlib.h>
#define int long long
#define AVL_keytype pair
#define AVL_valtype int

typedef struct {
	int x;
	int num;
}pair;

int ABS(int a){
	return a >= 0 ? a : -a;
}

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
	if(a.x != b.x){
		return a.x - b.x;
	}
	else{
		return a.num - b.num;
	}
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
				AVL_node *ans_sub;
				newr = build_AVL_node(next_larger->key, next_larger->val, r->left, erase_AVL_sub(next_larger->key, r->right, &ans_sub));
				release_AVL_node(ans_sub);
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

int dis(int r, int l){
	if(r < 0){
		return -r;
	}
	else if(l < 0){
		return -l;
	}
	else{
		return 0;
	}
}

int next(int r, int l){
	if(r < 0){
		return r;
	}
	else if(l < 0){
		return -l;
	}
	else{
		return 0;
	}
}

signed main(){
	int N, i, f, now;
	scanf("%lld", &N);
	int *L = (int *)malloc(sizeof(int) * N);
	int *R = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &L[i], &R[i]);
	}

	AVL_tree *tL1 = make_AVL_tree();
	AVL_tree *tR1 = make_AVL_tree();
	AVL_node *r, *res;
	pair p;
	for(i = 0; i < N; i++){
		p.x = L[i];
		p.num = i;
		insert_AVL(p, 0, tL1);
	}
	for(i = 0; i < N; i++){
		p.x = R[i];
		p.num = i;
		insert_AVL(p, 0, tR1);
	}
	int ans1 = 0;
	for(f = 1, i = N, now = 0; i > 0; f *= -1, i--){
		if(f == 1){
			r = kth_smallest_AVL(i, tL1);
			ans1 += dis(R[r->key.num] - now, now - L[r->key.num]);
			now += next(R[r->key.num] - now, now - L[r->key.num]);
			p.x = L[r->key.num];
			p.num = r->key.num;
			res = erase_AVL(p, tL1);
			p.x = R[r->key.num];
			p.num = r->key.num;
			res = erase_AVL(p, tR1);
		}
		else{
			r = kth_smallest_AVL(1, tR1);
			ans1 += dis(R[r->key.num] - now, now - L[r->key.num]);
			now += next(R[r->key.num] - now, now - L[r->key.num]);
			p.x = L[r->key.num];
			p.num = r->key.num;
			res = erase_AVL(p, tL1);
			p.x = R[r->key.num];
			p.num = r->key.num;
			res = erase_AVL(p, tR1);
		}
//		printf("(i, now) = (%lld, %lld)\n", i, now);
	}
	ans1 += ABS(now);

	AVL_tree *tL2 = make_AVL_tree();
	AVL_tree *tR2 = make_AVL_tree();
	for(i = 0; i < N; i++){
		p.x = L[i];
		p.num = i;
		insert_AVL(p, 0, tL2);
	}
	for(i = 0; i < N; i++){
		p.x = R[i];
		p.num = i;
		insert_AVL(p, 0, tR2);
	}
	int rr, ll;
	int ans2 = 0;
	for(f = -1, i = N, now = 0; i > 0; f *= -1, i--){
		if(f == 1){
			r = kth_smallest_AVL(i, tL2);
			ans2 += dis(R[r->key.num] - now, now - L[r->key.num]);
			now += next(R[r->key.num] - now, now - L[r->key.num]);
			p.x = L[r->key.num];
			p.num = r->key.num;
			res = erase_AVL(p, tL2);
			p.x = R[r->key.num];
			p.num = r->key.num;
			res = erase_AVL(p, tR2);
		}
		else{
			r = kth_smallest_AVL(1, tR2);
			ans2 += dis(R[r->key.num] - now, now - L[r->key.num]);
			now += next(R[r->key.num] - now, now - L[r->key.num]);
			p.x = L[r->key.num];
			p.num = r->key.num;
			res = erase_AVL(p, tL2);
			p.x = R[r->key.num];
			p.num = r->key.num;
			res = erase_AVL(p, tR2);
		}
	}
	ans2 += ABS(now);
//	printf("ans1 = %lld\n", ans1);
//	printf("ans2 = %lld\n", ans2);
	printf("%lld\n", max(ans1, ans2));
	return 0;
} ./Main.c: In function ‘insert_AVL_sub’:
./Main.c:207:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘pair {aka struct <anonymous>}’ [-Wformat=]
    printf("In function 'insert_AVL_sub':\nkey '%d' already exists\n", key);
           ^
./Main.c: In function ‘outall_AVL_sub’:
./Main.c:270:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘pair {aka struct <anonymous>}’ [-Wformat=]
   printf("(key, val, ele_num, height) = (%d, %d, %d, %d)\n", r->key, r->val, r->ele_num, r->height);
          ^
./Main.c:270:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘long long int’ [-Wformat=]
./Main.c:270:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long long int’ [-Wformat=]
./Main.c:270:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 5 has type ‘long long int’ [-Wformat=]
./Main.c: In function ‘main’:
./Main.c:368:2: warning: ignoring return value of ‘scanf’, declare...