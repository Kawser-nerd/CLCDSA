#include <stdio.h>
#include <stdlib.h>
#define int long long

typedef struct {
	int x;
	int y;
	int num;
}pos;

#define AVL_keytype pos
#define AVL_valtype int
#define queue_valtype int

typedef struct q_node_sub{
	queue_valtype data;
	struct q_node_sub *next;
}q_node;

typedef struct {
	q_node *fst;
	q_node *last;
	int num;
}queue;

queue *make_queue(){
	queue *q = (queue *)malloc(sizeof(queue));
	q->fst = NULL;
	q->last = NULL;
	q->num = 0;
	return q;
}

int element_num_q(queue *q){
	return q->num;
}

void add_data_q(queue_valtype val, queue *q){
	q_node *last = (q_node *)malloc(sizeof(q_node));
	last->data = val;
	last->next = NULL;
	if(element_num_q(q) == 0){
		q->fst = last;
	}
	else{
		q->last->next = last;
	}
	q->last = last;
	q->num++;
}

queue_valtype take_data_q(queue *q){
	if(q->num == 0){
		printf("no data in the queue\n");
	}
	queue_valtype ans = q->fst->data;
	q_node *fst = q->fst;
	if(q->num == 1){
		q->fst = NULL;
		q->last = NULL;
	}
	else{
		q->fst = fst->next;
	}
	free(fst);
	q->num--;
	return ans;
}

queue_valtype look_data_q(queue *q){
	if(q->num == 0){
		printf("no data in the queue\n");
	}
	else{
		return q->fst->data;
	}
}

void to_empty(queue *q){
	queue_valtype a;
	while(element_num_q(q) > 0){
		a = take_data_q(q);
	}
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
	int (*compare_AVL)(pos a, pos b);
}AVL_tree;

int max(int a, int b){
	return a >= b ? a : b;
}

/*
//????
//a < b ?????
//a = b ??0
//a > b ?????
int compare_AVL(AVL_keytype a, AVL_keytype b){
	return a - b;
}
*/

int compare_xy(pos a, pos b){
	if(a.x == b.x){
		return a.y - b.y;
	}
	else{
		return a.x - b.x;
	}
}

