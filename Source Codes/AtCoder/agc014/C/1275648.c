#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}position;

typedef struct node_sub{
	position data;
	struct node_sub *next;
}node;

typedef struct {
	node fst;
	node *last;
	int num;
}queue;

queue *make_queue(){
	queue *q = (queue *)malloc(sizeof(queue));
	q->fst.next = NULL;
	q->last = &(q->fst);
	q->num = 0;
	return q;
}

int is_empty(queue *q){
	if(q->num == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void add_data(position p, queue *q){
	node *last = (node *)malloc(sizeof(node));
	last->data = p;
	last->next = NULL;
	q->last->next = last;
	q->last = last;
	q->num++;
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int min4(int a, int b, int c, int d){
	return min(min(a, b), min(c, d));
}

position take_data(queue *q){
	node *fst = q->fst.next;
	q->fst.next = fst->next;
	position ans = fst->data;
	free(fst);
	if(q->num == 1){
		q->last = &(q->fst);
	}
	q->num--;
	return ans;
}

int main(){
	int H, W, K, i, j;
	position p, pos;
	scanf("%d%d%d", &H, &W, &K);
	int inf = H * W;
	char **A = (char **)malloc(sizeof(char *) * H);
	int **dis = (int **)malloc(sizeof(int *) * H);
	for(i = 0; i < H; i++){
		A[i] = (char *)malloc(sizeof(char) * (W + 1));
		dis[i] = (int *)malloc(sizeof(int) * W);
		scanf("%s", A[i]);
		for(j = 0; j < W; j++){
			if(A[i][j] == 'S'){
				dis[i][j] = 0;
				p.x = i;
				p.y = j;
			}
			else{
				dis[i][j] = inf;
			}
		}
	}
	int posx, posy, rest = min4(p.x, H - p.x - 1, p.y, W - p.y - 1);
	int dh[] = {0, 1, 0, -1};
	int dw[] = {1, 0, -1, 0};
	queue *q = make_queue();
	for(add_data(p, q);;){
		if(is_empty(q) == 1){
			break;
		}
		pos = take_data(q);
		posx = pos.x;
		posy = pos.y;
		if(rest == 0){
			printf("1\n");
			return 0;
		}
		if(dis[posx][posy] == K){
			break;
		}
		for(i = 0; i < 4; i++){
			if(A[posx + dh[i]][posy + dw[i]] == '.' && dis[posx + dh[i]][posy + dw[i]] > dis[posx][posy] + 1){
				dis[posx + dh[i]][posy + dw[i]] = dis[posx][posy] + 1;
				p.x = posx + dh[i];
				p.y = posy + dw[i];
				rest = min(min4(p.x, H - p.x - 1, p.y, W - p.y - 1), rest);
				add_data(p, q);
			}
		}
	}
	printf("%d\n", 2 + (rest - 1) / K);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:74:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &H, &W, &K);
  ^
./Main.c:81:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", A[i]);
   ^