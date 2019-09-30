#include <stdio.h>
#include <stdlib.h>
#define inf (int)(1e9 + 7)

typedef struct {
	int *array;
	int last;
	int first;
}queue;

queue *make_queue(int maxN){
	queue *q = (queue *)malloc(sizeof(queue));
	q->array = (int *)malloc(sizeof(int) * maxN);
	q->last = 0;
	q->first = 0;
	return q;
}

int element_num_queue(queue *q){
	return q->first - q->last;
}

void add_data_queue(int val, queue *q){
	q->array[q->first] = val;
	q->first++;
}

int take_data_queue(queue *q){
	if(element_num_queue(q) <= 0){
		printf("no data in the queue\n");
	}
	q->last++;
	return q->array[q->last - 1];
}

void flush_queue(queue *q){
	q->last = 0;
	q->first = 0;
}

int min(int a, int b){
	return a <= b ? a : b;
}

//n:???, s:?????, t:?????, e:(u, v)->f u??v????
int Edmonds_Karp(int N, int s, int t, int **e){
	int v, i, flow_sum = 0;
	int *flow = (int *)malloc(sizeof(int) * N);//??????????
	int *p = (int *)malloc(sizeof(int) * N);//?????? ????????
	queue *q = make_queue(N * N);

	for(;;){
		//???
		for(i = 0; i < N; i++){
			flow[i] = 0;
			p[i] = -1;
		}
		flow[s] = inf;
		p[s] = -2;

		add_data_queue(s, q);
		while(element_num_queue(q) > 0){
			v = take_data_queue(q);
			if(v == t){
				break;
			}
			for(i = 0; i < N; i++){
				if(e[v][i] > 0 && p[i] == -1){
					p[i] = v;
					flow[i] = min(flow[v], e[v][i]);
					add_data_queue(i, q);
				}
			}
		}
		//??????????
		if(flow[t] == 0){
			break;
		}
		//???????????
		for(v = t; v != s; v = p[v]){
			e[p[v]][v] -= flow[t];
			e[v][p[v]] += flow[t];
		}
		flow_sum += flow[t];
		flush_queue(q);
	}
	return flow_sum;
}

int main(){
	int N, i, j, ans;
	scanf("%d", &N);
	int **E = (int **)malloc(sizeof(int *) * (2 * N + 2));
	for(i = 0; i < 2 * N + 2; i++){
		E[i] = (int *)malloc(sizeof(int) * (2 * N + 2));
		for(j = 0; j < 2 * N + 2; j++){
			E[i][j] = 0;
		}
	}
	for(i = 1; i <= N; i++){
		E[0][i] = 1;
	}
	for(i = N + 1; i <= 2 * N; i++){
		E[i][2 * N + 1] = 1;
	}
	int *a = (int *)malloc(sizeof(int) * N);
	int *b = (int *)malloc(sizeof(int) * N);
	int *c = (int *)malloc(sizeof(int) * N);
	int *d = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d%d", &a[i], &b[i]);
	}
	for(i = 0; i < N; i++){
		scanf("%d%d", &c[i], &d[i]);
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(a[i] < c[j] && b[i] < d[j]){
				E[1 + i][N + 1 + j] = 1;
			}
		}
	}
/*	for(i = 0; i < 2 * N + 2; i++){
		for(j = 0; j < 2 * N + 2; j++){
			printf("E[%d][%d] = %d\n", i, j, E[i][j]);
		}
	}
*/	ans = Edmonds_Karp(2 * N + 2, 0, 2 * N + 1, E);
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:92:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:111:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a[i], &b[i]);
   ^
./Main.c:114:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &c[i], &d[i]);
   ^