int compare_yx(pos a, pos b){
	if(a.y == b.y){
		return a.x - b.x;
	}
	else{
		return a.y - b.y;
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

AVL_node *find_AVL_sub(AVL_keytype key, AVL_node *r, int (*compare_AVL)(pos a, pos b)){
	if(r == NULL){
		return NULL;
	}
	int comp = compare_AVL(key, r->key);
	if(comp == 0){
		return r;
	}
	else if(comp < 0){
		return find_AVL_sub(key, r->left, compare_AVL);
	}
	else{
		return find_AVL_sub(key, r->right, compare_AVL);
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

int num_less_than_AVL_sub(AVL_keytype key, AVL_node *r, int (*compare_AVL)(pos a, pos b)){
	if(r == NULL){
		return 0;
	}
	else if(compare_AVL(key, r->key) < 0){
		return num_less_than_AVL_sub(key, r->left, compare_AVL);
	}
	else{
		return ele_num(r->left) + num_less_than_AVL_sub(key, r->right, compare_AVL) + 1;
	}
}

AVL_node *next_largest_AVL_sub(AVL_keytype key, AVL_node *r, int (*compare_AVL)(pos a, pos b)){
	if(r == NULL){
		return NULL;
	}
	else if(compare_AVL(key, r->key) <= 0){
		return next_largest_AVL_sub(key, r->left, compare_AVL);
	}
	else{
		AVL_node *candidate = next_largest_AVL_sub(key, r->right, compare_AVL);
		if(candidate == NULL){
			return r;
		}
		else{
			return candidate;
		}
	}
}

AVL_node *next_smallest_AVL_sub(AVL_keytype key, AVL_node *r, int (*compare_AVL)(pos a, pos b)){
	if(r == NULL){
		return NULL;
	}
	else if(compare_AVL(key, r->key) >= 0){
		return next_smallest_AVL_sub(key, r->right, compare_AVL);
	}
	else{
		AVL_node *candidate = next_smallest_AVL_sub(key, r->left, compare_AVL);
		if(candidate == NULL){
			return r;
		}
		else{
			return candidate;
		}
	}
}

AVL_node *insert_AVL_sub(AVL_keytype key, AVL_valtype val, AVL_node *r, int (*compare_AVL)(pos a, pos b)){
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
			newr = build_AVL_node(r->key, r->val, insert_AVL_sub(key, val, r->left, compare_AVL), r->right);
		}
		else{
			newr = build_AVL_node(r->key, r->val, r->left, insert_AVL_sub(key, val, r->right, compare_AVL));
		}
		release_AVL_node(r);
	}
	return newr;
}

AVL_node *erase_AVL_sub(AVL_keytype key, AVL_node *r, AVL_node **ans, int (*compare_AVL)(pos a, pos b)){
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
				newr = build_AVL_node(next_larger->key, next_larger->val, r->left, erase_AVL_sub(next_larger->key, r->right, &ans_sub, compare_AVL));
				release_AVL_node(ans_sub);
			}
		}
		else{
			if(comp < 0){
				newr = build_AVL_node(r->key, r->val, erase_AVL_sub(key, r->left, ans, compare_AVL), r->right);
			}
			else{
				newr = build_AVL_node(r->key, r->val, r->left, erase_AVL_sub(key, r->right, ans, compare_AVL));
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
		printf("(key.x, key.y, key.num, val, ele_num, height) = (%lld, %lld, %lld, %lld, %lld, %lld)\n", r->key.x, r->key.y, r->key.num, r->val, r->ele_num, r->height);
		outall_AVL_sub(r->right);
	}
}

//AVL_tree?????
AVL_tree *make_AVL_tree(int (*compare_AVL)(pos a, pos b)){
	AVL_tree *t = (AVL_tree *)malloc(sizeof(AVL_tree));
	t->root = NULL;
	t->compare_AVL = compare_AVL;
	return t;
}

//t?????????????
int element_num_AVL(AVL_tree *t){
	return ele_num(t->root);
}

//????key?????????????
//????NULL???
AVL_node *find_AVL(AVL_keytype key, AVL_tree *t){
	return find_AVL_sub(key, t->root, t->compare_AVL);
}

//?????k???key?????????????
//1 ? k ? ele_num(t->root) ?????????NULL???(????????)
AVL_node *kth_smallest_AVL(int k, AVL_tree *t){
	return kth_smallest_AVL_sub(k, t->root);
}

//????key???????????
int num_less_than_AVL(AVL_keytype key, AVL_tree *t){
	return num_less_than_AVL_sub(key, t->root, t->compare_AVL);
}

//key???????????????????????????
//????NULL???
AVL_node *next_largest_AVL(AVL_keytype key, AVL_tree *t){
	return next_largest_AVL_sub(key, t->root, t->compare_AVL);
}

//key???????????????????????????
//????NULL???
AVL_node *next_smallest_AVL(AVL_keytype key, AVL_tree *t){
	return next_smallest_AVL_sub(key, t->root, t->compare_AVL);
}

//???key, ?val?????????
//?????????????????(????????)
void insert_AVL(AVL_keytype key, AVL_valtype val, AVL_tree *t){
	t->root = insert_AVL_sub(key, val, t->root, t->compare_AVL);
}

//???key?????????????
//????????NULL???
AVL_node *erase_AVL(AVL_keytype key, AVL_tree *t){
	AVL_node *ans = NULL;
	t->root = erase_AVL_sub(key, t->root, &ans, t->compare_AVL);
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


int ABS(int a){
	return a >= 0 ? a : -a;
}

int dis(pos a, pos b){
	return max(ABS(a.x - b.x), ABS(a.y - b.y));
}

signed main(){
	int N, a, b, x, y, D, i;
	scanf("%lld%lld%lld", &N, &a, &b);
	a--;
	b--;
	pos *ps = (pos *)malloc(sizeof(pos) * N);
	AVL_tree *txy = make_AVL_tree(compare_xy);
	AVL_tree *tyx = make_AVL_tree(compare_yx);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &x, &y);
		ps[i].x = x - y;
		ps[i].y = x + y;
		ps[i].num = i;
		if(i != a){
			insert_AVL(ps[i], 1, txy);
			insert_AVL(ps[i], 1, tyx);
		}
	}
	for(i = 0; i < N; i++){
//		printf("ps[%lld] = (%lld, %lld, %lld)\n", i, ps[i].x, ps[i].y, ps[i].num);
	}
	D = dis(ps[a], ps[b]);
//	printf("D = %lld\n", D);
	AVL_tree *txy2 = make_AVL_tree(compare_xy);
	AVL_tree *tyx2 = make_AVL_tree(compare_yx);
	queue *q = make_queue();
	add_data_q(a, q);
	pos p1, p2;
	AVL_node *r, *res;
	while(element_num_q(q) > 0){
		i = take_data_q(q);
//		printf("i = %lld\n", i);
		insert_AVL(ps[i], 1, txy2);
		insert_AVL(ps[i], 1, tyx2);
//		printf("test1\n");
//		outall_AVL(tyx);
		p1.x = ps[i].x - D;
		p1.y = ps[i].y - D - 1;
		p2.x = ps[i].x - D;
		p2.y = ps[i].y + D;
		for(;;){
			r = next_smallest_AVL(p1, txy);
			if(r == NULL){
				break;
			}
//			printf("(x, y, num) = (%lld, %lld, %lld)\n", r->key.x, r->key.y, r->key.num);
			if(compare_xy(r->key, p2) > 0){
				break;
			}
			else{
//				printf("add(%lld)\n", r->key.num);
				add_data_q(r->key.num, q);
				res = erase_AVL(r->key, tyx);
				res = erase_AVL(r->key, txy);
			}
		}
//		printf("test2\n");
//		outall_AVL(tyx);
		p1.x = ps[i].x + D;
		p1.y = ps[i].y - D - 1;
		p2.x = ps[i].x + D;
		p2.y = ps[i].y + D;
		for(;;){
			r = next_smallest_AVL(p1, txy);
			if(r == NULL){
				break;
			}
//			printf("(x, y, num) = (%lld, %lld, %lld)\n", r->key.x, r->key.y, r->key.num);
			if(compare_xy(r->key, p2) > 0){
				break;
			}
			else{
//				printf("add(%lld)\n", r->key.num);
				add_data_q(r->key.num, q);
//				printf("TEST\n");
//				outall_AVL(tyx);
//				printf("erase_AVL(%lld, %lld, %lld)\n", r->key.x, r->key.y, r->key.num);
				res = erase_AVL(r->key, tyx);
//				outall_AVL(tyx);
				res = erase_AVL(r->key, txy);
			}
		}
//		printf("test3\n");
//		outall_AVL(tyx);
		p1.x = ps[i].x - D - 1;
		p1.y = ps[i].y - D;
		p2.x = ps[i].x + D;
		p2.y = ps[i].y - D;
		for(;;){
			r = next_smallest_AVL(p1, tyx);
			if(r == NULL){
				break;
			}
//			printf("(x, y, num) = (%lld, %lld, %lld)\n", r->key.x, r->key.y, r->key.num);
			if(compare_yx(r->key, p2) > 0){
				break;
			}
			else{
//				printf("add(%lld)\n", r->key.num);
				add_data_q(r->key.num, q);
				res = erase_AVL(r->key, txy);
				res = erase_AVL(r->key, tyx);
			}
		}
//		printf("test4\n");
//		outall_AVL(tyx);
		p1.x = ps[i].x - D - 1;
		p1.y = ps[i].y + D;
		p2.x = ps[i].x + D;
		p2.y = ps[i].y + D;
		for(;;){
			r = next_smallest_AVL(p1, tyx);
			if(r == NULL){
				break;
			}
//			printf("(x, y, num) = (%lld, %lld, %lld)\n", r->key.x, r->key.y, r->key.num);
			if(compare_yx(r->key, p2) > 0){
				break;
			}
			else{
//				printf("add(%lld)\n", r->key.num);
				add_data_q(r->key.num, q);
				res = erase_AVL(r->key, txy);
				res = erase_AVL(r->key, tyx);
//				outall_AVL(txy);
//				outall_AVL(tyx);
			}
		}
	}
//	printf("test6\n");
//	outall_AVL(txy2);
//	outall_AVL(tyx2);
	int ans = 0;
	while(element_num_AVL(txy2) > 0){
		r = kth_smallest_AVL(1, txy2);
		i = r->key.num;
		p1.x = ps[i].x - D;
		p1.y = ps[i].y - D - 1;
		p2.x = ps[i].x - D;
		p2.y = ps[i].y + D;
		ans += num_less_than_AVL(p2, txy2) - num_less_than_AVL(p1, txy2);
//		printf("ans1 = %lld\n", ans);
		p1.x = ps[i].x + D;
		p1.y = ps[i].y - D - 1;
		p2.x = ps[i].x + D;
		p2.y = ps[i].y + D;
		ans += num_less_than_AVL(p2, txy2) - num_less_than_AVL(p1, txy2);
//		printf("ans2 = %lld\n", ans);
		p1.x = ps[i].x - D;
		p1.y = ps[i].y - D;
		p2.x = ps[i].x + D - 1;
		p2.y = ps[i].y - D;
		ans += num_less_than_AVL(p2, tyx2) - num_less_than_AVL(p1, tyx2);
//		printf("ans3 = %lld\n", ans);
		p1.x = ps[i].x - D;
		p1.y = ps[i].y + D;
		p2.x = ps[i].x + D - 1;
		p2.y = ps[i].y + D;
		ans += num_less_than_AVL(p2, tyx2) - num_less_than_AVL(p1, tyx2);
		res = erase_AVL(r->key, tyx2);
		res = erase_AVL(r->key, txy2);
//		printf("ans4 = %lld\n", ans);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘insert_AVL_sub’:
./Main.c:293:11: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘pos {aka struct <anonymous>}’ [-Wformat=]
    printf("In function 'insert_AVL_sub':\nkey '%d' already exists\n", key);
           ^
./Main.c: In function ‘main’:
./Main.c:440:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &N, &a, &b);
  ^
./Main.c:447:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &x, &y);
   ^