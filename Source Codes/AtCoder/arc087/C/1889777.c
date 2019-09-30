#include <stdio.h>
#include <stdlib.h>
#define int long long
#define max_size (int)(1e5 + 1)
#define alphabet_num 2
#define trie_valtype int
#define trie_initial_val 0

int char_to_int(char c){
	return (int)c - (int)'0';
}

typedef struct trie_node_sub {
	int exist;
	trie_valtype val;
	int heignt;
	struct trie_node_sub *children[alphabet_num];
}trie_node;

typedef struct {
	trie_node *root;
}trie;

trie_node *make_node_trie(int exist, trie_valtype val, int heignt){
	int i;
	trie_node *r = (trie_node *)malloc(sizeof(trie_node));
	r->exist = exist;
	r->val = val;
	r->heignt = heignt;
	for(i = 0; i < alphabet_num; i++){
		r->children[i] = NULL;
	}
	return r;
}

trie *make_trie(){
	trie *t = (trie *)malloc(sizeof(trie));
	t->root = NULL;
	return t;
}

void insert_trie(char *s, trie_valtype val, trie *t){
	int i;
	trie_node *r;
	if(t->root == NULL){
		t->root = make_node_trie(0, trie_initial_val, 0);
	}
	r = t->root;
	for(i = 0; s[i] != '\0'; i++){
		if(r->children[char_to_int(s[i])] == NULL){
			r->children[char_to_int(s[i])] = make_node_trie(0, trie_initial_val, r->heignt + 1);
		}
		r = r->children[char_to_int(s[i])];
	}
	if(r->exist == 1){
		printf("In function 'insert_trie':\nkey '%s' already exists\n", s);
	}
	r->exist = 1;
	r->val = val;
}

trie_node *find_trie(char *s, trie *t){
	int i;
	trie_node *r;
	if(t->root == NULL){
		return NULL;
	}
	else{
		r = t->root;
	}
	for(i = 0; s[i] != '\0'; i++){
		if(r->children[char_to_int(s[i])] == NULL){
			return NULL;
		}
		r = r->children[char_to_int(s[i])];
	}
	if(r->exist == 0){
		return NULL;
	}
	else{
		return r;
	}
}

#define queue_valtype trie_node *

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

int grundy(int N){
	int i;
	for(i = 1; N % i == 0; i <<= 1){}
	return i >> 1;
}

signed main(){
	int N, L, i, j, g = 0;
	scanf("%lld%lld", &N, &L);
	char *s = (char *)malloc(sizeof(char) * max_size);
	trie *t = make_trie();
	for(i = 0; i < N; i++){
		scanf("%s", s);
		insert_trie(s, 1, t);
	}
	queue *q = make_queue();
	add_data_q(t->root, q);
	trie_node *r;
	while(element_num_q(q) > 0){
		r = take_data_q(q);
//		printf("r->heignt = %lld\n", r->heignt);
		if(r->children[0] != NULL){
			add_data_q(r->children[0], q);
		}
		if(r->children[1] != NULL){
			add_data_q(r->children[1], q);
		}
		if((r->children[0] == NULL && r->children[1] != NULL) || (r->children[0] != NULL && r->children[1] == NULL)){
			g ^= grundy(L - r->heignt);
		}
	}
	if(g == 0){
		printf("Bob\n");
	}
	else{
		printf("Alice\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:159:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &L);
  ^
./Main.c:163:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^