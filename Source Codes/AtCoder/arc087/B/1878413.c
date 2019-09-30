#include <stdio.h>
#include <stdlib.h>
#define max_size 8001
#define AVL_keytype int
#define AVL_valtype int
#define ms_valtype int

//????
int compare_ms(ms_valtype a, ms_valtype b){
	return a - b;
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
	if(a > b){
		return a;
	}
	else{
		return b;
	}
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
//			printf("In function 'insert_AVL_sub':\nkey '%d' already exists\n", key);
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

AVL_node *erase_AVL_sub(AVL_keytype key, AVL_node *r){
	AVL_node *newr;
	if(r == NULL){
		printf("In function 'erase_AVL_sub':\nkey '%d' doesn't exist\n", key);
		newr = NULL;
	}
	else{
		int comp = compare_AVL(key, r->key);
		if(comp == 0){
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
				newr = build_AVL_node(next_larger->key, next_larger->val, r->left, erase_AVL_sub(next_larger->key, r->right));
			}
		}
		else if(comp < 0){
			newr = build_AVL_node(r->key, r->val, erase_AVL_sub(key, r->left), r->right);
		}
		else{
			newr = build_AVL_node(r->key, r->val, r->left, erase_AVL_sub(key, r->right));
		}
		release_AVL_node(r);
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

//???key?????????
//?????????????(????????)
void erase_AVL(AVL_keytype key, AVL_tree *t){
	t->root = erase_AVL_sub(key, t->root);
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

int ABS(int x){
	return x >= 0 ? x : -x;
}

int main(){
	int N, x, y, i, j, direction = 1;
	char *s = (char *)malloc(sizeof(char) * max_size);
	scanf("%s", s);
	for(i = 0; s[i] != '\0'; i++){}
	N = i;
	scanf("%d%d", &x, &y);
	for(i = 0; i < N; i++){
		if(s[i] == 'T'){
			x -= i;
			break;
		}
	}
	if(i == N){
		if(x == N && y == 0){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
		return 0;
	}
	int *side = (int *)malloc(sizeof(int) * N);
	int *vertical = (int *)malloc(sizeof(int) * N);
	for(j = 0; j < N; j++){
		side[j] = 0;
		vertical[j] = 0;
	}
	int side_num = 0, vertical_num = 0;
	for(i++; i < N; i++){
		if(s[i] == 'F'){
			if(direction == 0){
				side[side_num]++;
			}
			else{
				vertical[vertical_num]++;
			}
		}
		else{
			if(direction == 0){
				side_num++;
			}
			else{
				vertical_num++;
			}
			direction = 1 - direction;
		}
	}
	if(direction == 0){
		side_num++;
	}
	else{
		vertical_num++;
	}
	sort(side, side_num);
	sort(vertical, vertical_num);
/*	printf("side_num = %d\n", side_num);
	for(i = 0; i < side_num; i++){
		printf("side[%d] = %d\n", i, side[i]);
	}
	printf("vertical_num = %d\n", vertical_num);
	for(i = 0; i < vertical_num; i++){
		printf("vertical[%d] = %d\n", i, vertical[i]);
	}
*/	AVL_tree *t0_new = make_AVL_tree();
	AVL_tree *t0_old;
	AVL_tree *t1_new = make_AVL_tree();
	AVL_tree *t1_old;
	AVL_node *r, *r_new;
	insert_AVL(0, 1, t0_new);
	insert_AVL(0, 1, t1_new);
	for(i = 0; i < side_num; i++){
		t0_old = t0_new;
		t0_new = make_AVL_tree();
		while(element_num_AVL(t0_old) > 0){
			r = kth_smallest_AVL(1, t0_old);
			insert_AVL(ABS(r->key + side[i]), 1, t0_new);
			insert_AVL(ABS(r->key - side[i]), 1, t0_new);
			erase_AVL(r->key, t0_old);
		}
	}
	for(i = 0; i < vertical_num; i++){
		t1_old = t1_new;
		t1_new = make_AVL_tree();
		while(element_num_AVL(t1_old) > 0){
			r = kth_smallest_AVL(1, t1_old);
			insert_AVL(ABS(r->key + vertical[i]), 1, t1_new);
			insert_AVL(ABS(r->key - vertical[i]), 1, t1_new);
			erase_AVL(r->key, t1_old);
		}
	}
	if(find_AVL(ABS(x), t0_new) != NULL && find_AVL(ABS(y), t1_new) != NULL){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:372:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", s);
  ^
./Main.c:375:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &x, &y);
  ^