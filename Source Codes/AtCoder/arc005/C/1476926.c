#include <stdio.h>
#include <stdlib.h>

#define datatype pos
#define inf 9

typedef struct {
	int x;
	int y;
}pos;

typedef enum{
	false,
	true
}Boolean;

typedef struct node_sub{
	datatype data;
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

Boolean is_empty_q(queue *q){
	if(q->num == 0){
		return true;
	}
	else{
		return false;
	}
}

void add_data_q(datatype val, queue *q){
	node *last = (node *)malloc(sizeof(node));
	last->data = val;
	last->next = NULL;
	if(is_empty_q(q) == true){
		q->fst = last;
	}
	else{
		q->last->next = last;
	}
	q->last = last;
	q->num++;
}

datatype take_data_q(queue *q){
	if(q->num == 0){
		printf("no data in the queue\n");
	}
	datatype ans = q->fst->data;
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

int main(){
	int H, W, i, j, next_x, next_y;
	pos p, next_p;
	scanf("%d%d", &H, &W);
	char **c = (char **)malloc(sizeof(char *) * H);
	int **b = (int **)malloc(sizeof(int *) * H);
	queue *q = make_queue();
	for(i = 0; i < H; i++){
		c[i] = (char *)malloc(sizeof(char) * (W + 1));
		b[i] = (int *)malloc(sizeof(int) * W);
		scanf("%s", c[i]);
		for(j = 0; j < W; j++){
			if(c[i][j] == 's'){
				b[i][j] = 0;
				p.x = i;
				p.y = j;
				add_data_q(p, q);
			}
			else{
				b[i][j] = inf;
			}
		}
	}
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	int now_destroy, next_destroy;
	while(is_empty_q(q) == false){
		p = take_data_q(q);
		now_destroy = b[p.x][p.y];
		for(i = 0; i < 4; i++){
			next_x = p.x + dx[i];
			next_y = p.y + dy[i];
			if(0 <= next_x && next_x < H && 0 <= next_y && next_y < W){
				if(c[next_x][next_y] == 'g'){
					printf("YES\n");
					return 0;
				}
				next_destroy = now_destroy;
				if(c[next_x][next_y] == '#'){
					next_destroy++;
				}
				if(next_destroy <= 2 && next_destroy < b[next_x][next_y]){
					b[next_x][next_y] = next_destroy;
					next_p.x = next_x;
					next_p.y = next_y;
					add_data_q(next_p, q);
				}
			}
		}
	}
/*	printf("test:\n");
	for(i = 0; i < H; i++){
		for(j = 0; j < W; j++){
			printf("%d  ", b[i][j]);
		}
		printf("\n");
	}
*/	printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:80:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &H, &W);
  ^
./Main.c:87:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", c[i]);
   ^