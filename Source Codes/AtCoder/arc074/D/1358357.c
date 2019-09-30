#include <stdio.h>
#include <stdlib.h>

#define inf (int)(1e9 + 7)

typedef enum{
	false,
	true
}Boolean;

typedef struct node_sub{
	int data;
	struct node_sub *next;
}node;

typedef struct {
	node *fst;
	node *last;
	int num;
}queue;

queue *make_queue(){
	queue *q = (queue *)malloc(sizeof(queue));
	q->fst = NULL;
	q->last = NULL;
	q->num = 0;
	return q;
}

Boolean is_empty(queue *q){
	if(q->num == 0){
		return true;
	}
	else{
		return false;
	}
}

void add_data(int val, queue *q){
	node *last = (node *)malloc(sizeof(node));
	last->data = val;
	last->next = NULL;
	if(is_empty(q) == true){
		q->fst = last;
	}
	else{
		q->last->next = last;
	}
	q->last = last;
	q->num++;
}

int take_data(queue *q){
	if(q->num == 0){
		printf("no data in the queue\n");
	}
	int ans = q->fst->data;
	node *fst = q->fst;
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

void to_empty(queue *q){
	int a;
	while(is_empty(q) == false){
		a = take_data(q);
	}
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

//n:???, s:?????, t:?????, e:(u, v)->f u??v????
int Edmonds_Karp(int n, int s, int t, int **e){
	int v, i;
	int flow_sum = 0;
	int *flow = (int *)malloc(sizeof(int) * n);
	int *p = (int *)malloc(sizeof(int) * n);
	queue *q = make_queue();

	for(;;){
		for(i = 0; i < n; i++){
			flow[i] = 0;
			p[i] = -1;
		}
		flow[s] = inf;
		p[s] = -2;

		add_data(s, q);
		while(is_empty(q) == false){
			v = take_data(q);
			if(v == t){
				break;
			}
			for(i = 0; i < n; i++){
				if(e[v][i] > 0 && p[i] == -1){
					p[i] = v;
					flow[i] = min(flow[v], e[v][i]);
					add_data(i, q);
				}
			}
		}
		if(flow[t] == 0){
			break;
		}
		for(v = t; v != s; v = p[v]){
			e[p[v]][v] -= flow[t];
			e[v][p[v]] += flow[t];
		}
		flow_sum += flow[t];
		to_empty(q);
	}
	return flow_sum;
}

int main(){
	int H, W, n, i, j;
	scanf("%d%d", &H, &W);
	char *a = (char *)malloc(sizeof(char) * (W + 1));
	n = H + W + 2;
	int **e = (int **)malloc(sizeof(int *) * n);
	for(i = 0; i < n; i++){
		e[i] = (int *)malloc(sizeof(int) * n);
		for(j = 0; j < n; j++){
			e[i][j] = 0;
		}
	}
	int sx, sy, tx, ty;
	for(i = 0; i < H; i++){
		scanf("%s", a);
		for(j = 0; j < W; j++){
			if(a[j] == 'S'){
				e[0][1 + i] = inf;
				e[0][1 + H + j] = inf;
				sx = i;
				sy = j;
			}
			else if(a[j] == 'T'){
				e[1 + i][n - 1] = inf;
				e[1 + H + j][n - 1] = inf;
				tx = i;
				ty = j;
			}
			else if(a[j] == 'o'){
				e[1 + i][1 + H + j] = 1;
				e[1 + H + j][1 + i] = 1;
			}
		}
	}
	if(sx == tx || sy == ty){
		printf("-1\n");
	}
	else{
		printf("%d\n", Edmonds_Karp(n, 0, n - 1, e));
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:132:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:144:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", a);
   ^