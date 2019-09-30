#include <stdio.h>
#include <stdlib.h>

typedef struct {
	long long x;
	long long y;
}position;

int compare(const void *a, const void *b){
	return (int)(((position *)a)->y * ((position *)b)->x - ((position *)a)->x * ((position *)b)->y);
}

int main(){
	long long N, i, j, k, l;
	scanf("%lld", &N);
	position *p = (position *)malloc(sizeof(position) * N);
	position *up_half = (position *)malloc(sizeof(position) * N);
	position *down_half = (position *)malloc(sizeof(position) * N);
	position *whole = (position *)malloc(sizeof(position) * 2 * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &(p[i].x), &(p[i].y));
	}
	long long right_ans = 0, obtuse_ans = 0;
	long long acute, right, behind, front, x, y;
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
		qsort(up_half, k, sizeof(position), compare);
		qsort(down_half, l, sizeof(position), compare);
		for(j = 0; j < k; j++){
			whole[j] = up_half[j];
		}
		for(j = 0; j < l; j++){
			whole[k + j] = down_half[j];
		}
		for(j = 0; j < k; j++){
			whole[k + l + j] = up_half[j];
		}
		for(j = 0; j < l; j++){
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
		obtuse_ans += ((N - 1) * (N - 2)) / 2 - acute - right;
	}
	printf("%lld %lld %lld\n", (N * (N - 1) * (N - 2)) / 6 - right_ans - obtuse_ans, right_ans, obtuse_ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &(p[i].x), &(p[i].y));
   ^