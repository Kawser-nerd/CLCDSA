#include <stdio.h>
#include <stdlib.h>

#define datatype point
#define int long long int

typedef struct {
	int num;
	int x;
	int y;
}point;

typedef struct node_sub{
	int val;
	struct node_sub *prev;
	struct node_sub *next;
}node;

//????
int compare(datatype a, datatype b, int R, int C){
	if(a.y == 0 || a.x == R){
		if(b.y == C || b.x == 0){
			return -1;
		}
		else{
			return a.x + a.y - b.x - b.y;
		}
	}
	else{
		if(b.y == 0 || b.x == R){
			return 1;
		}
		else{
			return b.x + b.y - a.x - a.y;
		}
	}
	
}

//??
void sort_sub(datatype *origin, int left, int right, datatype *tmp, int R, int C){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp, R, C);
		sort_sub(origin, half, right, tmp, R, C);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if((compare(tmp[j], tmp[k], R, C) <= 0 && j < half) || k == right){
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

void sort(datatype *origin, int N, int R, int C){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	sort_sub(origin, 0, N, tmp, R, C);
}

signed main(){
	int R, C, N, x1, y1, x2, y2, i, j;
	scanf("%lld%lld%lld", &R, &C, &N);
	point *p = (point *)malloc(sizeof(point) * 2 * N);
	for(i = 0, j = 0; i < N; i++){
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		if((x1 % R == 0 || y1 % C == 0) && (x2 % R == 0 || y2 % C == 0)){
			p[j].num = j;
			p[j].x = x1;
			p[j].y = y1;
			p[j + 1].num = j;
			p[j + 1].x = x2;
			p[j + 1].y = y2;
			j += 2;
		}
	}
	N = j;
	sort(p, N, R, C);
	/*for(i = 0; i < N; i++){
		printf("%lld  ", p[i].num);
	}
	printf("\n");*/
	node *nod = NULL;
	node *now;
	node *new;
	//printf("test1: N = %lld\n", N);
	for(i = 0; i < N; i++){
		new = (node *)malloc(sizeof(node));
		new->val = p[i].num;
		new->prev = NULL;
		new->next = nod;
		if(nod != NULL){
			nod->prev = new;
		}
		nod = new;
	}
	j = N;
	node *pre, *nex;
	for(now = nod; ;){
		if(now->next == NULL){
			printf("NO\n");
			return 0;
		}
		if(now->val == now->next->val){
			pre = now->prev;
			nex = now->next->next;
			if(nex == NULL){
				j -= 2;
				break;
			}
			if(pre == NULL){
				nex->prev = NULL;
				now = nex;
			}
			else{
				pre->next = nex;
				nex->prev = pre;
				now = pre;
			}
			j -= 2;
		}
		else{
			now = now->next;
		}
	}
	if(j == 0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:69:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &R, &C, &N);
  ^
./Main.c:72:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
   ^