#include <stdio.h>
#include <stdlib.h>

#define datatype trout
#define int long long int

typedef struct {
	int val;
	int h;
	int w;
}trout;

typedef struct {
	int a;
	int num;
}pair;

int MOD(int a){
	return a % (int)(1e9 + 7);
}

//????
int compare(datatype a, datatype b){
	if(a.val < b.val){
		return 1;
	}
	else if(a.val > b.val){
		return -1;
	}
	else{
		return 0;
	}
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
	int H, W, i, j, k, ans = 0;
	scanf("%lld%lld", &H, &W);
	trout *array = (trout *)malloc(sizeof(trout) * H * W);
	pair **dp = (pair **)malloc(sizeof(pair *) * (H + 2));
	for(i = 0; i < H + 2; i++){
		dp[i] = (pair *)malloc(sizeof(pair) * (W + 2));
		for(j = 0; j < W + 2; j++){
			dp[i][j].a = 0;
			dp[i][j].num = 0;
		}
	}
	for(i = 1; i <= H; i++){
		for(j = 1; j <= W; j++){
			scanf("%lld", &(dp[i][j].a));
			array[(i - 1) * W + j - 1].val = dp[i][j].a;
			array[(i - 1) * W + j - 1].h = i;
			array[(i - 1) * W + j - 1].w = j;
		}
	}
	sort(array, H * W);
	for(k = 0; k < H * W; k++){
		i = array[k].h;
		j = array[k].w;
		if(dp[i][j].a < dp[i - 1][j].a){
			dp[i][j].num += dp[i - 1][j].num;
		}
		if(dp[i][j].a < dp[i + 1][j].a){
			dp[i][j].num += dp[i + 1][j].num;
		}
		if(dp[i][j].a < dp[i][j - 1].a){
			dp[i][j].num += dp[i][j - 1].num;
		}
		if(dp[i][j].a < dp[i][j + 1].a){
			dp[i][j].num += dp[i][j + 1].num;
		}
		dp[i][j].num = MOD(dp[i][j].num + 1);
	}
	for(i = 1; i <= H; i++){
		for(j = 1; j <= W; j++){
			ans = MOD(ans + dp[i][j].num);
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:64:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &H, &W);
  ^
./Main.c:76:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%lld", &(dp[i][j].a));
    ^