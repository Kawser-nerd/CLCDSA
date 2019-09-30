#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}pos;

signed compare(const void *a, const void *b){
	return ((pos *)a)->x - ((pos *)b)->x;
}

pos *ps, *ans;
int k = 0, **A;

int put(int x, int y){
	if(A[x][y] == 0){
		ans[k] = (pos){x, y};
		A[x][y] = 1;
		k++;
	}
}

void solve(int l, int r){
	if(r - l > 1){
		int i, h = (l + r) / 2;
		for(i = l; i < r; i++){
			put(ps[h].x, ps[i].y);
		}
		solve(l, h);
		solve(h + 1, r);
	}
}

int main(){
	int N, i, j;
	A = (int **)malloc(sizeof(int *) * 1001);
	for(i = 0; i <= 1000; i++){
		A[i] = (int *)malloc(sizeof(int) * 1001);
		for(j = 0; j <= 1000; j++){
			A[i][j] = 0;
		}
	}
	scanf("%d", &N);
	ps = (pos *)malloc(sizeof(pos) * N);
	for(i = 0; i < N; i++){
		scanf("%d%d", &ps[i].x, &ps[i].y);
		A[ps[i].x][ps[i].y] = 1;
	}
	qsort(ps, N, sizeof(pos), compare);
/*	for(i = 0; i < N; i++){
		printf("ps[%d] = (%d, %d)\n", i, ps[i].x, ps[i].y);
	}
*/	ans = (pos *)malloc(sizeof(pos) * 10000);
	solve(0, N);
	printf("%d\n", k);
	for(i = 0; i < k; i++){
		printf("%d %d\n", ans[i].x, ans[i].y);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &ps[i].x, &ps[i].y);
   ^