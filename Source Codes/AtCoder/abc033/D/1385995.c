#include <stdio.h>
#include <stdlib.h>

#define datatype position
#define int long long int

typedef struct {
	int x;
	int y;
}position;

//????
int compare(datatype a, datatype b){
	return a.y * b.x - a.x * b.y;
}

//??
void sort_sub(datatype *origin, int left, int right, datatype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if((compare(tmp[j], tmp[k]) <= 0 && j < half) || k == right){
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

void sort(datatype *origin, int N){
	datatype *tmp = (datatype *)malloc(sizeof(datatype) * N);
	sort_sub(origin, 0, N, tmp);
}

signed main(){
	int N, i, j, k, l;
	scanf("%lld", &N);
	position *p = (position *)malloc(sizeof(position) * N);
	position *up_half = (position *)malloc(sizeof(position) * N);
	position *down_half = (position *)malloc(sizeof(position) * N);
	position *whole = (position *)malloc(sizeof(position) * 2 * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &p[i].x, &p[i].y);
	}
	int acute_ans = 0, right_ans = 0, obtuse_ans = 0;
	int acute, right, behind, front, x, y;
	for(i = 0; i < N; i++){
		x = p[i].x;
		y = p[i].y;
		//printf("i = %lld, pivot = (%lld, %lld)\n", i, x, y);
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
		sort(up_half, k);
		sort(down_half, l);
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
		/*for(j = 0; j < N - 1; j++){
			printf("j = %lld, (%lld, %lld)\n", j, whole[j].x, whole[j].y);
		}*/
		acute = 0;
		right = 0;
		for(behind = 0, front = 1; behind < N - 1; behind++){
			//printf("behind = %lld\n", behind);
			while(whole[behind].x * whole[front].y - whole[behind].y * whole[front].x >= 0
			 && whole[behind].x * whole[front].x + whole[behind].y * whole[front].y > 0
			 && front - behind < N - 1){
				front++;
			}
			//printf("front = %lld\n", front);
			if(whole[behind].x * whole[front].y - whole[behind].y * whole[front].x > 0
				&& whole[behind].x * whole[front].x + whole[behind].y * whole[front].y == 0){
				right++;
			}
			acute += front - behind - 1;
		}
		//printf("acute = %lld\n", acute);
		//printf("right = %lld\n", right);
		right_ans += right;
		obtuse_ans += ((N - 1) * (N - 2)) / 2 - acute - right;
		//printf("right_ans = %lld\n", right_ans);
		//printf("obtuse_ans = %lld\n", obtuse_ans);
		//printf("\n");
	}
	acute_ans = (N * (N - 1) * (N - 2)) / 6 - right_ans - obtuse_ans;
	printf("%lld %lld %lld\n", acute_ans, right_ans, obtuse_ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:46:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &p[i].x, &p[i].y);
   ^