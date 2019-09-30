#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define keytype pos

//static int malloc_cont;
//static int free_cont;

typedef struct {
	int x;
	int y;
}pos;

typedef struct {
	int L;
	int R;
	int U;
	int D;
}datatype;

typedef struct node_sub{
	keytype key; //???
	datatype val; //?
	int ele_num; //?????????
	int height; //????
	struct node_sub *left; //?????????
	struct node_sub *right; //?????????
}node;

typedef struct {
	node *root;
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
int compare(keytype a, keytype b){
	if(a.x == b.x){
		return a.y - b.y;
	}
	else{
		return a.x - b.x;
	}
}

int ele_num(node *r){
	if(r == NULL){
		return 0;
	}
	else{
		return r->ele_num;
	}
}

int height(node *r){
	if(r == NULL){
		return 0;
	}
	else{
		return r->height;
	}
}

//t???????????
//datatype??????????????free??
void release(node *r){
	free(r);
//	free_cont++;
}

node *build_node(keytype key, datatype val, node *left, node *right){
	node *newr;
	int left_h = height(left);
	int right_h = height(right);
	if(left_h > right_h + 1){
		node *ll = left->left;
		node *lr = left->right;
		if(height(ll) < height(lr)){
			newr = build_node(lr->key, lr->val, build_node(left->key, left->val, ll, lr->left), build_node(key, val, lr->right, right));
			release(lr);
		}
		else{
			newr = build_node(left->key, left->val, ll, build_node(key, val, lr, right));
		}
		release(left);
	}
	else if(right_h > left_h + 1){
		node *rr = right->right;
		node *rl = right->left;
		if(height(rr) < height(rl)){
			newr = build_node(rl->key, rl->val, build_node(key, val, left, rl->left), build_node(right->key, right->val, rl->right, rr));
			release(rl);
		}
		else{
			newr = build_node(right->key, right->val, build_node(key, val, left, rl), rr);
		}
		release(right);
	}
	else{
//		malloc_cont++;
		newr = (node *)malloc(sizeof(node));
		newr->key = key;
		newr->val = val;
		newr->ele_num = ele_num(left) + ele_num(right) + 1;
		newr->height = max(left_h, right_h) + 1;
		newr->left = left;
		newr->right = right;
	}
	return newr;
}

node *find_sub(keytype key, node *r){
	if(r == NULL){
		return NULL;
	}
	int comp = compare(key, r->key);
	if(comp == 0){
		return r;
	}
	else if(comp < 0){
		return find_sub(key, r->left);
	}
	else{
		return find_sub(key, r->right);
	}
}

node *kth_smallest_sub(int k, node *r){
	if(r == NULL || k < 1){
		printf("In function 'kth_smallest_sub':\nargument 'k' is out of range\n");
		return NULL;
	}
	else if(r->ele_num < k){
		printf("In function 'kth_smallest_sub':\nargument 'k' is out of range\n");
		return NULL;
	}
	else if(ele_num(r->left) == k - 1){
		return r;
	}
	else if(ele_num(r->left) > k - 1){
		return kth_smallest_sub(k, r->left);
	}
	else{
		return kth_smallest_sub(k - ele_num(r->left) - 1, r->right);
	}
}

node *insert_sub(keytype key, datatype val, node *r){
	node *newr;
	if(r == NULL){
		newr = build_node(key, val, NULL, NULL);
	}
	else{
		int comp = compare(key, r->key);
		if(comp == 0){
			printf("In function 'insert_sub':\nkey '%d' already exists\n", key);
			newr = build_node(r->key, val, r->left, r->right);
		}
		else if(comp < 0){
			newr = build_node(r->key, r->val, insert_sub(key, val, r->left), r->right);
		}
		else{
			newr = build_node(r->key, r->val, r->left, insert_sub(key, val, r->right));
		}
		release(r);
	}
	return newr;
}

node *erase_sub(keytype key, node *r){
	node *newr;
	if(r == NULL){
		printf("In function 'erase_sub':\nkey '%d' doesn't exist\n", key);
		newr = NULL;
	}
	else{
		int comp = compare(key, r->key);
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
				node *next_larger = kth_smallest_sub(1, r->right);
				newr = build_node(next_larger->key, next_larger->val, r->left, erase_sub(next_larger->key, r->right));
			}
		}
		else if(comp < 0){
			newr = build_node(r->key, r->val, erase_sub(key, r->left), r->right);
		}
		else{
			newr = build_node(r->key, r->val, r->left, erase_sub(key, r->right));
		}
		release(r);
	}
	return newr;
}

void storeall_sub(keytype *array, int k, node *r){
	if(r != NULL){
		storeall_sub(array, k, r->left);
		array[k + ele_num(r->left)] = r->key;
		storeall_sub(array, k + ele_num(r->left) + 1, r->right);
	}
}

void outall_sub(node *r){
	if(r != NULL){
		outall_sub(r->left);
		pos p = r->key;
		datatype val = r->val;
		printf("(x, y) = (%d, %d)\n", p.x, p.y);
		printf("(L, R, U, D) = (%d, %d, %d, %d)\n", val.L, val.R, val.U, val.D);
		outall_sub(r->right);
	}
}

