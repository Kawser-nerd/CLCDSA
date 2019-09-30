#include <stdio.h>
#include <stdlib.h>
#define deque_valtype char

typedef struct dq_node_sub{
	deque_valtype val;
	struct dq_node_sub *prev;
	struct dq_node_sub *next;
}dq_node;

typedef struct {
	int N;
	dq_node *first;
	dq_node *last;
}deque;

deque *make_deque(){
	deque *dq = (deque *)malloc(sizeof(deque));
	dq->N = 0;
	dq->first = NULL;
	dq->last = NULL;
	return dq;
}

void add_first_data_deque(deque_valtype val, deque *dq){
	dq_node *first = (dq_node *)malloc(sizeof(dq_node));
	first->val = val;
	first->prev = NULL;
	first->next = dq->first;
	dq->first = first;
	dq->N++;
	if(dq->N == 1){
		dq->last = first;
	}
	else{
		first->next->prev = first;
	}
}

void add_last_data_deque(deque_valtype val, deque *dq){
	dq_node *last = (dq_node *)malloc(sizeof(dq_node));
	last->val = val;
	last->prev = dq->last;
	last->next = NULL;
	dq->last = last;
	dq->N++;
	if(dq->N == 1){
		dq->first = last;
	}
	else{
		last->prev->next = last;
	}
}

deque_valtype take_first_data_deque(deque *dq){
	if(dq->N == 0){
		printf("In function 'take_first_data_deque':\nThere is no data in the deque");
	}
	deque_valtype ans = dq->first->val;
	dq->N--;
	if(dq->N == 0){
		free(dq->first);
		dq->first = NULL;
		dq->last == NULL;
	}	
	else{
		dq->first = dq->first->next;
		free(dq->first->prev);
		dq->first->prev = NULL;
	}
	return ans;
}

deque_valtype take_last_data_deque(deque *dq){
	if(dq->N == 0){
		printf("In function 'take_last_data_deque':\nThere is no data in the deque");
	}
	deque_valtype ans = dq->last->val;
	dq->N--;
	if(dq->N == 0){
		free(dq->last);
		dq->first = NULL;
		dq->last == NULL;
	}	
	else{
		dq->last = dq->last->prev;
		free(dq->last->next);
		dq->last->next = NULL;
	}
	return ans;
}

deque_valtype look_first_data_deque(deque *dq){
	if(dq->N == 0){
		printf("In function 'look_first_data_deque':\nThere is no data in the deque");
	}
	return dq->first->val;
}

deque_valtype look_last_data_deque(deque *dq){
	if(dq->N == 0){
		printf("In function 'look_last_data_deque':\nThere is no data in the deque");
	}
	return dq->last->val;
}

int element_num_deque(deque *dq){
	return dq->N;
}

void out_all_deque(deque *dq){
	dq_node *now = dq->first;
	while(now != NULL){
		printf("%c\n", now->val);
		now = now->next;
	}
}

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, K, i, is_reverse;
	char head;
	scanf("%d%d", &N, &K);
	char *S = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S);
	K = min(K, 2 * N + K % 2);
	deque *dq = make_deque();
	for(i = 0; i < N; i++){
		add_last_data_deque(S[i], dq);
	}
	for(i = 0, is_reverse = 0; i < K; i++){
		head = take_first_data_deque(dq);
		if(is_reverse == 0){
			if(head == 'A'){
				add_first_data_deque('B', dq);
			}
			else{
				add_last_data_deque('B', dq);
				is_reverse = 1;
			}
		}
		else{
			if(head == 'B'){
				add_first_data_deque('A', dq);
			}
			else{
				add_last_data_deque('A', dq);
				is_reverse = 0;
			}
		}
	}
	while(element_num_deque(dq) > 0){
		head = take_first_data_deque(dq);
		if(is_reverse == 0){
			printf("%c", head);
		}
		else{
			if(head == 'A'){
				printf("B");
			}
			else{
				printf("A");
			}
		}
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:126:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:128:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^