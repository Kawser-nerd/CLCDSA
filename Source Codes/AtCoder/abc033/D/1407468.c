#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}pos;

void sort(pos *p, int l, int r){
	static pos tmp[2000];
	if(r - l > 1){
		int i, j, k, h = (l + r) / 2;
		sort(p, l, h);
		sort(p, h, r);
		for(i = l; i < r; i++){
			tmp[i] = p[i];
		}
		for(i = l, j = l, k = h; i < r; i++){
			if((tmp[j].y * tmp[k].x <= tmp[j].x * tmp[k].y && j < h) || k == r){
				p[i] = tmp[j];
				j++;
			}
			else{
				p[i] = tmp[k];
				k++;
			}
		}
	}
}

int main(){
	int N, i, j, k, l;
	scanf("%d", &N);
	pos *p = (pos *)malloc(sizeof(pos) * N);
	pos *up_half = (pos *)malloc(sizeof(pos) * N);
	pos *down_half = (pos *)malloc(sizeof(pos) * N);
	pos *whole = (pos *)malloc(sizeof(pos) * 2 * N);
	for(i = 0; i < N; i++){
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	long long acute_ans = 0, right_ans = 0, obtuse_ans = 0, pairnum = ((N - 1) * (N - 2)) / 2;
	int acute, right, behind, front, x, y;
	for(i = 0; i < N; i++){
		x = p[i].x;
		y = p[i].y;
		for(j = 0, k = 0, l = 0; j < N; j++){
			if(i != j){
				if(p[j].y >= y){
					up_half[k].x = p[j].x - x;
					up_half[k].y = p[j].y - y;
					k++;
				}
				else{
					down_half[l].x = p[j].x - x;
					down_half[l].y = p[j].y - y;
					l++;
				}
			}
		}
		sort(up_half, 0, k);
		sort(down_half, 0, l);
		for(j = 0; j < k; j++){
			whole[j] = up_half[j];
			whole[k + l + j] = up_half[j];
		}
		for(j = 0; j < l; j++){
			whole[k + j] = down_half[j];
			whole[k + l + k + j] = down_half[j];
		}
		acute = 0;
		right = 0;
		for(behind = 0, front = 1; behind < N - 1; behind++){
			while(whole[behind].x * whole[front].y - whole[behind].y * whole[front].x >= 0
			 && whole[behind].x * whole[front].x + whole[behind].y * whole[front].y > 0
			 && front - behind < N - 1){
				front++;
			}
			if(whole[behind].x * whole[front].y - whole[behind].y * whole[front].x > 0
				&& whole[behind].x * whole[front].x + whole[behind].y * whole[front].y == 0){
				right++;
			}
			acute += front - behind - 1;
		}
		right_ans += right;
		obtuse_ans += pairnum - acute - right;
	}
	acute_ans = pairnum * N / 3 - right_ans - obtuse_ans;
	printf("%lld %lld %lld\n", acute_ans, right_ans, obtuse_ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &p[i].x, &p[i].y);
   ^