//AVL_tree?????
AVL_tree *make_AVL_tree(){
	AVL_tree *t = (AVL_tree *)malloc(sizeof(AVL_tree));
	t->root = NULL;
	return t;
}

//t?????????????
int element_num(AVL_tree *t){
	return ele_num(t->root);
}

//????key?????????????
//????NULL???
node *find(keytype key, AVL_tree *t){
	return find_sub(key, t->root);
}

//?????k???key?????????????
//1 ? k ? ele_num(t->root) ?????????NULL???(????????)
node *kth_smallest(int k, AVL_tree *t){
	return kth_smallest_sub(k, t->root);
}

//???key, ?val?????????
//?????????????????(????????)
void insert(keytype key, datatype val, AVL_tree *t){
	t->root = insert_sub(key, val, t->root);
}

//???key?????????
//?????????????(????????)
void erase(keytype key, AVL_tree *t){
	t->root = erase_sub(key, t->root);
}

//?????key???????????????
keytype *storeall(AVL_tree *t){
	keytype *array = (keytype *)malloc(sizeof(keytype) * element_num(t));
	storeall_sub(array, 0, t->root);
	return array;
}

//????????key??????????
void outall(AVL_tree *t){
	outall_sub(t->root);
}

int main(){
	int K, i;
	node *r, *rL, *rR, *rU, *rD;
	pos p, p_sub;
	datatype val;
	scanf("%d", &K);
	char *S = (char *)malloc(sizeof(char) * (K + 1));
	scanf("%s", S);
	AVL_tree *t = make_AVL_tree();
	p.x = 0;
	p.y = 0;
	val.L = 1;
	val.R = 1;
	val.U = 1;
	val.D = 1;
	insert(p, val, t);
	r = find(p, t);
	for(i = 0; i < K; i++){
		p = r->key;
		if(S[i] == 'L'){
			p.x -= (r->val).L;
		}
		else if(S[i] == 'R'){
			p.x += (r->val).R;
		}
		else if(S[i] == 'U'){
			p.y += (r->val).U;
		}
		else{
			p.y -= (r->val).D;
		}
		p_sub = p;
		p_sub.x -= 1;
		rL = find(p_sub, t);
		p_sub.x += 2;
		rR = find(p_sub, t);
		p_sub.x -= 1;
		p_sub.y += 1;
		rU = find(p_sub, t);
		p_sub.y -= 2;
		rD = find(p_sub, t);
		p_sub.y += 1;

		p_sub = p;
		if(rL == NULL && rR == NULL){
			val.L = 1;
			val.R = 1;
		}
		else if(rL == NULL){
			val.L = 1;
			val.R = (rR->val).R + 1;
			p_sub.x = p.x + val.R - 1;
			(find(p_sub, t)->val).L = val.R;
		}
		else if(rR == NULL){
			val.R = 1;
			val.L = (rL->val).L + 1;
			p_sub.x = p.x - val.L + 1;
			(find(p_sub, t)->val).R = val.L;
		}
		else{
			val.L = (rL->val).L + 1;
			val.R = (rR->val).R + 1;
			p_sub.x = p.x - val.L + 1;
			(find(p_sub, t)->val).R = val.L + val.R - 1;
			p_sub.x = p.x + val.R - 1;
			(find(p_sub, t)->val).L = val.L + val.R - 1;
		}

		p_sub = p;
		if(rU == NULL && rD == NULL){
			val.U = 1;
			val.D = 1;
		}
		else if(rU == NULL){
			val.U = 1;
			val.D = (rD->val).D + 1;
			p_sub.y = p.y - val.D + 1;
			(find(p_sub, t)->val).U = val.D;
		}
		else if(rD == NULL){
			val.D = 1;
			val.U = (rU->val).U + 1;
			p_sub.y = p.y + val.U - 1;
			(find(p_sub, t)->val).D = val.U;
		}
		else{
			val.U = (rU->val).U + 1;
			val.D = (rD->val).D + 1;
			p_sub.y = p.y + val.U - 1;
			(find(p_sub, t)->val).D = val.U + val.D - 1;
			p_sub.y = p.y - val.D + 1;
			(find(p_sub, t)->val).U = val.U + val.D - 1;
		}
		insert(p, val, t);
		r = find(p, t);
	}
	printf("%d %d\n", p.x, p.y);
	return 0;
} ./Main.c: In function ‘insert_sub’:
./Main.c:166:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘pos {aka struct <anonymous>}’ [-Wformat=]
    printf("In function 'insert_sub':\nkey '%d' already exists\n", key);
           ^
./Main.c: In function ‘erase_sub’:
./Main.c:183:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘pos {aka struct <anonymous>}’ [-Wformat=]
   printf("In function 'erase_sub':\nkey '%d' doesn't exist\n", key);
          ^
./Main.c: In function ‘main’:
./Main.c:286:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &K);
  ^
./Main.c:288:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^