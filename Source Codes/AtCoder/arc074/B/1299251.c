#include <stdio.h>
#include <stdlib.h>

#define datatype int

long long int max(long long int a, long long int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

long long int min(long long int a, long long int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

typedef enum{
	false,
	true
}boolean;

typedef struct node_sub{
	datatype val;
	struct node_sub *parent;
	struct node_sub *prev;
	struct node_sub *next;
	struct node_sub *left;
	struct node_sub *right;
}node;

typedef struct {
	long long int num;
	node *root;
	node *last;
}heap;

long long int compare(datatype a, datatype b){
	if(a < b){
		return -1;
	}
	if(a == b){
		return 0;
	}
	if(a > b){
		return 1;
	}
}

heap *make_heap(){
	heap *h = (heap *)malloc(sizeof(heap));
	h->num = 0;
	h->root = NULL;
	h->last = NULL;
	return h;
}

boolean is_empty(heap *h){
	if(h->num == 0){
		return true;
	}
	else{
		return false;
	}
}

void up_heapify(node *n, heap *h){
	if(n->parent != NULL){
		if(compare(n->val, n->parent->val) == -1){
			datatype tmp;
			tmp = n->val;
			n->val = n->parent->val;
			n->parent->val = tmp;
			up_heapify(n->parent, h);
		}
	}
}

void insert(datatype val, heap *h){
	node *new = (node *)malloc(sizeof(node));
	new->val = val;
	new->next = NULL;
	new->left = NULL;
	new->right = NULL;
	if(is_empty(h) == true){
		new->parent = NULL;
		new->prev = NULL;
		h->root = new;
		h->last = new;
	}
	else if(h->num == 1){
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
	h->num++;
}

void down_heappify(node *n, heap *h){
	if(n->left != NULL){
		datatype tmp;
		if(n->right == NULL){
			if(compare(n->val, n->left->val) == 1){
				tmp = n->val;
				n->val = n->left->val;
				n->left->val = tmp;
				down_heappify(n->left, h);
			}
		}
		else{
			if(compare(n->left->val, n->right->val) != 1 && compare(n->val, n->left->val) == 1){
				tmp = n->val;
				n->val = n->left->val;
				n->left->val = tmp;
				down_heappify(n->left, h);
			}
			else if(compare(n->left->val, n->right->val) == 1 && compare(n->val, n->right->val) == 1){
				tmp = n->val;
				n->val = n->right->val;
				n->right->val = tmp;
				down_heappify(n->right, h);
			}
		}
	}
}

datatype take_min(heap *h){
	datatype ans = h->root->val;
	node *ln = h->last;
	if(h->num == 1){
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
	h->num--;
	return ans;
}

long long int main(){
	long long int N, i, a, b;
	scanf("%lld", &N);
	heap *hl = make_heap();
	heap *hr = make_heap();
	long long int *ac = (long long int *)malloc(sizeof(long long int) * N);
	long long int *sumleft = (long long int *)malloc(sizeof(long long int) * (N + 1));
	long long int *sumright = (long long int *)malloc(sizeof(long long int) * (N + 1));
	long long int sum = 0;
	for(i = 0; i < N; i++){
		scanf("%lld", &a);
		insert(a, hl);
		sum += a;
	}
	sumleft[0] = sum;
	for(i = 0; i < N; i++){
		scanf("%lld", &ac[i]);
	}
	sum = 0;
	for(i = 0; i < N; i++){
		scanf("%lld", &a);
		insert(-a, hr);
		sum += a;
	}
	sumright[N] = sum;
	for(i = 0; i < N; i++){
		a = take_min(hl);
		b = max(a, ac[i]);
		sumleft[i + 1] = sumleft[i] + b - a;
		insert(b, hl);
	}
	for(i = 0; i < N; i++){
		a = -take_min(hr);
		b = min(a, ac[N - i - 1]);
		sumright[N - i - 1] = sumright[N - i] + b - a;
		insert(-b, hr);
	}
	long long int ans = sumleft[0] - sumright[0];
	for(i = 0; i <= N; i++){
		ans = max(ans, sumleft[i] - sumright[i]);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:176:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:184:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a);
   ^
./Main.c:190:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &ac[i]);
   ^
./Main.c:194:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a);
   ^