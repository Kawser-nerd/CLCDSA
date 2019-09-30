#include <stdio.h>
#include <stdlib.h>
#define int long long
#define ms_valtype pair3

#define heap_valtype pair2

typedef struct {
	int A;
	int B;
	int C;
}pair3;

typedef struct {
	int x;
	int y;
}pair2;

int compare(heap_valtype a, heap_valtype b){
	return (a.x - a.y) - (b.x - b.y);
}


typedef struct heap_node_sub{
	heap_valtype val;
	struct heap_node_sub *parent;
	struct heap_node_sub *prev;
	struct heap_node_sub *next;
	struct heap_node_sub *left;
	struct heap_node_sub *right;
}heap_node;

typedef struct {
	int N;
	heap_node *root;
	heap_node *last;
}heap;

//heap???
heap *make_heap(){
	heap *h = (heap *)malloc(sizeof(heap));
	h->N = 0;
	h->root = NULL;
	h->last = NULL;
	return h;
}

int element_num_heap(heap *h){
	return h->N;
}

void up_heapify(heap_node *n, heap *h){
	if(n->parent != NULL){
		if(compare(n->val, n->parent->val) < 0){
			heap_valtype tmp;
			tmp = n->val;
			n->val = n->parent->val;
			n->parent->val = tmp;
			up_heapify(n->parent, h);
		}
	}
}

//??????
void add_data_heap(heap_valtype val, heap *h){
	heap_node *new = (heap_node *)malloc(sizeof(heap_node));
	new->val = val;
	new->next = NULL;
	new->left = NULL;
	new->right = NULL;
	if(element_num_heap(h) == 0){
		new->parent = NULL;
		new->prev = NULL;
		h->root = new;
		h->last = new;
	}
	else if(element_num_heap(h) == 1){
		new->parent = h->root;
		new->prev = h->root;
		h->root->left = new;
		h->root->next = new;
		h->last = new;
		up_heapify(new, h);
	}
	else{
		new->prev = h->last;
		h->last->next = new;
		if(h->last->parent->right == NULL){
			new->parent = h->last->parent;
			h->last->parent->right = new;
		}
		else{
			new->parent = h->last->parent->next;
			h->last->parent->next->left = new;
		}
		h->last = new;
		up_heapify(new, h);
	}
	h->N++;
}

void down_heappify(heap_node *n, heap *h){
	if(n->left != NULL){
		heap_valtype tmp;
		if(n->right == NULL){
			if(compare(n->val, n->left->val) > 0){
				tmp = n->val;
				n->val = n->left->val;
				n->left->val = tmp;
				down_heappify(n->left, h);
			}
		}
		else{
			if(compare(n->left->val, n->right->val) <= 0 && compare(n->val, n->left->val) > 0){
				tmp = n->val;
				n->val = n->left->val;
				n->left->val = tmp;
				down_heappify(n->left, h);
			}
			else if(compare(n->left->val, n->right->val) > 0 && compare(n->val, n->right->val) > 0){
				tmp = n->val;
				n->val = n->right->val;
				n->right->val = tmp;
				down_heappify(n->right, h);
			}
		}
	}
}

//??????????
heap_valtype take_min_heap(heap *h){
	if(element_num_heap(h) == 0){
		printf("no data in the heap\n");
	}
	heap_valtype ans = h->root->val;
	heap_node *ln = h->last;
	if(element_num_heap(h) == 1){
		h->root = NULL;
		h->last = NULL;
	}
	else{
		ln->prev->next = NULL;
		if(ln->parent->right == NULL){
			ln->parent->left = NULL;
		}
		else{
			ln->parent->right = NULL;
		}
		h->last = ln->prev;
		h->root->val = ln->val;
		down_heappify(h->root, h);
	}
	free(ln);
	h->N--;
	return ans;
}

heap_valtype look_min_heap(heap *h){
	if(element_num_heap(h) == 0){
		printf("no data in the heap\n");
	}
	return h->root->val;
}

//????
int compare_ms(ms_valtype a, ms_valtype b){
	return (a.A - a.B) - (b.A - b.B);
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

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int X, Y, Z, N, K, i, sum;
	scanf("%lld%lld%lld", &X, &Y, &Z);
	N = X + Y + Z;
	pair3 *ABC = (pair3 *)malloc(sizeof(pair3) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld%lld", &ABC[i].A, &ABC[i].B, &ABC[i].C);
	}
	sort(ABC, N);
/*	for(i = 0; i < N; i++){
		printf("(A, B, C) = (%lld, %lld, %lld)\n", ABC[i].A, ABC[i].B, ABC[i].C);
	}
*/	int *ans = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		ans[i] = 0;
	}
	pair2 p2;
	heap *h1 = make_heap();
	sum = 0;
	for(i = 0; i < Y; i++){
		sum += ABC[i].B;
		p2.x = ABC[i].B;
		p2.y = ABC[i].C;
		add_data_heap(p2, h1);
	}
//	printf("sum[%lld] = %lld\n", Y - 1, sum);
	ans[Y - 1] += sum;
	for(i = Y; i < Y + Z; i++){
		sum += ABC[i].B;
		p2.x = ABC[i].B;
		p2.y = ABC[i].C;
		add_data_heap(p2, h1);
		p2 = take_min_heap(h1);
		sum -= p2.x;
		sum += p2.y;
//		printf("sum[%lld] = %lld\n", i, sum);
		ans[i] += sum;
	}
	heap *h2 = make_heap();
	sum = 0;
	for(i = N - 1; i >= Y + Z; i--){
		sum += ABC[i].A;
		p2.x = ABC[i].A;
		p2.y = ABC[i].C;
		add_data_heap(p2, h2);
	}
//	printf("sum[%lld] = %lld\n", Y + Z - 1, sum);
	ans[Y + Z - 1] += sum;
	for(i = Y + Z - 1; i >= Y; i--){
		sum += ABC[i].A;
		p2.x = ABC[i].A;
		p2.y = ABC[i].C;
		add_data_heap(p2, h2);
		p2 = take_min_heap(h2);
		sum -= p2.x;
		sum += p2.y;
//		printf("sum[%lld] = %lld\n", i - 1, sum);
		ans[i - 1] += sum;
	}
	int a = 0;
	for(i = Y - 1; i < Y + Z; i++){
		a = max(a, ans[i]);
	}
	printf("%lld\n", a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:208:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &X, &Y, &Z);
  ^
./Main.c:212:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &ABC[i].A, &ABC[i].B, &ABC[i].C);
   ^