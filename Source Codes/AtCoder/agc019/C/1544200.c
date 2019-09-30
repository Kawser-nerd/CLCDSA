#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define int long long
#define sup (int)(1e8 - 1)
#define inf (int)(1e9 + 7)
#define datatype pos

typedef struct {
	int X;
	int Y;
}pos;

//????
int compare(datatype a, datatype b){
	return a.X - b.X;
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
	free(tmp);
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

signed main(){
	int x1, y1, x2, y2, N, X, Y, i, f = 0;
	scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
	if(x1 < x2 && y1 > y2){
		f = 1;
		y1 = sup - y1;
		y2 = sup - y2;
	}
	else if(x1 > x2 && y1 < y2){
		f = 2;
		x1 = sup - x1;
		x2 = sup - x2;
	}
	else if(x1 >= x2 && y1 >= y2){
		f = 3;
		x1 = sup - x1;
		x2 = sup - x2;
		y1 = sup - y1;
		y2 = sup - y2;
	}
	scanf("%lld", &N);
	pos *fountain = (pos *)malloc(sizeof(pos) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &X, &Y);
		if(f == 1){
			Y = sup - Y;
		}
		else if(f == 2){
			X = sup - X;
		}
		else if(f == 3){
			X = sup - X;
			Y = sup - Y;
		}
		if(X < x1 || x2 < X || Y < y1 || y2 < Y){
			X = inf;
			Y = inf;
		}
		fountain[i].X = X;
		fountain[i].Y = Y;
	}
	sort(fountain, N);
/*	printf("test:\n");
	for(i = 0; i < N; i++){
		printf("%lld  ", fountain[i].X);
	}
	printf("\n");
*/	for(i = 0; fountain[i].X < inf && i < N; i++){}
	N = i;
//	printf("N = %lld\n", N);
	int *dp = (int *)malloc(sizeof(int) * (N + 2));
	dp[0] = -inf;
	for(i = 1; i <= N + 1; i++){
		dp[i] = inf;
	}
	int l, h, r, fountain_num;
	for(i = 0; i < N; i++){
		for(l = 0, r = N + 1; r - l > 1;){
			h = (l + r) / 2;
			if(dp[h] > fountain[i].Y){
				r = h;
			}
			else{
				l = h;
			}
		}
		dp[r] = fountain[i].Y;
	}
	for(i = 0; dp[i] < inf; i++){}
	fountain_num = i - 1;
	double ans;
	if(fountain_num == min(x2 - x1, y2 - y1) + 1){
		ans = 100 * ((x2 - x1) + (y2 - y1)) - 2 * 10 * fountain_num + (5 * M_PI) * (fountain_num + 1);
	}
	else{
		ans = 100 * ((x2 - x1) + (y2 - y1)) - 2 * 10 * fountain_num + (5 * M_PI) * fountain_num;
	}
//	printf("fountain_num = %lld\n", fountain_num);
	printf("%.15lf\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:59:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
  ^
./Main.c:77:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:80:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &X, &Y);
   ^