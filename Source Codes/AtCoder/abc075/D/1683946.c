#include <stdio.h>
#include <stdlib.h>
#define int long long
#define datatype pos
#define inf ((int)(1e18) * 4 + 1)

typedef struct {
	int x;
	int y;
}pos;

//????
int compare(datatype a, datatype b){
	return a.x - b.x;
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
			if(k == right){
				origin[i] = tmp[j];
				j++;
			}
			else if(compare(tmp[j], tmp[k]) <= 0 && j < half){
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
	int K, N, i, j, k, H, W, ans = inf;
	scanf("%lld%lld", &N, &K);
	pos *p = (pos *)malloc(sizeof(pos) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &p[i].x, &p[i].y);
	}
	pos *h = (pos *)malloc(sizeof(pos) * N);
	sort(p, N);
	for(i = 0; i + K <= N; i++){
		for(j = i + K; j <= N; j++){
			W = p[j - 1].x - p[i].x;
//			printf("W = %lld\n", W);
			for(k = i; k < j; k++){
				h[k - i].x = p[k].y;
			}
			sort(h, j - i);
			for(k = 0; k + K <= j - i; k++){
				H = h[k + K - 1].x - h[k].x;
				ans = min(ans, W * H);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:60:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &K);
  ^
./Main.c:63:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &p[i].x, &p[i].y);
   ^